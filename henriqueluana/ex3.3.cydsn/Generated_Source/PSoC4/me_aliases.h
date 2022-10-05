/*******************************************************************************
* File Name: me.h  
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

#if !defined(CY_PINS_me_ALIASES_H) /* Pins me_ALIASES_H */
#define CY_PINS_me_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define me_0			(me__0__PC)
#define me_0_PS		(me__0__PS)
#define me_0_PC		(me__0__PC)
#define me_0_DR		(me__0__DR)
#define me_0_SHIFT	(me__0__SHIFT)
#define me_0_INTR	((uint16)((uint16)0x0003u << (me__0__SHIFT*2u)))

#define me_INTR_ALL	 ((uint16)(me_0_INTR))


#endif /* End Pins me_ALIASES_H */


/* [] END OF FILE */
