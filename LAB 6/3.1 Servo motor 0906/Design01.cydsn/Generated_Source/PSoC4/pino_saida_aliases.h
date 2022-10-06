/*******************************************************************************
* File Name: pino_saida.h  
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

#if !defined(CY_PINS_pino_saida_ALIASES_H) /* Pins pino_saida_ALIASES_H */
#define CY_PINS_pino_saida_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pino_saida_0			(pino_saida__0__PC)
#define pino_saida_0_PS		(pino_saida__0__PS)
#define pino_saida_0_PC		(pino_saida__0__PC)
#define pino_saida_0_DR		(pino_saida__0__DR)
#define pino_saida_0_SHIFT	(pino_saida__0__SHIFT)
#define pino_saida_0_INTR	((uint16)((uint16)0x0003u << (pino_saida__0__SHIFT*2u)))

#define pino_saida_INTR_ALL	 ((uint16)(pino_saida_0_INTR))


#endif /* End Pins pino_saida_ALIASES_H */


/* [] END OF FILE */
