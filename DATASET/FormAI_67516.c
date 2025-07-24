//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdlib.h>
#include <stdio.h>

#define TEMP_THRESHOLD 20.0

float read_temperature_sensor() {
    // simulated sensor reading
    return (float) rand() / (float) RAND_MAX * 30.0f;
}

void monitor_temperature(float temp) {
    printf("Current temperature: %.2fC\n", temp);
    
    if (temp > TEMP_THRESHOLD) {
        printf("Temperature above threshold! Sending warning email\n");
        // send email alert
    }
}

int main() {
    float temp;

    while(1) {
        temp = read_temperature_sensor();
        monitor_temperature(temp);
        sleep(1);
    }

    return 0;
}