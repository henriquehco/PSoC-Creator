/*******************************************************************************
* File Name: Desliga_Liga.c  
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
#include "Desliga_Liga.h"

static Desliga_Liga_BACKUP_STRUCT  Desliga_Liga_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Desliga_Liga_Sleep
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
*  \snippet Desliga_Liga_SUT.c usage_Desliga_Liga_Sleep_Wakeup
*******************************************************************************/
void Desliga_Liga_Sleep(void)
{
    #if defined(Desliga_Liga__PC)
        Desliga_Liga_backup.pcState = Desliga_Liga_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Desliga_Liga_backup.usbState = Desliga_Liga_CR1_REG;
            Desliga_Liga_USB_POWER_REG |= Desliga_Liga_USBIO_ENTER_SLEEP;
            Desliga_Liga_CR1_REG &= Desliga_Liga_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Desliga_Liga__SIO)
        Desliga_Liga_backup.sioState = Desliga_Liga_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Desliga_Liga_SIO_REG &= (uint32)(~Desliga_Liga_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Desliga_Liga_Wakeup
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
*  Refer to Desliga_Liga_Sleep() for an example usage.
*******************************************************************************/
void Desliga_Liga_Wakeup(void)
{
    #if defined(Desliga_Liga__PC)
        Desliga_Liga_PC = Desliga_Liga_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Desliga_Liga_USB_POWER_REG &= Desliga_Liga_USBIO_EXIT_SLEEP_PH1;
            Desliga_Liga_CR1_REG = Desliga_Liga_backup.usbState;
            Desliga_Liga_USB_POWER_REG &= Desliga_Liga_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Desliga_Liga__SIO)
        Desliga_Liga_SIO_REG = Desliga_Liga_backup.sioState;
    #endif
}


/* [] END OF FILE */
