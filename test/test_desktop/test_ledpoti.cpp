#include "unity.h"
#include "ledpoti.h"
#include <stdio.h>

#ifdef UNIT_TEST

void test_init() {
	struct ledpoti_s	obj;

	ledpoti_init(&obj);

	TEST_ASSERT_EQUAL(obj.poti, 0);
	TEST_ASSERT_EQUAL(obj.led, false);

	TEST_ASSERT_EQUAL(obj.lower_bound, 0);
	TEST_ASSERT_EQUAL(obj.upper_bound, 1023);
}

void test_ledpoti_get() {
	struct ledpoti_s	obj;

	ledpoti_init(&obj);

	obj.poti = 500;
	TEST_ASSERT_EQUAL(ledpoti_get_poti_value(&obj), 500);

}

void test_ledpoti_set() {
	struct ledpoti_s	obj;

	ledpoti_init(&obj);

	ledpoti_status_s r0 = ledpoti_set_poti_value(&obj, 100);
	TEST_ASSERT_EQUAL(ledpoti_get_poti_value(&obj), 100);
	TEST_ASSERT_EQUAL(r0.status, LEDPOTI_OK);

	ledpoti_status_s r1 = ledpoti_set_poti_value(&obj, -5);
	TEST_ASSERT_EQUAL(ledpoti_get_poti_value(&obj), 100);
  TEST_ASSERT_EQUAL(r1.status, LEDPOTI_OUTOFBOUNDS);

	ledpoti_status_s r2 = ledpoti_set_poti_value(&obj, 2000);
	TEST_ASSERT_EQUAL(ledpoti_get_poti_value(&obj), 100);
	TEST_ASSERT_EQUAL(r2.status, LEDPOTI_OUTOFBOUNDS);

}

void test_ledpoti_evaluate_state() {
	struct ledpoti_s	obj;

	ledpoti_init(&obj);
	ledpoti_set_bounds(&obj, 250, 750);

  int 	good_values[5] = { 250, 539, 640, 700, 750 };
	int 	bad_values[5] = { 0, 149, 249, 751, 989 };

	bool r;
	for( int i = 0; i < sizeof(good_values)/sizeof(int); i++) {
		ledpoti_set_poti_value(&obj, good_values[i]);
		r = ledpoti_evaluate_led_state(&obj);
		TEST_ASSERT_EQUAL(r, true);

	}
	for( int i = 0; i < sizeof(bad_values)/sizeof(int); i++) {
		ledpoti_set_poti_value(&obj, bad_values[i]);
		r = ledpoti_evaluate_led_state(&obj);
		TEST_ASSERT_EQUAL(r, false);

	}


}


void test_ledpoti_set_bounds() {
	struct ledpoti_s	obj;

	ledpoti_init(&obj);
  ledpoti_status_s r;

	r = ledpoti_set_bounds(&obj, -1,100);
	TEST_ASSERT_EQUAL(r.status, LEDPOTI_OUTOFBOUNDS);
	r = ledpoti_set_bounds(&obj, 100,10900);
	TEST_ASSERT_EQUAL(r.status, LEDPOTI_OUTOFBOUNDS);
	r = ledpoti_set_bounds(&obj, 500,400);
	TEST_ASSERT_EQUAL(r.status, LEDPOTI_INVALIDBOUNDS);

	r = ledpoti_set_bounds(&obj, 400,500);
	TEST_ASSERT_EQUAL(r.status, LEDPOTI_OK);
	TEST_ASSERT_EQUAL(obj.lower_bound, 400);
	TEST_ASSERT_EQUAL(obj.upper_bound, 500);

}

int main(int argc, char **argv) {

	UNITY_BEGIN();

  RUN_TEST(test_init);
  RUN_TEST(test_ledpoti_get);
	RUN_TEST(test_ledpoti_set);
	RUN_TEST(test_ledpoti_evaluate_state);
	RUN_TEST(test_ledpoti_set_bounds);

	UNITY_END();

	return 0;
}



#endif
