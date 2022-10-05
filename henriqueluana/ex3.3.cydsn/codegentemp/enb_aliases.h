/*******************************************************************************
* File Name: enb.h  
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

#if !defined(CY_PINS_enb_ALIASES_H) /* Pins enb_ALIASES_H */
#define CY_PINS_enb_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define enb_0			(enb__0__PC)
#define enb_0_PS		(enb__0__PS)
#define enb_0_PC		(enb__0__PC)
#define enb_0_DR		(enb__0__DR)
#define enb_0_SHIFT	(enb__0__SHIFT)
#define enb_0_INTR	((uint16)((uint16)0x0003u << (enb__0__SHIFT*2u)))

#define enb_INTR_ALL	 ((uint16)(enb_0_INTR))


#endif /* End Pins enb_ALIASES_H */


/* [] END OF FILE */
