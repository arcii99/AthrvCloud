//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
//SOPHISTICATED C TEMPERATURE MONITOR PROGRAM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_TEMP 100
#define MIN_TEMP 0
#define TEMP_LIMIT 30

//Function to generate random temperature between 0 and 100
int generateTemp(void)
{
    int temp;
    temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    return temp;
}

int main()
{
    int currentTemp = generateTemp();  //initialize temperature
    char time_string[30];              //initialize time string
    time_t current_time;               //initialize current time variable

    while (currentTemp <= TEMP_LIMIT)  //check temperature limit
    {
        current_time = time(NULL);         //get current time
        strftime(time_string, 30, "%m/%d/%Y %H:%M:%S", localtime(&current_time)); //format time
        printf("%s - Current Temperature: %dC\n", time_string, currentTemp);   //print time and temperature

        //update temperature
        currentTemp = generateTemp();
        sleep(1);   //wait for 1 second before checking temperature again
    }

    printf("Temperature Limit Reached! Please check the temperature.\n");

    return 0;
}