/**
* This is a Contionuous Integration orientation program that is written for
* demonstrating Agile Software Development Techniques in IoT.
*
* Designed especially for working with NodeMCUv2 with LED and Rotary Switch
*
* The LED works as an digital actuator according to data coming from analog
* rotary angle sensor. The analog input value from potentiometer makes LED
* on/off by looking its operating range.
*
* Digital and analog ports are used for LED and potentiometer.
* D5 -> LED
* A0 -> ROTary Potentiometer
*
* In sake of achieving CoAP-enabled control, the Slyft API is used for
* wrapping. Further reading: www.slyft.io
*
* We are ThingForward and we make programming for "things" in the rapidly
* evolving world of IoT simpler, faster, better and easier to maintain.
* Our comprehensive developer tools and support services ensure that your
* embedded devices get to market fast - making sure your company can profit
* from the full potential of IoT. Further reading: www.ThingForward.io
*
* Copyright (C) 2017 thingforward.io
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ledpoti.h"
/** \brief Global declarations for Poti boundary values. */
#define POTI_VALUE_MAX 	1023 /**< Maximum Poti value can be 1023 */
#define POTI_VALUE_MIN	0 /**< Maximum Poti value can be 0 */

/** \brief Initiate the struct obj with initial values. */
void ledpoti_init(ledpoti_s *obj) {
	obj->poti = 0;						/**< First potentiometer value */
	obj->led = false;				  /**< First LED value */
	obj->lower_bound = 0;		  /**< First lower bound value */
	obj->upper_bound = 1023;  /**< First upper bound value */
}

/** \brief Sets bound values. */
ledpoti_status_s ledpoti_set_bounds(ledpoti_s *obj, int new_lower, int new_upper) {
	ledpoti_status_s res;

	if ( new_lower >= POTI_VALUE_MIN && new_upper <= POTI_VALUE_MAX) {
		if ( new_upper >= POTI_VALUE_MIN && new_upper <= POTI_VALUE_MAX) {
			if ( new_upper > new_lower) {
				obj->lower_bound = new_lower;
				obj->upper_bound = new_upper;
				res.status = LEDPOTI_OK;
			} else {
				res.status = LEDPOTI_INVALIDBOUNDS;
			}
		} else {
			res.status = LEDPOTI_OUTOFBOUNDS;
		}
	} else {
		res.status = LEDPOTI_OUTOFBOUNDS;
	}

	return res;
}

/** \brief Returns the poti value. */
int ledpoti_get_poti_value(ledpoti_s *obj) {
	return obj->poti;
}
/** \brief Sets the poti value manually. */
ledpoti_status_s ledpoti_set_poti_value(ledpoti_s *obj, int new_poti_value) {
	ledpoti_status_s res;

	if ( new_poti_value >= POTI_VALUE_MIN && new_poti_value <= POTI_VALUE_MAX) {
		obj->poti = new_poti_value;
		res.status = LEDPOTI_OK;		/**< In bounds! */
		return res;
	}
	res.status = LEDPOTI_OUTOFBOUNDS; /**< Out of bounds! */
	return res;
}
/** \brief Evaluates the LED state according to Poti value. */
bool ledpoti_evaluate_led_state(ledpoti_s *obj) {
	int v = ledpoti_get_poti_value(obj); /**< Poti value alias */
	obj->led = ((v >= obj->lower_bound) && (v <= obj->upper_bound));
	return obj->led;
}
