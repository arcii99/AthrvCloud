//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIMESTEP 0.001
#define THERMOCOUPLE_ACCURACY 0.01
#define EXPECTED_TEMP_CHANGE_PER_SEC 0.5
#define TEMP_MON_INTERVAL 5.0

double getTemperature() {
    double noise = (double)rand()/RAND_MAX * THERMOCOUPLE_ACCURACY;
    double temperature = 20.0 + sin(time(NULL))*EXPECTED_TEMP_CHANGE_PER_SEC*TEMP_MON_INTERVAL + noise;
    return temperature;
}

int main() {
    double temperature;
    double timeElapsed = 0.0;
    double lastTempReading = 0.0;
    double highestTemp = 0.0;
    double lowestTemp = 100.0;
    int numReadings = 0;
    int numHighReadings = 0;

    printf("Starting temperature monitoring...\n");

    while(1) {
        temperature = getTemperature();
        if (temperature > highestTemp) {
            highestTemp = temperature;
        }
        if (temperature < lowestTemp) {
            lowestTemp = temperature;
        }
        if (fabs(temperature - lastTempReading) > THERMOCOUPLE_ACCURACY) {
            printf("Temperature has changed from %f to %f\n", lastTempReading, temperature);
            lastTempReading = temperature;
            numReadings++;
            if (temperature >= 90.0) {
                printf("***HIGH TEMPERATURE ALERT***\n");
                numHighReadings++;
            }
        }

        if (fmod(timeElapsed, TEMP_MON_INTERVAL) < TIMESTEP) {
            printf("Current temperature: %f\n", temperature);
            printf("Highest temperature so far: %f\n", highestTemp);
            printf("Lowest temperature so far: %f\n", lowestTemp);
            printf("Average temperature: %f\n", (highestTemp + lowestTemp)/2.0);
            printf("Number of temperature readings: %d\n", numReadings);
            printf("Number of high temperature readings: %d\n", numHighReadings);
        }

        timeElapsed += TIMESTEP;
    }

    return 0;
}