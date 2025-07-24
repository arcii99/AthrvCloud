//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int temperature = rand() % 40 + 10; // Generating random temperature from 10 to 50 degrees

    if (temperature < 20)
    {
        printf("It is very cold outside with a temperature of %d degrees Celsius.\n", temperature);
    }
    else if (temperature >= 20 && temperature < 30)
    {
        printf("It is a moderate day outside with a temperature of %d degrees Celsius.\n", temperature);
    }
    else
    {
        printf("It is very hot outside with a temperature of %d degrees Celsius.\n", temperature);
    }

    int chance_of_rain = rand() % 100; // Generating a random number for the chance of rain

    if (chance_of_rain < 30)
    {
        printf("It seems like it's not going to rain today.\n");
    }
    else if (chance_of_rain >= 30 && chance_of_rain < 60)
    {
        printf("There might be a slight chance of rain today.\n");
    }
    else
    {
        printf("It looks like it's going to rain today.\n");
    }

    int wind_speed = rand() % 40; // Generating a random number for wind speed

    if (wind_speed < 10)
    {
        printf("There is hardly any wind today.\n");
    }
    else if (wind_speed >= 10 && wind_speed < 20)
    {
        printf("It's a bit windy today with winds blowing at %d km/h.\n", wind_speed);
    }
    else if (wind_speed >= 20 && wind_speed < 30)
    {
        printf("It's quite a windy day today with winds blowing at %d km/h.\n", wind_speed);
    }
    else
    {
        printf("Beware of the strong winds today! They are blowing at %d km/h.\n", wind_speed);
    }

    return 0;
}