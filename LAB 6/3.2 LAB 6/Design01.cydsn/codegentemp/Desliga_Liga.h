/*******************************************************************************
* File Name: Desliga_Liga.h  
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

#if !defined(CY_PINS_Desliga_Liga_H) /* Pins Desliga_Liga_H */
#define CY_PINS_Desliga_Liga_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Desliga_Liga_aliases.h"


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
} Desliga_Liga_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Desliga_Liga_Read(void);
void    Desliga_Liga_Write(uint8 value);
uint8   Desliga_Liga_ReadDataReg(void);
#if defined(Desliga_Liga__PC) || (CY_PSOC4_4200L) 
    void    Desliga_Liga_SetDriveMode(uint8 mode);
#endif
void    Desliga_Liga_SetInterruptMode(uint16 position, uint16 mode);
uint8   Desliga_Liga_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Desliga_Liga_Sleep(void); 
void Desliga_Liga_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Desliga_Liga__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Desliga_Liga_DRIVE_MODE_BITS        (3)
    #define Desliga_Liga_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Desliga_Liga_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Desliga_Liga_SetDriveMode() function.
         *  @{
         */
        #define Desliga_Liga_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Desliga_Liga_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Desliga_Liga_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Desliga_Liga_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Desliga_Liga_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Desliga_Liga_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Desliga_Liga_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Desliga_Liga_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Desliga_Liga_MASK               Desliga_Liga__MASK
#define Desliga_Liga_SHIFT              Desliga_Liga__SHIFT
#define Desliga_Liga_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Desliga_Liga_SetInterruptMode() function.
     *  @{
     */
        #define Desliga_Liga_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Desliga_Liga_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Desliga_Liga_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Desliga_Liga_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Desliga_Liga__SIO)
    #define Desliga_Liga_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Desliga_Liga__PC) && (CY_PSOC4_4200L)
    #define Desliga_Liga_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Desliga_Liga_USBIO_DISABLE              ((uint32)(~Desliga_Liga_USBIO_ENABLE))
    #define Desliga_Liga_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Desliga_Liga_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Desliga_Liga_USBIO_ENTER_SLEEP          ((uint32)((1u << Desliga_Liga_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Desliga_Liga_USBIO_SUSPEND_DEL_SHIFT)))
    #define Desliga_Liga_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Desliga_Liga_USBIO_SUSPEND_SHIFT)))
    #define Desliga_Liga_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Desliga_Liga_USBIO_SUSPEND_DEL_SHIFT)))
    #define Desliga_Liga_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Desliga_Liga__PC)
    /* Port Configuration */
    #define Desliga_Liga_PC                 (* (reg32 *) Desliga_Liga__PC)
#endif
/* Pin State */
#define Desliga_Liga_PS                     (* (reg32 *) Desliga_Liga__PS)
/* Data Register */
#define Desliga_Liga_DR                     (* (reg32 *) Desliga_Liga__DR)
/* Input Buffer Disable Override */
#define Desliga_Liga_INP_DIS                (* (reg32 *) Desliga_Liga__PC2)

/* Interrupt configuration Registers */
#define Desliga_Liga_INTCFG                 (* (reg32 *) Desliga_Liga__INTCFG)
#define Desliga_Liga_INTSTAT                (* (reg32 *) Desliga_Liga__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Desliga_Liga_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Desliga_Liga__SIO)
    #define Desliga_Liga_SIO_REG            (* (reg32 *) Desliga_Liga__SIO)
#endif /* (Desliga_Liga__SIO_CFG) */

/* USBIO registers */
#if !defined(Desliga_Liga__PC) && (CY_PSOC4_4200L)
    #define Desliga_Liga_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Desliga_Liga_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Desliga_Liga_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Desliga_Liga_DRIVE_MODE_SHIFT       (0x00u)
#define Desliga_Liga_DRIVE_MODE_MASK        (0x07u << Desliga_Liga_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Desliga_Liga_H */


/* [] END OF FILE */
