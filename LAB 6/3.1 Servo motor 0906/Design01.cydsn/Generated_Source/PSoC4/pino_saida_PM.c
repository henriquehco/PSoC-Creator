/*******************************************************************************
* File Name: pino_saida.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "pino_saida.h"

static pino_saida_BACKUP_STRUCT  pino_saida_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: pino_saida_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet pino_saida_SUT.c usage_pino_saida_Sleep_Wakeup
*******************************************************************************/
void pino_saida_Sleep(void)
{
    #if defined(pino_saida__PC)
        pino_saida_backup.pcState = pino_saida_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            pino_saida_backup.usbState = pino_saida_CR1_REG;
            pino_saida_USB_POWER_REG |= pino_saida_USBIO_ENTER_SLEEP;
            pino_saida_CR1_REG &= pino_saida_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pino_saida__SIO)
        pino_saida_backup.sioState = pino_saida_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        pino_saida_SIO_REG &= (uint32)(~pino_saida_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: pino_saida_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to pino_saida_Sleep() for an example usage.
*******************************************************************************/
void pino_saida_Wakeup(void)
{
    #if defined(pino_saida__PC)
        pino_saida_PC = pino_saida_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            pino_saida_USB_POWER_REG &= pino_saida_USBIO_EXIT_SLEEP_PH1;
            pino_saida_CR1_REG = pino_saida_backup.usbState;
            pino_saida_USB_POWER_REG &= pino_saida_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pino_saida__SIO)
        pino_saida_SIO_REG = pino_saida_backup.sioState;
    #endif
}


/* [] END OF FILE */
