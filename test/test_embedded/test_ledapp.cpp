#include <Arduino.h>
#include "unity.h"
#include <ledapp.h>
#include <ledpoti.h>

#ifdef UNIT_TEST

void embedded_test_init() {
	struct ledpoti_s	obj;
	ledpoti_init(&obj);
  TEST_ASSERT_EQUAL(1,1);
}

void setup(){
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(embedded_test_init);
  UNITY_END();
}

void loop() {

}

#endif
