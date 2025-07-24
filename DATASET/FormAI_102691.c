//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int max_temp, min_temp, avg_temp, rainfall, month, day;
    srand(time(NULL)); // Seed for randomization

    // User input for month and day
    printf("Enter the month(1-12): ");
    scanf("%d", &month);

    printf("Enter the day(1-31): ");
    scanf("%d", &day);

    // Random temperature calculation
    max_temp = rand() % 30 + 20;
    min_temp = rand() % 15 + 5;
    avg_temp = (max_temp + min_temp) / 2;

    // Random rainfall calculation
    rainfall = rand() % 200;

    printf("\n\nWeather Report for %d/%d\n", month, day);
    printf("----------------------------\n");
    printf("Maximum Temperature: %dF\n", max_temp);
    printf("Minimum Temperature: %dF\n", min_temp);
    printf("Average Temperature: %dF\n", avg_temp);
    printf("Rainfall: %dmm\n", rainfall);

    if(rainfall > 100){
        printf("The weather is likely to be stormy today. Stay indoors!\n");
    } else if (rainfall > 50) {
        printf("There might be some drizzle. Take an umbrella!\n");
    } else {
        printf("The weather today is mostly dry and sunny.\n");
    }

    return 0;
}