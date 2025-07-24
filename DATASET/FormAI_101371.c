//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int temp; // variable to store temperature
    srand(time(NULL)); // seed the random number generator using current time

    printf("Temperature Monitor\n");

    // loop 10 times to simulate random temperature readings
    for(int i=1; i<=10; i++) 
    { 
        temp = rand()%100; // generate random number between 0 and 99
        printf("Reading %d: %d degrees Celsius\n", i, temp);

        // check if temperature is too high or too low
        if(temp >= 50)
            printf("WARNING: Temperature is too high!\n");
        else if(temp <= 0)
            printf("WARNING: Temperature is too low!\n");

        // wait for 2 seconds before taking next reading
        sleep(2); 
    }

    printf("End of Monitoring\n");

    return 0;
}