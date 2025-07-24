//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int weather[7][24]; // 7 days a week, 24 hours a day

    srand(time(0)); // seed the random number generator

    // initialize the weather array with random temperature values
    for (int day=0; day<7; day++) {
        for (int hour=0; hour<24; hour++) {
            weather[day][hour] = rand() % 31 - 10; // temperature range from -10 to 20 Celsius
        }
    }

    // print the weather forecast for the next 7 days
    printf("Weather Forecast (Celsius):\n");
    printf("---------------------------\n");
    printf("   Hour   |   Mon   |   Tue   |   Wed   |   Thu   |   Fri   |   Sat   |   Sun   |\n");
    printf("------------------------------------------------------------------------------\n");
    for (int hour=0; hour<24; hour++) {
        printf("%02d:00-%02d:00", hour, hour+1);
        for (int day=0; day<7; day++) {
            printf(" | %c%d ", weather[day][hour] >= 0 ? '+' : '-', abs(weather[day][hour]));
        }
        printf("|\n");
    }
    printf("------------------------------------------------------------------------------\n");

    // calculate the average temperature for each day of the week
    int avg[7];
    for (int day=0; day<7; day++) {
        avg[day] = 0;
        for (int hour=0; hour<24; hour++) {
            avg[day] += weather[day][hour];
        }
        avg[day] /= 24;
    }

    // print the average temperature for each day of the week
    printf("\nAverage Temperature (Celsius):\n");
    printf("--------------------------------\n");
    printf("Mon: %c%d\n", avg[0] >= 0 ? '+' : '-', abs(avg[0]));
    printf("Tue: %c%d\n", avg[1] >= 0 ? '+' : '-', abs(avg[1]));
    printf("Wed: %c%d\n", avg[2] >= 0 ? '+' : '-', abs(avg[2]));
    printf("Thu: %c%d\n", avg[3] >= 0 ? '+' : '-', abs(avg[3]));
    printf("Fri: %c%d\n", avg[4] >= 0 ? '+' : '-', abs(avg[4]));
    printf("Sat: %c%d\n", avg[5] >= 0 ? '+' : '-', abs(avg[5]));
    printf("Sun: %c%d\n", avg[6] >= 0 ? '+' : '-', abs(avg[6]));

    return 0;
}