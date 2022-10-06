/*******************************************************************************
* File Name: pino_saida.h  
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

#if !defined(CY_PINS_pino_saida_H) /* Pins pino_saida_H */
#define CY_PINS_pino_saida_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pino_saida_aliases.h"


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
} pino_saida_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pino_saida_Read(void);
void    pino_saida_Write(uint8 value);
uint8   pino_saida_ReadDataReg(void);
#if defined(pino_saida__PC) || (CY_PSOC4_4200L) 
    void    pino_saida_SetDriveMode(uint8 mode);
#endif
void    pino_saida_SetInterruptMode(uint16 position, uint16 mode);
uint8   pino_saida_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pino_saida_Sleep(void); 
void pino_saida_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pino_saida__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pino_saida_DRIVE_MODE_BITS        (3)
    #define pino_saida_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pino_saida_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pino_saida_SetDriveMode() function.
         *  @{
         */
        #define pino_saida_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pino_saida_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pino_saida_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pino_saida_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pino_saida_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pino_saida_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pino_saida_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pino_saida_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pino_saida_MASK               pino_saida__MASK
#define pino_saida_SHIFT              pino_saida__SHIFT
#define pino_saida_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pino_saida_SetInterruptMode() function.
     *  @{
     */
        #define pino_saida_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pino_saida_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pino_saida_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pino_saida_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pino_saida__SIO)
    #define pino_saida_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pino_saida__PC) && (CY_PSOC4_4200L)
    #define pino_saida_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pino_saida_USBIO_DISABLE              ((uint32)(~pino_saida_USBIO_ENABLE))
    #define pino_saida_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pino_saida_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pino_saida_USBIO_ENTER_SLEEP          ((uint32)((1u << pino_saida_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pino_saida_USBIO_SUSPEND_DEL_SHIFT)))
    #define pino_saida_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pino_saida_USBIO_SUSPEND_SHIFT)))
    #define pino_saida_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pino_saida_USBIO_SUSPEND_DEL_SHIFT)))
    #define pino_saida_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pino_saida__PC)
    /* Port Configuration */
    #define pino_saida_PC                 (* (reg32 *) pino_saida__PC)
#endif
/* Pin State */
#define pino_saida_PS                     (* (reg32 *) pino_saida__PS)
/* Data Register */
#define pino_saida_DR                     (* (reg32 *) pino_saida__DR)
/* Input Buffer Disable Override */
#define pino_saida_INP_DIS                (* (reg32 *) pino_saida__PC2)

/* Interrupt configuration Registers */
#define pino_saida_INTCFG                 (* (reg32 *) pino_saida__INTCFG)
#define pino_saida_INTSTAT                (* (reg32 *) pino_saida__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pino_saida_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pino_saida__SIO)
    #define pino_saida_SIO_REG            (* (reg32 *) pino_saida__SIO)
#endif /* (pino_saida__SIO_CFG) */

/* USBIO registers */
#if !defined(pino_saida__PC) && (CY_PSOC4_4200L)
    #define pino_saida_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pino_saida_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pino_saida_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pino_saida_DRIVE_MODE_SHIFT       (0x00u)
#define pino_saida_DRIVE_MODE_MASK        (0x07u << pino_saida_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pino_saida_H */


/* [] END OF FILE */
