#include "alerts.h"
#include "catch.hpp"
#include "stats.h"

#include <stdlib.h>
#include <math.h>



//static int emailAlertCallCount = 0;
//static int ledAlertCallCount = 0;


void emailAlerter(float maxThreshold, struct Stats *ptr)
{
    printf("we are in emailAlerter section\n");
	if((ptr->average) > maxThreshold)
	{ printf("email threshold is crossed\n");
		emailAlertCallCount++;
	}
	else 
		printf("email is out of range\n");
}

void ledAlerter(float maxThreshold, struct Stats *ptr)
{
    printf("we are in emailAlerter section\n");
	if((ptr->average) > maxThreshold)
	{ printf("led threshold crossed\n");
		ledAlertCallCount++;
	}
	else 
		printf("led is out of range\n");
}
