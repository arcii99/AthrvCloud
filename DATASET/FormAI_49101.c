//FormAI DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

int main()
{
    srand(time(NULL)); // initialize random seed

    int curr_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP; // generate random temperature between 0 and 100

    printf("Current temperature is %d degrees Celsius\n", curr_temp);

    if(curr_temp >= 90)
        printf("It's really hot in here!\n");
    else if(curr_temp >= 70)
        printf("It's getting warm, better turn on the fan!\n");
    else if(curr_temp >= 50)
        printf("It's a comfortable temperature!\n");
    else if(curr_temp >= 30)
        printf("It's a bit chilly, better put on a sweater.\n");
    else
        printf("It's freezing in here, I need to turn up the heat!\n");

    return 0;
}