//FormAI DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Function to generate a random temperature between -10C and 40C */
double getTemperature(){
    double temp = -10.0 + (double)rand() / RAND_MAX * (40.0 - (-10.0));
    return temp;
}

/* Function to generate a random wind speed between 0m/s and 25m/s */
double getWindSpeed(){
    double speed = 0.0 + (double)rand() / RAND_MAX * (25.0 - 0.0);
    return speed;
}

/* Function to generate a random precipitation level between 0mm and 50mm */
double getPrecipitation(){
    double rain = 0.0 + (double)rand() / RAND_MAX * (50.0 - 0.0);
    return rain;
}

int main(){
    srand(time(NULL)); /* Seed the random number generator */
    int i;
    for(i=0;i<24;i++){
        /* Simulate weather conditions for each hour */
        double temp = getTemperature();
        double speed = getWindSpeed();
        double rain = getPrecipitation();
        /* Print the weather conditions for this hour */
        printf("Hour %d: Temperature = %.1fC, Wind Speed = %.1fm/s, Precipitation Level = %.1fmm\n", i+1, temp, speed, rain);
    }
    return 0;
}