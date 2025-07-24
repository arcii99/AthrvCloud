//FormAI DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int days;
    float temperature;

    srand(time(NULL)); // Initializing random number generator with current time 

    printf("Enter number of days you want to simulate weather for: ");
    scanf("%d", &days);

    printf("\nWeather simulation for %d days:\n", days);

    for (int i = 1; i <= days; i++) {

        temperature = (float)(rand() % 50) - 10; // Generating random temperature between -10 and 40 degrees Celsius

        printf("Day %d: Temperature %.2f degrees Celsius\n", i, temperature);
        
        if (temperature < 0) {
            printf("It's freezing cold outside! Dress warmly!\n");
        }
        else if (temperature < 10) {
            printf("It's cool outside! Dress in layers!\n");
        }
        else if (temperature < 20) {
            printf("The weather is mild. Enjoy!\n");
        }
        else if (temperature < 30) {
            printf("It's warm outside! Wear light clothes!\n");
        }
        else {
            printf("It's scorching hot outside! Stay hydrated!\n");
        }

        printf("\n");
    }

    return 0;
}