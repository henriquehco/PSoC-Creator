/*******************************************************************************
* File Name: mld.h  
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

#if !defined(CY_PINS_mld_H) /* Pins mld_H */
#define CY_PINS_mld_H

#include "cytypes.h"
#include "cyfitter.h"
#include "mld_aliases.h"


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
} mld_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   mld_Read(void);
void    mld_Write(uint8 value);
uint8   mld_ReadDataReg(void);
#if defined(mld__PC) || (CY_PSOC4_4200L) 
    void    mld_SetDriveMode(uint8 mode);
#endif
void    mld_SetInterruptMode(uint16 position, uint16 mode);
uint8   mld_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void mld_Sleep(void); 
void mld_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(mld__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define mld_DRIVE_MODE_BITS        (3)
    #define mld_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - mld_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the mld_SetDriveMode() function.
         *  @{
         */
        #define mld_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define mld_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define mld_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define mld_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define mld_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define mld_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define mld_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define mld_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define mld_MASK               mld__MASK
#define mld_SHIFT              mld__SHIFT
#define mld_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in mld_SetInterruptMode() function.
     *  @{
     */
        #define mld_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define mld_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define mld_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define mld_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(mld__SIO)
    #define mld_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(mld__PC) && (CY_PSOC4_4200L)
    #define mld_USBIO_ENABLE               ((uint32)0x80000000u)
    #define mld_USBIO_DISABLE              ((uint32)(~mld_USBIO_ENABLE))
    #define mld_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define mld_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define mld_USBIO_ENTER_SLEEP          ((uint32)((1u << mld_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << mld_USBIO_SUSPEND_DEL_SHIFT)))
    #define mld_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << mld_USBIO_SUSPEND_SHIFT)))
    #define mld_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << mld_USBIO_SUSPEND_DEL_SHIFT)))
    #define mld_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(mld__PC)
    /* Port Configuration */
    #define mld_PC                 (* (reg32 *) mld__PC)
#endif
/* Pin State */
#define mld_PS                     (* (reg32 *) mld__PS)
/* Data Register */
#define mld_DR                     (* (reg32 *) mld__DR)
/* Input Buffer Disable Override */
#define mld_INP_DIS                (* (reg32 *) mld__PC2)

/* Interrupt configuration Registers */
#define mld_INTCFG                 (* (reg32 *) mld__INTCFG)
#define mld_INTSTAT                (* (reg32 *) mld__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define mld_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(mld__SIO)
    #define mld_SIO_REG            (* (reg32 *) mld__SIO)
#endif /* (mld__SIO_CFG) */

/* USBIO registers */
#if !defined(mld__PC) && (CY_PSOC4_4200L)
    #define mld_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define mld_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define mld_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define mld_DRIVE_MODE_SHIFT       (0x00u)
#define mld_DRIVE_MODE_MASK        (0x07u << mld_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins mld_H */


/* [] END OF FILE */
