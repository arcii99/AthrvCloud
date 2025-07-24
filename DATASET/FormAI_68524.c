//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    //define array for data
    float data[10]={6.2,7.1,5.6,8.9,9.8,4.5,2.3,1.2,3.4,5.9};

    //calculate mean of the data
    float mean=0;
    for(int i=0;i<10;i++)
    {
        mean+=data[i];
    }
    mean/=10;

    //calculate standard deviation of the data
    float stdev=0;
    for(int i=0;i<10;i++)
    {
        stdev+=pow(data[i]-mean,2);
    }
    stdev=sqrt(stdev/10);

    //calculate z-score for each data point
    for(int i=0;i<10;i++)
    {
        float z=(data[i]-mean)/stdev;
        printf("For data point %d, z-score = %.2f\n",i+1,z);
    }

    return 0;
}