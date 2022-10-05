/*******************************************************************************
* File Name: bd.h  
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

#if !defined(CY_PINS_bd_H) /* Pins bd_H */
#define CY_PINS_bd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "bd_aliases.h"


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
} bd_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   bd_Read(void);
void    bd_Write(uint8 value);
uint8   bd_ReadDataReg(void);
#if defined(bd__PC) || (CY_PSOC4_4200L) 
    void    bd_SetDriveMode(uint8 mode);
#endif
void    bd_SetInterruptMode(uint16 position, uint16 mode);
uint8   bd_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void bd_Sleep(void); 
void bd_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(bd__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define bd_DRIVE_MODE_BITS        (3)
    #define bd_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - bd_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the bd_SetDriveMode() function.
         *  @{
         */
        #define bd_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define bd_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define bd_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define bd_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define bd_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define bd_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define bd_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define bd_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define bd_MASK               bd__MASK
#define bd_SHIFT              bd__SHIFT
#define bd_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bd_SetInterruptMode() function.
     *  @{
     */
        #define bd_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define bd_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define bd_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define bd_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(bd__SIO)
    #define bd_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(bd__PC) && (CY_PSOC4_4200L)
    #define bd_USBIO_ENABLE               ((uint32)0x80000000u)
    #define bd_USBIO_DISABLE              ((uint32)(~bd_USBIO_ENABLE))
    #define bd_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define bd_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define bd_USBIO_ENTER_SLEEP          ((uint32)((1u << bd_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << bd_USBIO_SUSPEND_DEL_SHIFT)))
    #define bd_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << bd_USBIO_SUSPEND_SHIFT)))
    #define bd_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << bd_USBIO_SUSPEND_DEL_SHIFT)))
    #define bd_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(bd__PC)
    /* Port Configuration */
    #define bd_PC                 (* (reg32 *) bd__PC)
#endif
/* Pin State */
#define bd_PS                     (* (reg32 *) bd__PS)
/* Data Register */
#define bd_DR                     (* (reg32 *) bd__DR)
/* Input Buffer Disable Override */
#define bd_INP_DIS                (* (reg32 *) bd__PC2)

/* Interrupt configuration Registers */
#define bd_INTCFG                 (* (reg32 *) bd__INTCFG)
#define bd_INTSTAT                (* (reg32 *) bd__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define bd_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(bd__SIO)
    #define bd_SIO_REG            (* (reg32 *) bd__SIO)
#endif /* (bd__SIO_CFG) */

/* USBIO registers */
#if !defined(bd__PC) && (CY_PSOC4_4200L)
    #define bd_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define bd_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define bd_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define bd_DRIVE_MODE_SHIFT       (0x00u)
#define bd_DRIVE_MODE_MASK        (0x07u << bd_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins bd_H */


/* [] END OF FILE */
