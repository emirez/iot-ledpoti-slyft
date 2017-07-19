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

#ifndef __LEDPOTI_H
#define __LEDPOTI_H

/**
 * \brief Interface structure for Led Poti Example
 *
 * This stores the internal state and the bounds
 * for turning the led on or off.
 */
typedef struct ledpoti_s {

	int	poti;				/**< Last potentiometer value */

	bool led;			/**< Last LED state (true=on) */

	int lower_bound;		/**< LED goes on if poti in [lower_bound..upper_bound] */
	int upper_bound;		/**< LED goes of if poti out [lower_bound..upper_bound] */

} ledpoti_s;

/** error definitions */
enum ledpoti_status_e {
	LEDPOTI_OK = 0,
	LEDPOTI_OUTOFBOUNDS,
	LEDPOTI_INVALIDBOUNDS
};

/** status struct */
typedef struct ledpoti_status_s {
	bool	result;
	ledpoti_status_e	status; /**< 0, 1, 2 Values for Errors from ENUM */

} ledpoti_status_s;


/** \brief Initializes an empty struct, sets values to 0 */
void ledpoti_init(ledpoti_s *obj);

/** \brief reset the bounds */
ledpoti_status_s ledpoti_set_bounds(ledpoti_s *obj, int new_lower, int new_upper);

/** \brief returns the poti value */
int ledpoti_get_poti_value(ledpoti_s *obj);

/** \brief sets poti value, if bounds are ok */
ledpoti_status_s ledpoti_set_poti_value(ledpoti_s *obj, int new_poti_value);

/** \brief calculcates the led state */
bool ledpoti_evaluate_led_state(ledpoti_s *obj);

#endif
