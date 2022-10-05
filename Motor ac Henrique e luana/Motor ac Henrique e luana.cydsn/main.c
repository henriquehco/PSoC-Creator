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

        b2 = b2_Read();
        b1 = b1_Read();
        
        if (b2 == 1) {
            mle_Write(0);
            mld_Write(1);  
        }
        
        if (b1 == 1) {
            mle_Write(1);
            mld_Write(0);
    }
}

/* [] END OF FILE */
