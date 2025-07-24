//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator using the current time
    double temperature, humidity, rainfall;
    int year, month, day;

    printf("Enter a date in the format YYYY MM DD: ");
    scanf("%d %d %d", &year, &month, &day);

    // generate random weather data for the given date
    temperature = (rand() % 30) + 10; // temperature ranges from 10 to 40 degrees Celsius
    humidity = (rand() % 70) + 30; // humidity ranges from 30 to 100 percent
    rainfall = (rand() % 50) / 10.0; // rainfall ranges from 0 to 5 mm

    // display the weather information
    printf("Weather on %d/%d/%d:\n", day, month, year);
    printf("Temperature: %.1f degrees Celsius\n", temperature);
    printf("Humidity: %.1f%%\n", humidity);
    printf("Rainfall: %.1f mm\n", rainfall);

    return 0;
}