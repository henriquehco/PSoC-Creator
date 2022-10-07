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

CY_ISR (Pin_SW2_Handler)
{
   LED_Write( ~LED_Read() );
   
   Pin_SW2_ClearInterrupt ();
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    ISR_StartEx(Pin_SW2_Handler);
    //Pin_SW2_int_StartEx (Pin_SW2_Handler);

    for(;;)
    {

    }
}

/* [] END OF FILE */
