//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, wind_speed, chance_of_rain, humidity, is_raining;
    srand(time(NULL));
    
    printf("Welcome to the hilarious weather simulator! \n");
    printf("Enter the temperature today (in Celsius): ");
    scanf("%d", &temp);
    printf("Enter the wind speed today (in km/h): ");
    scanf("%d", &wind_speed);
    printf("Enter the chance of rain today (0-100%%): ");
    scanf("%d", &chance_of_rain);
    printf("Enter the humidity today (0-100%%): ");
    scanf("%d", &humidity);
    
    printf("Simulating weather...\n");
    
    if (chance_of_rain > 50) {
        is_raining = rand() % 2;
    }
    else {
        is_raining = rand() % 2;
        if (is_raining == 1) {
            printf("Surprise! It's raining even though the chance of rain was low.\n");
        }
    }
    
    printf("The temperature today is %dC\n", temp);
    printf("The wind speed today is %dkm/h\n", wind_speed);
    printf("The chance of rain today is %%%d\n", chance_of_rain);
    printf("The humidity today is %%%d\n", humidity);
    if (is_raining == 1) {
        printf("It's raining today. Don't forget your umbrella!\n");
    }
    else {
        printf("It's not raining today, but there's always a chance of a sudden downpour!\n");
    }
    
    printf("End of simulation. Thanks for using Hilarious Weather Simulator.\n");
    
    return 0;
}