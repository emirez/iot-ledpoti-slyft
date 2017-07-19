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

#ifndef UNIT_TEST

#include <Arduino.h>
#include "ledpoti.h"
#include "ledapp.h"

ledpoti_s obj; /**< New struct member */

/** \brief Setup function for initializations */
void setup() {
  Serial.begin(9600); /**< Serial port data rate is 9600 bits/sec */
  /** \brief Native environment application */
  ledpoti_init(&obj);
  ledpoti_set_bounds(&obj, 250, 750);
  /** \brief Embedded environment application */
  ledapp_ports_init();
}
/** \brief Processor-in-a-loop function for actions */
void loop() {
  /** \brief Embedded environment actions */
  ledapp_apploop(&obj);
  Serial.print("Poti Value: ");
  Serial.println(ledapp_get_poti_value());
  Serial.print("LED Value: ");
  Serial.println(ledapp_get_led_value());
  delay(1000);
}

#endif
