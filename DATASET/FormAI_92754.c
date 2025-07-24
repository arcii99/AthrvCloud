//FormAI DATASET v1.0 Category: Weather simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int month, day, high_temp, low_temp, avg_temp, rainfall, i, j;
    int total_rainfall = 0, total_high_temp = 0, total_low_temp = 0, total_avg_temp = 0, count = 0;

    srand(time(NULL)); // Initializing random seed

    printf("Weather simulation example program\n");

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    printf("Enter number of days in month: ");
    scanf("%d", &day);

    printf("Month: %d, Days: %d\n", month, day);

    printf("Day      High        Low          Average         Rainfall\n");

    for(i = 1; i <= day; i++)
    {
        high_temp = rand() % 30 + 20; // Generating random high temperature between 20 to 50 degrees Celsius
        low_temp = rand() % (high_temp - 10) + 10; // Generating random low temperature between 10 to the high temperature - 10 degrees Celsius
        avg_temp = (high_temp + low_temp) / 2; // Calculating average temperature
        rainfall = rand() % 100; // Generating random rainfall between 0 to 100 millimeters

        total_high_temp += high_temp;
        total_low_temp += low_temp;
        total_avg_temp += avg_temp;
        total_rainfall += rainfall;
        count++;

        printf("%d%9d°C%9d°C%9d°C%12dmm\n", i, high_temp, low_temp, avg_temp, rainfall);
    }

    printf("\nSummary\n");
    printf("High temperature: %.1f°C\n", (float)total_high_temp/count);
    printf("Low temperature: %.1f°C\n", (float)total_low_temp/count);
    printf("Average temperature: %.1f°C\n", (float)total_avg_temp/count);
    printf("Total rainfall: %dmm\n", total_rainfall);

    return 0;
}