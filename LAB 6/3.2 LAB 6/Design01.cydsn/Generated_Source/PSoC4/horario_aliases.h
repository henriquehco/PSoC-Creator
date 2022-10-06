/*******************************************************************************
* File Name: horario.h  
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

#if !defined(CY_PINS_horario_ALIASES_H) /* Pins horario_ALIASES_H */
#define CY_PINS_horario_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define horario_0			(horario__0__PC)
#define horario_0_PS		(horario__0__PS)
#define horario_0_PC		(horario__0__PC)
#define horario_0_DR		(horario__0__DR)
#define horario_0_SHIFT	(horario__0__SHIFT)
#define horario_0_INTR	((uint16)((uint16)0x0003u << (horario__0__SHIFT*2u)))

#define horario_INTR_ALL	 ((uint16)(horario_0_INTR))


#endif /* End Pins horario_ALIASES_H */


/* [] END OF FILE */
