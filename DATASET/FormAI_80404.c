//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40.0
#define MIN_TEMP -10.0
#define MAX_PRESSURE 35.0
#define MIN_PRESSURE 10.0

int main() {
    srand(time(NULL)); // Seed the random number generator with time
    
    float temperature = (float) (rand()) / (float) (RAND_MAX) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
    float pressure = (float) (rand()) / (float) (RAND_MAX) * (MAX_PRESSURE - MIN_PRESSURE) + MIN_PRESSURE;
    
    printf("Initial Temperature: %.2f C\n", temperature);
    printf("Initial Pressure: %.2f hPa\n\n", pressure);
    
    int i;
    for (i = 1; i <= 10; i++) {
        float temp_change = (float) (rand()) / (float) (RAND_MAX) * 4 - 2; // Temperature can change by +/- 2 degrees
        float pressure_change = (float) (rand()) / (float) (RAND_MAX) * 4 - 2; // Pressure can change by +/- 2 hPa
        
        temperature += temp_change;
        pressure += pressure_change;
        
        // Check if temperature or pressure goes out of range
        if (temperature > MAX_TEMP) {
            temperature = MAX_TEMP;
        } else if (temperature < MIN_TEMP) {
            temperature = MIN_TEMP;
        }
        if (pressure > MAX_PRESSURE) {
            pressure = MAX_PRESSURE;
        } else if (pressure < MIN_PRESSURE) {
            pressure = MIN_PRESSURE;
        }
        
        printf("After hour %d:\n", i);
        printf("Temperature: %.2f C\n", temperature);
        printf("Pressure: %.2f hPa\n\n", pressure);
    }
    
    return 0;
}