/*******************************************************************************
* File Name: antihorario.h  
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

#if !defined(CY_PINS_antihorario_H) /* Pins antihorario_H */
#define CY_PINS_antihorario_H

#include "cytypes.h"
#include "cyfitter.h"
#include "antihorario_aliases.h"


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
} antihorario_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   antihorario_Read(void);
void    antihorario_Write(uint8 value);
uint8   antihorario_ReadDataReg(void);
#if defined(antihorario__PC) || (CY_PSOC4_4200L) 
    void    antihorario_SetDriveMode(uint8 mode);
#endif
void    antihorario_SetInterruptMode(uint16 position, uint16 mode);
uint8   antihorario_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void antihorario_Sleep(void); 
void antihorario_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(antihorario__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define antihorario_DRIVE_MODE_BITS        (3)
    #define antihorario_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - antihorario_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the antihorario_SetDriveMode() function.
         *  @{
         */
        #define antihorario_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define antihorario_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define antihorario_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define antihorario_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define antihorario_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define antihorario_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define antihorario_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define antihorario_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define antihorario_MASK               antihorario__MASK
#define antihorario_SHIFT              antihorario__SHIFT
#define antihorario_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in antihorario_SetInterruptMode() function.
     *  @{
     */
        #define antihorario_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define antihorario_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define antihorario_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define antihorario_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(antihorario__SIO)
    #define antihorario_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(antihorario__PC) && (CY_PSOC4_4200L)
    #define antihorario_USBIO_ENABLE               ((uint32)0x80000000u)
    #define antihorario_USBIO_DISABLE              ((uint32)(~antihorario_USBIO_ENABLE))
    #define antihorario_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define antihorario_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define antihorario_USBIO_ENTER_SLEEP          ((uint32)((1u << antihorario_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << antihorario_USBIO_SUSPEND_DEL_SHIFT)))
    #define antihorario_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << antihorario_USBIO_SUSPEND_SHIFT)))
    #define antihorario_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << antihorario_USBIO_SUSPEND_DEL_SHIFT)))
    #define antihorario_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(antihorario__PC)
    /* Port Configuration */
    #define antihorario_PC                 (* (reg32 *) antihorario__PC)
#endif
/* Pin State */
#define antihorario_PS                     (* (reg32 *) antihorario__PS)
/* Data Register */
#define antihorario_DR                     (* (reg32 *) antihorario__DR)
/* Input Buffer Disable Override */
#define antihorario_INP_DIS                (* (reg32 *) antihorario__PC2)

/* Interrupt configuration Registers */
#define antihorario_INTCFG                 (* (reg32 *) antihorario__INTCFG)
#define antihorario_INTSTAT                (* (reg32 *) antihorario__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define antihorario_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(antihorario__SIO)
    #define antihorario_SIO_REG            (* (reg32 *) antihorario__SIO)
#endif /* (antihorario__SIO_CFG) */

/* USBIO registers */
#if !defined(antihorario__PC) && (CY_PSOC4_4200L)
    #define antihorario_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define antihorario_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define antihorario_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define antihorario_DRIVE_MODE_SHIFT       (0x00u)
#define antihorario_DRIVE_MODE_MASK        (0x07u << antihorario_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins antihorario_H */


/* [] END OF FILE */
