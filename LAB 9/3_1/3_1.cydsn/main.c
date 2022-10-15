/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    int16 result1 = 0;
    float res1_volts = 0;
    char str_out[50];

    ADC_Start();
    ADC_StartConvert();
    UART_Start();
    
    
    for(;;)
    {
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT );
        result1 = ADC_GetResult16(0); // le resultado do canal 0
        res1_volts = ADC_CountsTo_Volts(0,result1); // converte o resultado para volts
        int result10 = res1_volts*1000;
        sprintf(str_out, "Digital=%d Volts = %d \n\r",result1,result10);
        UART_PutString(str_out);
        CyDelay(50);

    }
}

/* [] END OF FILE */
