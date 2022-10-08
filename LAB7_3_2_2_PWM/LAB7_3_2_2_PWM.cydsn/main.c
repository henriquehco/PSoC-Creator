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
enum estados {ESTADO_20 = 1, ESTADO_40,ESTADO_60,ESTADO_70,ESTADO_80,ESTADO_100};
enum estados led_state;

   void go_to_state20(){
       // if (BT_Read() == 0){
            led_state = ESTADO_40;
            PWM_1_WriteCompare (2000);

       // }
}
   void go_to_state40(){
       // if (BT_Read() == 0){
            led_state = ESTADO_60;
            PWM_1_WriteCompare (4000);

       // }
}
   void go_to_state60(){
      //  if (BT_Read() == 0){
            led_state = ESTADO_70;
            PWM_1_WriteCompare (6000);

       // }
}
   void go_to_state70(){
        if (BT_Read() == 0){
            led_state = ESTADO_80;
            PWM_1_WriteCompare (7000);

        }
}
   void go_to_state80(){
        if (BT_Read() == 0){
            led_state = ESTADO_100;
            PWM_1_WriteCompare (8000);

        }
}   void go_to_state100(){
        if (BT_Read() == 0){
            led_state = ESTADO_20;
            PWM_1_WriteCompare (10000);

        }
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();
    Clock_Start();
    led_state = 1;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
    if (BT_Read() == 0){
        CyDelay(100);
        switch(led_state){
        
        case ESTADO_20:
        go_to_state20();
        break;
         
        case ESTADO_40:
        go_to_state40();
        break;
        
        case ESTADO_60:
        go_to_state60();
        break;
         
        case ESTADO_70:
        go_to_state70();
        break;
        
        case ESTADO_80:
        go_to_state80();
        break;
        
        case ESTADO_100:
        go_to_state100();
        break;
        }
        }
    }
}

/* [] END OF FILE */
