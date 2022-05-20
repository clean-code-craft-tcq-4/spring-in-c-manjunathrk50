void emailAlerter(int maxThreshold, struct Stats *ptr);
void ledAlerter(int maxThreshold, struct Stats *ptr);

void (*check_and_alert[])(int, &struct Stats)={emailAlerter, ledAlerter};

extern int emailAlertCallCount;
extern int ledAlertCallCount;
