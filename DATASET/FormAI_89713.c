//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define TEMP_SENSOR_PIN 8
#define MAX_TEMP 50.0

float getTemperature() {
    // Code to read temperature from sensor connected to pin TEMP_SENSOR_PIN
    float temp = (float)rand()/(float)(RAND_MAX/MAX_TEMP);
    return temp;
}

void displayTemperature(float temperature) {
    printf("Current Temperature: %.2f Celsius\n", temperature);
    if (temperature >= 40.0) {
        printf("Alert! Temperature is above 40.00 Celsius\n");
    }
}

int main() {
    printf("C Temperature Monitor - Grateful Style\n");
    printf("-------------------------------------\n");
    printf("Initializing...\n\n");
    
    // Code to initialize temperature sensor pin and other necessary modules
    printf("Temperature sensor initialized on pin %d\n\n", TEMP_SENSOR_PIN);
    
    while(1) {
        float temperature = getTemperature();
        displayTemperature(temperature);

        // Code to wait for 5 seconds before reading temperature again
        printf("\nWaiting for 5 seconds...\n\n");
        sleep(5);
    }

    return 0;
}