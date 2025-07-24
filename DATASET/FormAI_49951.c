//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, prev_temp = 0;
    time_t now;
    struct tm *local_time;
    char buffer[80];

    printf("Welcome to the C Temperature monitor program, dear Watson.\n");
    printf("I am afraid we have a mystery to solve, as the temperature gauge seems to be malfunctioning.\n");

    while(1) {
        temp = rand() % 20 + 10; // generate a random temperature between 10 and 30 degrees Celsius

        if(temp != prev_temp) { // only print the temperature if it has changed since the last check
            now = time(NULL);
            local_time = localtime(&now);
            strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", local_time);

            printf("Temperature at %s is %d degrees Celsius.\n", buffer, temp);

            if(temp > 25) { // if the temperature is above 25 degrees Celsius, we have a problem
                printf("This is alarming, Watson! We must investigate further.\n");
                // code for further investigation goes here
            }

            prev_temp = temp;
        }

        sleep(5); // wait for 5 seconds before checking the temperature again
    }

    return 0;
}