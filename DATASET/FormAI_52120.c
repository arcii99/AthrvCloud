//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // to generate random values every time the program runs

    int temperature, pressure, humidity; // variables to store weather data

    printf("Welcome to the Weather Simulator!\n\n");

    // loop for simulating weather for 7 days
    for(int i=1; i<=7; i++) 
    {
        temperature = rand() % 30; // generate random temperature between 0°C and 30°C
        pressure = rand() % 1000 + 900; // generate random pressure between 900 hPa and 1000 hPa
        humidity = rand() % 100; // generate random humidity between 0% and 100%

        printf("Day %d:\n", i);

        // print temperature data
        printf("Temperature: %d°C\n", temperature);

        // print pressure data
        printf("Pressure: %d hPa\n", pressure);

        // print humidity data
        printf("Humidity: %d%%\n", humidity);

        // check for extreme weather conditions
        if(temperature >= 25 && humidity >= 80) // hot and humid
        {
            printf("Stay hydrated and avoid direct sunlight!\n\n");
        }
        else if(temperature <= 10 && pressure <= 950) // cold and low pressure
        {
            printf("Stay warm and cozy indoors!\n\n");
        }
        else if(pressure >= 1050) // high pressure
        {
            printf("Enjoy the clear skies and sunny weather!\n\n");
        }
        else // normal weather
        {
            printf("Enjoy the pleasant weather!\n\n");
        }
    }

    printf("Thank you for using the Weather Simulator!\n");

    return 0;
}