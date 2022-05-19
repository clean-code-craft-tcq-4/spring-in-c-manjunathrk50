#include "stats.h"
#include "catch.hpp"

#include <stdlib.h>
#include <math.h>


/*struct Stats {
    
    float average;
    float min;
    float max;
};

void compute_statistics(float numberset[], int setlength, struct Stats *ptr);*/

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/*int main()
{
	struct Stats s;
	s.average = 0;
    s.min = 0;
    s.max = 0;
	
    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = (int)sizeof(numberset) / sizeof(numberset[0]);
	struct Stats compute_statistics(numberset[], setlength, &s);
}*/

/*const char *show_classification(double x) {
    switch(fpclassify(x)) {
        case FP_INFINITE:  return "Inf";
        case FP_NAN:       return "NaN";
        default:           return "unknown";
    }
}*/

struct Stats compute_statistics(float numberset[], int setlength, struct Stats *ptr)
{
	int i;
	float avg, sum=0;
	float mn=numberset[0], mx=numberset[0];
	//char* ret=NULL;
	
	/*if(setlength == 0)
	{
		throw "Division by Zero condition ie NaN";
	}*/
	if(setlength == 0)
	{
		ptr->min=0;
		ptr->max=0;
		ptr->average = 0;
	}
	else {
	for(i=1;i<setlength;i++)
		{  if(numberset[i]>mx)
        {
            mx = numberset[i];
        }


        if(numberset[i]<mn)
        {
            mn = numberset[i];
        }
			
		}
	 printf("Maximum element is : %f\n", mx);
    printf("Minimum element is : %f\n", mn);
	for(i=0;i<setlength;i++)
	{
		sum=sum+numberset[i];
	}
printf("sum=%f\n", sum);
		avg=(sum)/(setlength);
		ptr->min=mn;
		ptr->max=mx;
		ptr->average = avg;
printf("ptr->min=%f ptr->max=%f ptr->average=%f\n", ptr->min, ptr->max, ptr->average);
	}
	
}
