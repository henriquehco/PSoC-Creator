/*******************************************************************************
* File Name: b1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_b1_ALIASES_H) /* Pins b1_ALIASES_H */
#define CY_PINS_b1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define b1_0			(b1__0__PC)
#define b1_0_PS		(b1__0__PS)
#define b1_0_PC		(b1__0__PC)
#define b1_0_DR		(b1__0__DR)
#define b1_0_SHIFT	(b1__0__SHIFT)
#define b1_0_INTR	((uint16)((uint16)0x0003u << (b1__0__SHIFT*2u)))

#define b1_INTR_ALL	 ((uint16)(b1_0_INTR))


#endif /* End Pins b1_ALIASES_H */


/* [] END OF FILE */
