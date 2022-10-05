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
enum estados {Estado_1, Estado_2};
    enum estados LED_state;
    
   void go_to_state2(){
        if (botao_1_Read() == 1){
            LED_state = Estado_2;
            LED_Write(0);}   
}
   void go_to_state1(){
        if (botao_2_Read() == 0){
            LED_state = Estado_1;
            LED_Write(1);}   
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
        
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LED_Write(1);
    LED_state = Estado_1;
    for(;;)
   
    {
     switch(LED_state)
    {
        case Estado_1:
        go_to_state2();
        break;
         
        case Estado_2:
        go_to_state1();
        break;
    }

   
        
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
