//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature = 0.0;
    int count = 0;
    float sum = 0.0;
    float average = 0.0;
    printf("Welcome to the Brave Temperature Monitor Program!\n");
    while (1) {
        printf("Enter temperature in degrees Celsius (enter -999 to exit):\n");
        scanf("%f", &temperature);
        if (temperature == -999) {
            break;
        }
        if (temperature < -273.15) {
            printf("Invalid temperature! Please enter a temperature higher than -273.15.\n");
            continue;
        }
        sum += temperature;
        count++;
        average = sum/count;
        printf("Temperature entered: %.2f degrees Celsius. Average temperature so far: %.2f degrees Celsius.\n", temperature, average);
    }
    printf("Thank you for using the Brave Temperature Monitor program!\n");
    return 0;
}