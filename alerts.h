void emailAlerter(float maxThreshold, struct Stats *ptr);
void ledAlerter(float maxThreshold, struct Stats *ptr);

void (*check_and_alert[])(float maxThreshold, struct Stats *ptr)={emailAlerter, ledAlerter};

//extern int emailAlertCallCount;
//extern int ledAlertCallCount;
