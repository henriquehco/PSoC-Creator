/*******************************************************************************
* File Name: in4.c  
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
#include "in4.h"

static in4_BACKUP_STRUCT  in4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: in4_Sleep
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
*  \snippet in4_SUT.c usage_in4_Sleep_Wakeup
*******************************************************************************/
void in4_Sleep(void)
{
    #if defined(in4__PC)
        in4_backup.pcState = in4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            in4_backup.usbState = in4_CR1_REG;
            in4_USB_POWER_REG |= in4_USBIO_ENTER_SLEEP;
            in4_CR1_REG &= in4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(in4__SIO)
        in4_backup.sioState = in4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        in4_SIO_REG &= (uint32)(~in4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: in4_Wakeup
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
*  Refer to in4_Sleep() for an example usage.
*******************************************************************************/
void in4_Wakeup(void)
{
    #if defined(in4__PC)
        in4_PC = in4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            in4_USB_POWER_REG &= in4_USBIO_EXIT_SLEEP_PH1;
            in4_CR1_REG = in4_backup.usbState;
            in4_USB_POWER_REG &= in4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(in4__SIO)
        in4_SIO_REG = in4_backup.sioState;
    #endif
}


/* [] END OF FILE */
