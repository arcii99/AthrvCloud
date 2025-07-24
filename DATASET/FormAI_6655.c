//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    float temperature[24], avg_temp = 0, min_temp = 50, max_temp = -50;
    
    //Setting the seed for random temperature generation
    srand(time(NULL));
    
    //Generating 24-hour temperature data
    for(i=0; i<24; i++) {
        temperature[i] = ((float)rand()/(float)(RAND_MAX)) * (40 - (-10)) + (-10); //Range: -10 to 40 degrees Celsius
    }
    
    //Calculating average, minimum and maximum temperature
    for(i=0; i<24; i++) {
        avg_temp += temperature[i];
        if(temperature[i] < min_temp) {
            min_temp = temperature[i];
        }
        if(temperature[i] > max_temp) {
            max_temp = temperature[i];
        }
    }
    avg_temp /= 24;
    
    //Printing the temperature data
    printf("24-Hour Weather Simulation\n\n");
    printf("Hour    Temperature\n");
    for(i=0; i<24; i++) {
        printf("%02d:00   %.1fC\n", i, temperature[i]);
    }
    
    //Printing the average, minimum and maximum temperature
    printf("\nAverage Temperature: %.1fC\n", avg_temp);
    printf("Minimum Temperature: %.1fC\n", min_temp);
    printf("Maximum Temperature: %.1fC\n", max_temp);
    
    return 0;
}