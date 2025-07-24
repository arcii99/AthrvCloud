//FormAI DATASET v1.0 Category: Temperature monitor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); //seed for random numbers
    int temperature = 0, hotCount = 0, coldCount = 0; //temperature, hot count, cold count
    printf("Welcome to the temperature monitor. Press ctrl+c to exit.\n");

    while(1) //infinite loop
    {
        temperature = rand() % 101 - 50; //generate random temperature between -50C to 50C

        printf("Current temperature: %dC\n", temperature);

        if(temperature >= 30) //hot temperature
        {
            printf("It's getting hot in here, so take off all your clothes!\n");
            hotCount++; //increment hot count
        }
        else if(temperature <= -20) //cold temperature
        {
            printf("Do you want to build a snowman? Cause it's freezing outside!\n");
            coldCount++; //increment cold count
        }

        printf("Hot count: %d, Cold count: %d\n", hotCount, coldCount);
        printf("==================================================\n");

        sleep(5); //wait for 5 seconds before next reading
    }

    return 0;
}