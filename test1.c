#include "stats.h"
#include "catch.hpp"

#include <stdlib.h>
#include <math.h>

//int emailAlerter();
//int ledAlerter();

struct stats compute_statistics(float, int, struct);
//struct Stats computedStats = compute_statistics(numberset, setlength);

//struct Stats compute_statistics(const float* numberset, int setlength)
struct Stats {
    
    float average;
    int min;
    int max;
}

int main()
{
	struct Stats s;
	s.average = 0;
    s.min = 0;
    s.max = 0;
	
    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
	struct Stats compute_statistics(numberset, setlength, s);
	
	
}

struct stats compute_statistics(float numberset[], int setlength,struct Stats s)
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
		s.min=numberset[0];
		s.max=numberset[setlength-1];
		s.average = avg;
	}
	
	
}
