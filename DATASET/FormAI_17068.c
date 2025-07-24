//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main() {
    int current_temperature = 0;
    int previous_temperature = 0;
    int difference = 0;
    int count = 0;
    char warning_message[50];

    printf("Welcome to the Temperature Monitor Program\n");

    while(1) {
        printf("Enter the current temperature: ");
        scanf("%d", &current_temperature);

        if(current_temperature < 0) {
            sprintf(warning_message, "WARNING! Temperature is below freezing, current temperature is %dC", current_temperature);
            printf("%s\n", warning_message);
        }

        if(previous_temperature != 0) {
            difference = current_temperature - previous_temperature;
            if(difference > 10) {
                printf("ALERT! Temperature increased by %d degrees within a minute\n", difference);
            }
        }

        if(count == 5) {
            printf("Checking for Malfunction....\n");
            if(abs(current_temperature - previous_temperature) < 5) {
                printf("Temperature Monitor is Malfunctioning, please replace it immediately\n");
                return 0;
            }
            count = 0;
        }

        previous_temperature = current_temperature;
        count++;
    }

    return 0;
}