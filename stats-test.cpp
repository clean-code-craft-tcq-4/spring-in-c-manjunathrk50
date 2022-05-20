#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include "alerts.h"

#include <stdlib.h>
#include <math.h>


TEST_CASE("reports average, minimum and maximum") {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
	struct Stats computedStats;
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    //struct Stats computedStats = compute_statistics(numberset, setlength, struct Stats s);
     compute_statistics(numberset, setlength, &computedStats);
    float epsilon = 0.001;
    REQUIRE(abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    //Stats computedStats = compute_statistics(0, 0, struct Stats s);
	struct Stats computedStats;
	 compute_statistics(0, 0, &computedStats);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
   //Design the REQUIRE statement here.
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
	
	REQUIRE(computedStats.average == NAN);
    REQUIRE(computedStats.max == NAN );
    REQUIRE(computedStats.min == NAN);
	
}

TEST_CASE("raises alerts when max is greater than threshold") {
    /// create additional .c and .h files
    // containing the emailAlerter, ledAlerter functions
    //alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
	

    unsigned ch;
    float numberset[] = {99.8, 34.2, 4.5};
	struct Stats computedStats;
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
   // Stats computedStats = compute_statistics(numberset, setlength);
    compute_statistics(numberset, setlength, &computedStats);

    const float maxThreshold = 10.2;
void (*check_and_alert[])(int, struct Stats*)={emailAlerter, ledAlerter};
	
	printf("Enter Choice: 0 for emailAlerter, 1 for ledAlerter\n");
    scanf("%d", &ch);
	(*check_and_alert[ch]) (maxThreshold, computedStats);
    //check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
