//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    float temp = 0;
    int threshold = 25;
    bool alarm = false;

    printf("Enter the current temperature: ");
    scanf("%f", &temp);

    printf("Enter threshold temperature: ");
    scanf("%d", &threshold);

    while(true) {
        if(temp >= threshold && !alarm) {
            printf("Temperature has exceeded threshold. Turning on alarm...\n");
            alarm = true;
        }
        else if(temp < threshold && alarm) {
            printf("Temperature has lowered below threshold. Turning off alarm...\n");
            alarm = false;
        }

        // Simulate temperature update
        temp += (float)(rand() % 10) / 10 - 0.5;

        // Display updated temperature
        printf("Current temperature: %.2f\n", temp);

        // Wait for next update
        sleep(1);
    }

    return 0;
}