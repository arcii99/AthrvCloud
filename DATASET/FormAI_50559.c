//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program simulates the weather for a given week.
 * It randomly picks a temperature and rain level for each day.
 * Users can input the location for which they wish to see the weather.
 */

int main()
{
    const char *locations[5] = {"New York City", "Seattle", "Miami", "Chicago", "Los Angeles"};
    int location;
    printf("Welcome to the Weather Simulation Program!\n");
    printf("Please enter the number corresponding to your location: \n");
    printf("1. New York City\n2. Seattle\n3. Miami\n4. Chicago\n5. Los Angeles\n");
    scanf("%d", &location);
    location--;

    srand(time(NULL));

    float temperatures[7];
    int rains[7];

    printf("\n\nWEEKLY FORECAST FOR %s:\n\n", locations[location]);

    for (int day = 0; day < 7; day++) {
        int temp = rand() % 31 + 40; // Temperatures between 40 and 70 degrees Fahrenheit
        temperatures[day] = temp;

        int rain = rand() % 101; // Rain level between 0 and 100 percent
        rains[day] = rain;

        printf("Day %d Temp: %0.1f °F, Rain: %d%%\n", day + 1, temperatures[day], rains[day]);
    }

    printf("\n\n");

    return 0;
}