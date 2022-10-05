/*******************************************************************************
* File Name: ena.h  
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

#if !defined(CY_PINS_ena_ALIASES_H) /* Pins ena_ALIASES_H */
#define CY_PINS_ena_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ena_0			(ena__0__PC)
#define ena_0_PS		(ena__0__PS)
#define ena_0_PC		(ena__0__PC)
#define ena_0_DR		(ena__0__DR)
#define ena_0_SHIFT	(ena__0__SHIFT)
#define ena_0_INTR	((uint16)((uint16)0x0003u << (ena__0__SHIFT*2u)))

#define ena_INTR_ALL	 ((uint16)(ena_0_INTR))


#endif /* End Pins ena_ALIASES_H */


/* [] END OF FILE */
