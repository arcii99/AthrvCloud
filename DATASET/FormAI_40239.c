//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE -50

int main() {
    int temperature;
    
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temperature);
    
    while (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) {
        printf("Invalid temperature entered. Please enter a temperature between %d and %d.\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
        printf("Enter the temperature in Celsius: ");
        scanf("%d", &temperature);
    }
    
    if (temperature < 0) {
        printf("The temperature is below freezing at %d degrees Celsius.\n", temperature);
    }
    else if (temperature > 0 && temperature < 25) {
        printf("The temperature is comfortable at %d degrees Celsius.\n", temperature);
    }
    else {
        printf("The temperature is hot at %d degrees Celsius.\n", temperature);
    }
    
    return 0;
}