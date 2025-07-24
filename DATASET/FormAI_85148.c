//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float temperature;
    float maxTemperature = -1000;
    float minTemperature = 1000;
    float totalTemperature = 0;
    int count = 0;
    
    printf("Welcome to the Temperature Monitor Program!\n\n");
    
    do {
        printf("Enter temperature in Celsius (or -999 to exit): ");
        scanf("%f", &temperature);
        
        if (temperature == -999) {
            printf("\nExiting program...\n");
            break;
        }
        
        if (temperature < -273.15) {
            printf("Temperature cannot be less than absolute zero (-273.15 C)\n");
            continue;
        }
        
        if (temperature > maxTemperature) {
            maxTemperature = temperature;
        }
        
        if (temperature < minTemperature) {
            minTemperature = temperature;
        }
        
        totalTemperature += temperature;
        count++;
        
        printf("Current Temperature: %.2f C\n", temperature);
        printf("Maximum Temperature: %.2f C\n", maxTemperature);
        printf("Minimum Temperature: %.2f C\n", minTemperature);
        printf("Average Temperature: %.2f C\n\n", totalTemperature/count);
        
    } while (temperature != -999);
    
    return 0;
}