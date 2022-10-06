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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
  
    for(;;)
   
    {
        /* Place your application code here. */
        
        
        CyDelay(200);
        
        if (Desliga_Liga_Read() == 0){
            
           ENABLE_Write(0);}
        
        else if(Desliga_Liga_Read() == 1) {
            
              ENABLE_Write(1);}
        
        if (horario_Read()==0){
            IN1_Write(1);
            IN2_Write(0);
        }
        
        if (antihorario_Read() == 1) {
            
            IN1_Write(0);
            IN2_Write(1);
            
             
        }
        
    }
    }


/* [] END OF FILE */
