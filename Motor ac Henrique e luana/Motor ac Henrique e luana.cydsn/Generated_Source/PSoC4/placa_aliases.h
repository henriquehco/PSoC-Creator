/*******************************************************************************
* File Name: placa.h  
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

#if !defined(CY_PINS_placa_ALIASES_H) /* Pins placa_ALIASES_H */
#define CY_PINS_placa_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define placa_0			(placa__0__PC)
#define placa_0_PS		(placa__0__PS)
#define placa_0_PC		(placa__0__PC)
#define placa_0_DR		(placa__0__DR)
#define placa_0_SHIFT	(placa__0__SHIFT)
#define placa_0_INTR	((uint16)((uint16)0x0003u << (placa__0__SHIFT*2u)))

#define placa_INTR_ALL	 ((uint16)(placa_0_INTR))


#endif /* End Pins placa_ALIASES_H */


/* [] END OF FILE */
