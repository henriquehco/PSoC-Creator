/*******************************************************************************
* File Name: mle.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_mle_H) /* Pins mle_H */
#define CY_PINS_mle_H

#include "cytypes.h"
#include "cyfitter.h"
#include "mle_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} mle_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   mle_Read(void);
void    mle_Write(uint8 value);
uint8   mle_ReadDataReg(void);
#if defined(mle__PC) || (CY_PSOC4_4200L) 
    void    mle_SetDriveMode(uint8 mode);
#endif
void    mle_SetInterruptMode(uint16 position, uint16 mode);
uint8   mle_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void mle_Sleep(void); 
void mle_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(mle__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define mle_DRIVE_MODE_BITS        (3)
    #define mle_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - mle_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the mle_SetDriveMode() function.
         *  @{
         */
        #define mle_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define mle_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define mle_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define mle_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define mle_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define mle_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define mle_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define mle_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define mle_MASK               mle__MASK
#define mle_SHIFT              mle__SHIFT
#define mle_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in mle_SetInterruptMode() function.
     *  @{
     */
        #define mle_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define mle_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define mle_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define mle_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(mle__SIO)
    #define mle_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(mle__PC) && (CY_PSOC4_4200L)
    #define mle_USBIO_ENABLE               ((uint32)0x80000000u)
    #define mle_USBIO_DISABLE              ((uint32)(~mle_USBIO_ENABLE))
    #define mle_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define mle_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define mle_USBIO_ENTER_SLEEP          ((uint32)((1u << mle_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << mle_USBIO_SUSPEND_DEL_SHIFT)))
    #define mle_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << mle_USBIO_SUSPEND_SHIFT)))
    #define mle_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << mle_USBIO_SUSPEND_DEL_SHIFT)))
    #define mle_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(mle__PC)
    /* Port Configuration */
    #define mle_PC                 (* (reg32 *) mle__PC)
#endif
/* Pin State */
#define mle_PS                     (* (reg32 *) mle__PS)
/* Data Register */
#define mle_DR                     (* (reg32 *) mle__DR)
/* Input Buffer Disable Override */
#define mle_INP_DIS                (* (reg32 *) mle__PC2)

/* Interrupt configuration Registers */
#define mle_INTCFG                 (* (reg32 *) mle__INTCFG)
#define mle_INTSTAT                (* (reg32 *) mle__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define mle_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(mle__SIO)
    #define mle_SIO_REG            (* (reg32 *) mle__SIO)
#endif /* (mle__SIO_CFG) */

/* USBIO registers */
#if !defined(mle__PC) && (CY_PSOC4_4200L)
    #define mle_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define mle_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define mle_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define mle_DRIVE_MODE_SHIFT       (0x00u)
#define mle_DRIVE_MODE_MASK        (0x07u << mle_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins mle_H */


/* [] END OF FILE */
