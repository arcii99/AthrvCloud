//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, windspeed;
    int minTemp = -10, maxTemp = 40;
    int minHumidity = 0, maxHumidity = 100;
    int minWindspeed = 0, maxWindspeed = 100;
    int day;

    srand(time(NULL)); // seed the random number generator with current time

    printf("Enter the number of days for weather simulation: ");
    scanf("%d", &day);
    if (day <= 0)
    {
        printf("Invalid input. Simulation days should be greater than 0.");
        return 0;
    }

    printf("\nDay\t Temperature (C)\t Humidity (%%)\t Wind Speed (km/h)\n");

    for(int i = 1; i <= day; i++)
    {
        temperature = rand() % (maxTemp - minTemp + 1) + minTemp; // generate random temperature within range
        humidity = rand() % (maxHumidity - minHumidity + 1) + minHumidity; // generate random humidity within range
        windspeed = rand() % (maxWindspeed - minWindspeed + 1) + minWindspeed; // generate random windspeed within range

        printf("%d\t %d\t\t\t %d\t\t %d\n", i, temperature, humidity, windspeed);
    }

    return 0;
}