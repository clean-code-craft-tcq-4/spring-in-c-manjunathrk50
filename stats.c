#include "stats.h"
#include "catch.hpp"

#include <stdlib.h>
#include <math.h>


//struct Stats compute_statistics(float, int, struct);


//struct Stats compute_statistics(const float* numberset, int setlength)
struct Stats {
    
    float average;
    float min;
    float max;
};

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

int main()
{
	struct Stats s;
	s.average = 0;
    s.min = 0;
    s.max = 0;
	
    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = (int)sizeof(numberset) / sizeof(numberset[0]);
	struct Stats compute_statistics(numberset[], setlength, &s);
	
	
}

struct Stats compute_statistics(float numberset[], int setlength, struct Stats *ptr)
{
	int i,j;
	float avg, sum=0;
	for(i=0; i<setlength;i++)
	{  for(j=0;j<setlength-i;j++)
		{
			if(numberset[i] > numberset[i+1])
			{
				int temp=numberset[i];
				numberset[i]=numberset[i+1];
				numberset[i+1]=temp;
			}
		}
		printf("Displaying sorted elements of array\n");
		for(i=0;i<setlength;i++)
		{
			printf("%f ", numberset[i]);
			sum=sum+numberset[i];
		}
		printf("\n");
		avg=(sum)/(setlength);
		ptr->min=numberset[0];
		ptr->max=numberset[setlength-1];
		ptr->average = avg;
	}
	
	
}
