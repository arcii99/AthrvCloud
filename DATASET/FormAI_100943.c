//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THRESHOLD 50
#define TEMPERATURE_RANGE 50
#define HUMIDITY_RANGE 100

int main() {
    srand(time(NULL));
    
    // Initialize variables
    int temperature, humidity, threshold;
    int num_days = 7;
    int num_hours = 24;
    int days[num_days][num_hours];
    
    // Generate random values for temperature and humidity for each hour for each day
    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_hours; j++) {
            temperature = rand() % TEMPERATURE_RANGE;
            humidity = rand() % HUMIDITY_RANGE;
            days[i][j] = temperature + humidity;
        }
    }
    
    // Calculate threshold average for each day
    for (int i = 0; i < num_days; i++) {
        int sum = 0;
        for (int j = 0; j < num_hours; j++) {
            sum += days[i][j];
        }
        threshold = sum / num_hours;
        if (threshold > MAX_THRESHOLD) {
            printf("Threshold exceeded on day %d\n", i+1);
        } else {
            printf("Threshold not exceeded on day %d\n", i+1);
        }
    }
    
    return 0;
}