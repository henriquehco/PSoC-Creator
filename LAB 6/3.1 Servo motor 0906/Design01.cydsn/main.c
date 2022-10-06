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
    int P;
    P = 1500;
    for(;;)
    {

        
        if ((Pin_DIM_Read()==1) && (P>1000)){ 
        P-=200;
            }
        if ((Pin_AUM_Read()==0 ) &&( P<2000)) {
        P+=200;
        }
        
        pino_saida_Write(1);
        CyDelayUs(P);                                                                                                                                                           
        pino_saida_Write(0);
        CyDelayUs(20000-P);

}}

/* [] END OF FILE */
