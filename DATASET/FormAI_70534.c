//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_TEMP_LIMIT 10
#define UPPER_TEMP_LIMIT 40
#define MIN_ALARM_VALUE 30
#define MAX_ALARM_VALUE 38

int main() {
    srand(time(NULL)); // Set random seed

    int temperature, alarm_status, alarm_value;
    temperature = rand() % (UPPER_TEMP_LIMIT - LOWER_TEMP_LIMIT + 1) + LOWER_TEMP_LIMIT; // Generate random temperature between 10 to 40 degree Celsius

    printf("Temperature: %dC\n", temperature);

    if (temperature < MIN_ALARM_VALUE || temperature > MAX_ALARM_VALUE) {
        alarm_status = 1;
        if (temperature < MIN_ALARM_VALUE) {
            alarm_value = MIN_ALARM_VALUE;
            printf("ALARM! Temperature is below %dC\n", alarm_value);
        }
        else {
            alarm_value = MAX_ALARM_VALUE;
            printf("ALARM! Temperature is above %dC\n", alarm_value);
        }
    }
    else {
        alarm_status = 0;
        printf("Temperature is within normal range\n");
    }

    return 0;
}