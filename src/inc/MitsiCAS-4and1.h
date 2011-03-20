/* FreeEMS - the open source engine management system
 *
 * Copyright 2011 Fred Cooke
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


/**	@file MitsiCAS-4and1.h
 * @ingroup allHeaders
 * @ingroup enginePositionRPMDecoders
 *
 * @brief Unique MitsiCAS-4and1 setup data and variables
 *
 * @author Fred Cooke
 */


// Variables unique to this decoder, should be kept to a minimum!
static unsigned short edgeTimeStamp; /// @todo TODO why is this here, and why is it static/shared, investigate
static LongTime timeStamp; /// @todo TODO why is this here, and why is it static/shared, investigate


// Event angle setup via defines to minimise the opportunity for human error when changing values
#define OuterSlotAngle  69 // BUT 69 is too high, and 68 is even more too low = need to refactor to specify these angles accurately enough for perfect RPM/scheduling
#define InnerSlotAngle 140 // WAS 138 // WAS 139 // WAS 137 // Speculation: 140? Close to it... ignore my affection for round numbers... :-) HA! I was close to right this time, the other was right first guess and wants to be a little lower.

// Outer slot fixed events - these are, by definition, correct!
#define E0   0
#define E2 180
#define E4 360
#define E7 540

// These are offset from the fixed ones by the angle of the slot
#define E1 (E0 + OuterSlotAngle)
#define E3 (E2 + OuterSlotAngle)
#define E5 (E4 + OuterSlotAngle)
#define E8 (E7 + OuterSlotAngle)

// Inner slot events
#define E6 525 // WAS 527 // WAS 526 // Start position measured, just like outer on/off duty.
#define E9 (E6 + InnerSlotAngle)


// Definitions of decoder interface constants
const unsigned char decoderName[] = "MitsiCAS-4and1.c";
const unsigned char numberOfEvents = 10;
const unsigned short eventAngles[] = {E0, E1, E2, E3, E4, E5, E6, E7, E8, E9}; // needs to be shared with other decoders, defined here and referenced by the scheduler or similar
const unsigned short totalEventAngleRange = 720;
const unsigned short decoderMaxCodeTime = 100; // To be optimised (shortened)!