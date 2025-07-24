//FormAI DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // seed the random number generator
    srand(time(NULL));
  
    // create an array to hold the temperatures
    double temperatures[30];
  
    // generate random temperatures between 0 and 100
    for(int i=0; i<30; i++){
        temperatures[i] = ((double)rand()/(double)RAND_MAX) * 100;
    }
  
    // calculate statistics for the temperatures
    double sum = 0;
    double mean = 0;
    double variance = 0;
    double std_deviation = 0;
  
    for(int i=0; i<30; i++){
        sum += temperatures[i];
    }
  
    mean = sum/30;
  
    for(int i=0; i<30; i++){
        variance += (temperatures[i] - mean) * (temperatures[i] - mean);
    }
  
    variance /= 30;
  
    std_deviation = sqrt(variance);
  
    // print the statistics
    printf("Temperature statistics:\n");
    printf("Mean temperature: %0.2lf\n", mean);
    printf("Variance: %0.2lf\n", variance);
    printf("Standard deviation: %0.2lf\n", std_deviation);
  
    return 0;
}