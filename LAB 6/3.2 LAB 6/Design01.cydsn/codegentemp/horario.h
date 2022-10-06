/*******************************************************************************
* File Name: horario.h  
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

#if !defined(CY_PINS_horario_H) /* Pins horario_H */
#define CY_PINS_horario_H

#include "cytypes.h"
#include "cyfitter.h"
#include "horario_aliases.h"


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
} horario_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   horario_Read(void);
void    horario_Write(uint8 value);
uint8   horario_ReadDataReg(void);
#if defined(horario__PC) || (CY_PSOC4_4200L) 
    void    horario_SetDriveMode(uint8 mode);
#endif
void    horario_SetInterruptMode(uint16 position, uint16 mode);
uint8   horario_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void horario_Sleep(void); 
void horario_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(horario__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define horario_DRIVE_MODE_BITS        (3)
    #define horario_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - horario_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the horario_SetDriveMode() function.
         *  @{
         */
        #define horario_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define horario_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define horario_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define horario_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define horario_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define horario_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define horario_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define horario_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define horario_MASK               horario__MASK
#define horario_SHIFT              horario__SHIFT
#define horario_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in horario_SetInterruptMode() function.
     *  @{
     */
        #define horario_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define horario_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define horario_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define horario_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(horario__SIO)
    #define horario_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(horario__PC) && (CY_PSOC4_4200L)
    #define horario_USBIO_ENABLE               ((uint32)0x80000000u)
    #define horario_USBIO_DISABLE              ((uint32)(~horario_USBIO_ENABLE))
    #define horario_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define horario_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define horario_USBIO_ENTER_SLEEP          ((uint32)((1u << horario_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << horario_USBIO_SUSPEND_DEL_SHIFT)))
    #define horario_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << horario_USBIO_SUSPEND_SHIFT)))
    #define horario_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << horario_USBIO_SUSPEND_DEL_SHIFT)))
    #define horario_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(horario__PC)
    /* Port Configuration */
    #define horario_PC                 (* (reg32 *) horario__PC)
#endif
/* Pin State */
#define horario_PS                     (* (reg32 *) horario__PS)
/* Data Register */
#define horario_DR                     (* (reg32 *) horario__DR)
/* Input Buffer Disable Override */
#define horario_INP_DIS                (* (reg32 *) horario__PC2)

/* Interrupt configuration Registers */
#define horario_INTCFG                 (* (reg32 *) horario__INTCFG)
#define horario_INTSTAT                (* (reg32 *) horario__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define horario_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(horario__SIO)
    #define horario_SIO_REG            (* (reg32 *) horario__SIO)
#endif /* (horario__SIO_CFG) */

/* USBIO registers */
#if !defined(horario__PC) && (CY_PSOC4_4200L)
    #define horario_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define horario_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define horario_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define horario_DRIVE_MODE_SHIFT       (0x00u)
#define horario_DRIVE_MODE_MASK        (0x07u << horario_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins horario_H */


/* [] END OF FILE */
