//FormAI DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TEMPERATURE 100.00 // Maximum Temperature
#define MIN_TEMPERATURE 0.00 // Minimum Temperature
#define TEMP_THRESHOLD 30.00 // Temperature Threshold

float read_temperature_from_sensor() {
    srand(time(NULL)); // Seed for Random Number Generation
    float temp = ((float)rand()/(float)(RAND_MAX)) * MAX_TEMPERATURE;
    return temp;
}

bool is_temperature_above_threshold(float temp) {
    if(temp > TEMP_THRESHOLD)
        return true;
    else
        return false;
}

int main(){
    float temperature;
    char choice;
    do {
        temperature = read_temperature_from_sensor();
        printf("Current Temperature: %.2f\n", temperature);
        if (is_temperature_above_threshold(temperature)) {
            printf("Temperature exceeds threshold of %.2f degrees\n", TEMP_THRESHOLD);
            // CODE TO NOTIFY AUTHORITY ABOUT HIGH TEMPERATURE
            // SECURE NOTIFICATION SYSTEM
        }
        printf("Do you want to continue monitoring(Y/N)? ");
        scanf(" %c", &choice);
    } while(choice == 'Y' || choice == 'y');
    return 0;
}