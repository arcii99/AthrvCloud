//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float celsius, fahrenheit;
    int humidity, pressure;
    time_t now;
    time(&now);
    
    srand(time(NULL));
    humidity = rand() % 100;
    pressure = rand() % 1013 + 1000;
    // Generate random humidity and pressure values
    
    printf("------------------------------\n");
    printf("  Temperature Monitor v1.0\n");
    printf("------------------------------\n");
    printf("Date and Time: %s", ctime(&now));
    // Print current date and time using ctime function
    printf("------------------------------\n");
    printf("Enter Celsius temperature: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Fahrenheit temperature: %.2f F\n", fahrenheit);
    printf("------------------------------\n");
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d mbar\n", pressure);
    printf("------------------------------\n");
    
    if (celsius <= 0) {
        printf("Warning: Temperature is below freezing point.\n");
    } else if (celsius >= 100) {
        printf("Warning: Temperature is above boiling point.\n");
    }
    
    return 0;
}