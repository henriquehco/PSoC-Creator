/*******************************************************************************
* File Name: enb.h  
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

#if !defined(CY_PINS_enb_H) /* Pins enb_H */
#define CY_PINS_enb_H

#include "cytypes.h"
#include "cyfitter.h"
#include "enb_aliases.h"


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
} enb_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   enb_Read(void);
void    enb_Write(uint8 value);
uint8   enb_ReadDataReg(void);
#if defined(enb__PC) || (CY_PSOC4_4200L) 
    void    enb_SetDriveMode(uint8 mode);
#endif
void    enb_SetInterruptMode(uint16 position, uint16 mode);
uint8   enb_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void enb_Sleep(void); 
void enb_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(enb__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define enb_DRIVE_MODE_BITS        (3)
    #define enb_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - enb_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the enb_SetDriveMode() function.
         *  @{
         */
        #define enb_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define enb_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define enb_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define enb_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define enb_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define enb_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define enb_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define enb_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define enb_MASK               enb__MASK
#define enb_SHIFT              enb__SHIFT
#define enb_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in enb_SetInterruptMode() function.
     *  @{
     */
        #define enb_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define enb_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define enb_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define enb_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(enb__SIO)
    #define enb_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(enb__PC) && (CY_PSOC4_4200L)
    #define enb_USBIO_ENABLE               ((uint32)0x80000000u)
    #define enb_USBIO_DISABLE              ((uint32)(~enb_USBIO_ENABLE))
    #define enb_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define enb_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define enb_USBIO_ENTER_SLEEP          ((uint32)((1u << enb_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << enb_USBIO_SUSPEND_DEL_SHIFT)))
    #define enb_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << enb_USBIO_SUSPEND_SHIFT)))
    #define enb_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << enb_USBIO_SUSPEND_DEL_SHIFT)))
    #define enb_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(enb__PC)
    /* Port Configuration */
    #define enb_PC                 (* (reg32 *) enb__PC)
#endif
/* Pin State */
#define enb_PS                     (* (reg32 *) enb__PS)
/* Data Register */
#define enb_DR                     (* (reg32 *) enb__DR)
/* Input Buffer Disable Override */
#define enb_INP_DIS                (* (reg32 *) enb__PC2)

/* Interrupt configuration Registers */
#define enb_INTCFG                 (* (reg32 *) enb__INTCFG)
#define enb_INTSTAT                (* (reg32 *) enb__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define enb_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(enb__SIO)
    #define enb_SIO_REG            (* (reg32 *) enb__SIO)
#endif /* (enb__SIO_CFG) */

/* USBIO registers */
#if !defined(enb__PC) && (CY_PSOC4_4200L)
    #define enb_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define enb_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define enb_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define enb_DRIVE_MODE_SHIFT       (0x00u)
#define enb_DRIVE_MODE_MASK        (0x07u << enb_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins enb_H */


/* [] END OF FILE */
