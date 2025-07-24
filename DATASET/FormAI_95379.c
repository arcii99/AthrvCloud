//FormAI DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>

int main() {
    float current_temp, min_temp, max_temp;
    int time = 1;
    printf("Welcome to the Shocking Temperature Monitor!\n");
    printf("Please enter the minimum temperature for the day: ");
    scanf("%f", &min_temp);
    printf("Please enter the maximum temperature for the day: ");
    scanf("%f", &max_temp);
    printf("Temperature monitoring begins...\n\n");
    printf("*********** SHOCKING TEMPERATURE ALERT! ***********\n");
    while (1) {
        printf("Current Temperature (Time %d): ", time);
        scanf("%f", &current_temp);
        if (current_temp < min_temp || current_temp > max_temp) {
            printf("Temperature out of range! Quick, do something!\n");
            printf("*********** SHOCKING TEMPERATURE ALERT! ***********\n");
        } else {
            printf("Temperature within range. Whew, that was close!\n");
        }
        time++;
    }
    return 0;
}