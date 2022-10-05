/*******************************************************************************
* File Name: mld.h  
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

#if !defined(CY_PINS_mld_ALIASES_H) /* Pins mld_ALIASES_H */
#define CY_PINS_mld_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define mld_0			(mld__0__PC)
#define mld_0_PS		(mld__0__PS)
#define mld_0_PC		(mld__0__PC)
#define mld_0_DR		(mld__0__DR)
#define mld_0_SHIFT	(mld__0__SHIFT)
#define mld_0_INTR	((uint16)((uint16)0x0003u << (mld__0__SHIFT*2u)))

#define mld_INTR_ALL	 ((uint16)(mld_0_INTR))


#endif /* End Pins mld_ALIASES_H */


/* [] END OF FILE */
