#include "alerts.h"
#include "catch.hpp"

#include <stdlib.h>
#include <math.h>



int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


void emailAlerter(int maxThreshold, struct Stats *ptr)
{
    printf("we are in emailAlerter section\n");
	if((ptr->average) > maxThreshold)
	{ printf("email threshold is crossed\n");
		emailAlertCallCount++;
	}
	else 
		printf("email is out of range\n");
}

void ledAlerter(int maxThreshold, struct Stats *ptr)
{
    printf("we are in emailAlerter section\n");
	if((ptr->average) > maxThreshold)
	{ printf("led threshold crossed\n");
		ledAlertCallCount++;
	}
	else 
		printf("led is out of range\n");
}
