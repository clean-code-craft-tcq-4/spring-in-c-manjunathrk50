//struct Stats compute_statistics(const float* numberset, int setlength);
//struct Stats compute_statistics(float, int, struct Stats);
#define NAN 0
struct Stats {
    
    float average;
    float min;
    float max;
};
struct Stats computedStats;
void compute_statistics(float numberset[], int setlength, struct Stats *ptr);
	

//typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
