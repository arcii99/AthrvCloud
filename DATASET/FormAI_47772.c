//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature;
    srand(time(0)); // Initialize random number generator with current time
    temperature = rand() % 101; // Generate a random temperature between 0 and 100

    printf("The current temperature is %d degrees Celsius.\n", temperature);

    if (temperature < 0)
    {
        printf("The temperature is extremely cold. Wear thick clothing to stay warm!\n");
    }
    else if (temperature >= 0 && temperature < 10)
    {
        printf("The temperature is quite cold. Wear a jacket!\n");
    }
    else if (temperature >= 10 && temperature < 20)
    {
        printf("The temperature is cool. You might want to consider bringing a sweater.\n");
    }
    else if (temperature >= 20 && temperature < 30)
    {
        printf("The temperature is comfortable. Enjoy the weather!\n");
    }
    else if (temperature >= 30 && temperature < 40)
    {
        printf("The temperature is quite hot. Stay hydrated and avoid direct sunlight!\n");
    }
    else
    {
        printf("The temperature is extremely hot. Stay indoors and keep your body cool!\n");
    }

    return 0;
}