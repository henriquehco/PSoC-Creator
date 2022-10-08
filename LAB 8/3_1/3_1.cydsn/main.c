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

CY_ISR (MY_ISR_TIMER)
{
   
   LED_Write( ~LED_Read() );
   
   Timer_2_ReadStatusRegister();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    ISR_StartEx(Pin_SW2_Handler);
    Timer_2_Start ();
    ISR_TIMER_StartEx(MY_ISR_TIMER);

    for(;;)
    {

    }
}

/* [] END OF FILE */
