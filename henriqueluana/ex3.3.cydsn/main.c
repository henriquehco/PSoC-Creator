/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ==============================================
*/
#include "project.h"
enum estados {Estado_1, Estado_2, Estado_3, Estado_4};
enum estados M_state;
    


   void go_to_state1(){
        if (be_Read() == 1 || bd_Read() == 0){
            M_state = Estado_1;
            in3_Write(0);
            in4_Write(0);
            in1_Write(1);
            in2_Write(0);

        }
}
        
   void go_to_state2(){
        if (be_Read() == 1 || bd_Read() == 0){
            M_state = Estado_2;
            in1_Write(0);
            in2_Write(1);
            in3_Write(0);
            in4_Write(0);
            
        }   
}

  
     void go_to_state3(){
        if (be_Read() == 1 || bd_Read() == 0){
            M_state = Estado_3;
            in1_Write(0);
            in2_Write(0);
            in3_Write(1);
            in4_Write(0);
            
        }   
}
   void go_to_state4(){
        if (be_Read() == 1 || bd_Read() == 0){
            M_state = Estado_4;
            in3_Write(0);
            in4_Write(1);
            in1_Write(0);
            in2_Write(0);

        }   
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ena_Write(1);
    enb_Write(1);
        
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    M_state = Estado_1;
    for(;;)
   
    {
        
      switch(M_state){
        
        case Estado_1:
        if (be_Read() == 1){
        go_to_state2();
        }
        else if (bd_Read() == 1){
        go_to_state4();
        }
        break;
         
        case Estado_2:
        if (be_Read() == 1){
        go_to_state3();
        }
        else if (bd_Read() == 1){
        go_to_state1();
        }       
        break;
        
        case Estado_3:
        else if (be_Read() == 1){
        go_to_state4();
        }
        else else if (bd_Read() == 1){
        go_to_state2();
        }
        break;
         
        case Estado_4:
        else if (be_Read() == 1){
        go_to_state1();
        }
        else if (bd_Read() == 1){
        go_to_state3();
        }
        break;
     }
        }
  

   CyDelay(200);
        
        
        /* Place your application code here. */
    
    }
}
/* [] END OF FILE */
