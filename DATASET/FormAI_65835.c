//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100  // maximum temperature value
#define MIN_TEMP 0    // minimum temperature value

int getTemp() {
    int temp;
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temp);
    while (temp < MIN_TEMP || temp > MAX_TEMP) {   // check if within valid range
        printf("Temperature must be between %d and %d Celsius. Try again.\n", MIN_TEMP, MAX_TEMP);
        printf("Enter the temperature in Celsius: ");
        scanf("%d", &temp);
    }
    return temp;
}

int main() {
    int temp = getTemp();
    printf("Temperature is %d Celsius.\n", temp);
    return 0;
}