/* FreeEMS - the open source engine management system
 *
 * Copyright 2008-2012 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */


/** @file
 *
 * @ingroup dataInitialisers
 *
 * @brief Fuel VE and Lambda tables
 *
 * This file contains the definitions of the primary group VE and lambda
 * tables. The declaration can be found in the global constants header file.
 *
 * @note At least one Doxygen bug prevents the data structures below being show
 *       correctly in the documentation for this file. Please see the source
 *       code itself for more information.
 */


#include "../inc/freeEMS.h"


#ifndef VETableMainFlashV
#define VETableMainFlashV VETableMainFlash
#define VETableSecondaryFlashV VETableSecondaryFlash
#define VETableTertiaryFlashV VETableTertiaryFlash
#define LambdaTableFlashV LambdaTableFlash
#endif


const volatile mainTable VETableMainFlashV FUELTABLESD = {
#if CONFIG == DEFAULT_ID
	RPMLength:  MAINTABLE_RPM_LENGTH,
	LoadLength: MAINTABLE_LOAD_LENGTH,
#else
	RPMLength:  16,
	LoadLength: 16,
#endif
	RPM: {
#if CONFIG == TRUCK_ID
#include "../data/tables/axis/FredsTruck-RPM.h"
#elif CONFIG == PRESTO_ID
#include "../data/tables/axis/FredsTruck-RPM.h"
#elif CONFIG == SEANKLT1_ID
#include "../data/tables/axis/SeansLT1-RPM.h"
#elif SEANKR1 // No ID assigned yet!
#include "../data/tables/axis/FredsTruck-RPM.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/axis/Slater-RPM.h"
#elif CONFIG == DEUCECOUPE_ID
#include "../data/tables/axis/HotelHyundai-RPM.h"
#elif CONFIG == DEFAULT_ID
#include "../data/tables/axis/DefaultWith400Spacing-RPM.h"
#else
#include "../data/tables/axis/FredsTruck-RPM.h"
#endif
	},
	Load: {
#if CONFIG == TRUCK_ID
#include "../data/tables/axis/FredsTruck-Load.h"
#elif CONFIG == PRESTO_ID
#include "../data/tables/axis/FredsTruck-Load.h"
#elif CONFIG == SEANKLT1_ID
#include "../data/tables/axis/FredsTruck-Load.h"
#elif SEANKR1 // No ID assigned yet!
#include "../data/tables/axis/FredsTruck-Load.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/axis/Slater-Load.h"
#elif CONFIG == DEUCECOUPE_ID
#include "../data/tables/axis/HotelHyundai-Load.h"
#elif CONFIG == DEFAULT_ID
#include "../data/tables/axis/DefaultWith10and20SplitSpacing-Load.h"
#else
#include "../data/tables/axis/FredsTruck-Load.h"
#endif
	},
	Table: {
#if CONFIG == TRUCK_ID
#include "../data/tables/ve/FredsTruckVE.h"
#elif CONFIG == PRESTO_ID
#include "../data/tables/ve/flat60Percent.h"
#elif CONFIG == SEANKLT1_ID
#include "../data/tables/ve/SeansLT1VE.h"
#elif SEANKR1 // No ID assigned yet!
#include "../data/tables/ve/flat80Percent.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/ve/SlaterVE.h"
#elif CONFIG == DEUCECOUPE_ID
#include "../data/tables/ve/flat60Percent.h"
#elif CONFIG == DEFAULT_ID
#include "../data/tables/ve/DefaultVE24RPMx19Load.h"
#else
#include "../data/tables/ve/flat60Percent.h"
#endif
	}
};


const volatile mainTable VETableSecondaryFlashV FUELTABLESD = {
	RPMLength:  MAINTABLE_RPM_LENGTH,
	LoadLength: MAINTABLE_LOAD_LENGTH,
	RPM:{
		#include "../data/tables/axis/DefaultWith400Spacing-RPM.h"
	},
	Load:{
		#include "../data/tables/axis/DefaultWith10and20SplitSpacing-Load.h"
	},
	Table:{
		#include "../data/tables/ve/DefaultVE24RPMx19Load.h"
	}
};


const volatile mainTable VETableTertiaryFlashV FUELTABLESD = {
	RPMLength:  MAINTABLE_RPM_LENGTH,
	LoadLength: MAINTABLE_LOAD_LENGTH,
	RPM:{
		#include "../data/tables/axis/DefaultWith400Spacing-RPM.h"
	},
	Load:{
		#include "../data/tables/axis/DefaultWith10and20SplitSpacing-Load.h"
	},
	Table:{
		#include "../data/tables/ve/DefaultVE24RPMx19Load.h"
	}
};


const volatile mainTable LambdaTableFlashV FUELTABLESD = {
#if CONFIG == DEFAULT_ID
	RPMLength:  MAINTABLE_RPM_LENGTH,
	LoadLength: MAINTABLE_LOAD_LENGTH,
#else
	RPMLength:  16,
	LoadLength: 16,
#endif
	RPM: {
#if CONFIG == SEANKLT1_ID
#include "../data/tables/axis/SeansLT1-RPM.h"
#elif CONFIG == DEFAULT_ID
#include "../data/tables/axis/DefaultWith400Spacing-RPM.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/axis/Slater-RPM.h"
#else
#include "../data/tables/axis/FredsTruck-RPM.h"
#endif
	},
	Load: {
#if CONFIG == DEFAULT_ID
#include "../data/tables/axis/DefaultWith10and20SplitSpacing-Load.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/axis/Slater-Load.h"
#else
#include "../data/tables/axis/FredsTruck-Load.h"
#endif
	},
	Table: {
#if CONFIG == DEFAULT_ID
#include "../data/tables/lambda/DefaultLambda24RPMx19Load.h"
#elif CONFIG == SLATER_ID
#include "../data/tables/lambda/SlaterLambda.h"
#else
#include "../data/tables/lambda/GenericLambda.h" // Reasonable starting point
#endif
	}
};
