/*******************************************************************************
* File Name: md.h  
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

#if !defined(CY_PINS_md_ALIASES_H) /* Pins md_ALIASES_H */
#define CY_PINS_md_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define md_0			(md__0__PC)
#define md_0_PS		(md__0__PS)
#define md_0_PC		(md__0__PC)
#define md_0_DR		(md__0__DR)
#define md_0_SHIFT	(md__0__SHIFT)
#define md_0_INTR	((uint16)((uint16)0x0003u << (md__0__SHIFT*2u)))

#define md_INTR_ALL	 ((uint16)(md_0_INTR))


#endif /* End Pins md_ALIASES_H */


/* [] END OF FILE */
