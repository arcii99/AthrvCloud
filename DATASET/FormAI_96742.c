//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

int main() {
    int temperature;
    
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &temperature);
    
    if (temperature > MAX_TEMPERATURE) {
        printf("Temperature is too high!\n");
        temperature = MAX_TEMPERATURE;
    } else if (temperature < MIN_TEMPERATURE) {
        printf("Temperature is too low!\n");
        temperature = MIN_TEMPERATURE;
    }
    
    printf("Temperature is: %d C\n\n", temperature);
    
    return 0;
}