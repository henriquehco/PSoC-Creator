/*******************************************************************************
* File Name: bd.h  
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

#if !defined(CY_PINS_bd_ALIASES_H) /* Pins bd_ALIASES_H */
#define CY_PINS_bd_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define bd_0			(bd__0__PC)
#define bd_0_PS		(bd__0__PS)
#define bd_0_PC		(bd__0__PC)
#define bd_0_DR		(bd__0__DR)
#define bd_0_SHIFT	(bd__0__SHIFT)
#define bd_0_INTR	((uint16)((uint16)0x0003u << (bd__0__SHIFT*2u)))

#define bd_INTR_ALL	 ((uint16)(bd_0_INTR))


#endif /* End Pins bd_ALIASES_H */


/* [] END OF FILE */
