//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int weather, temperature;

    srand(time(NULL)); // seeding the rand() function with current time

    weather = rand() % 4; // generates a random number from 0 to 3 for the weather
    temperature = rand() % 61 - 20; // generates a random number from -20 to 40 for the temperature

    printf("The temperature outside is %d degrees Celsius.\n", temperature);

    switch(weather)
    {
        case 0:
            printf("It's sunny outside!\n");
            break;
        case 1:
            printf("It's cloudy outside.\n");
            break;
        case 2:
            printf("It's rainy outside.\n");
            break;
        case 3:
            printf("It's snowing outside.\n");
            break;
        default:
            printf("Oops, something went wrong!\n");
    }

    return 0;
}