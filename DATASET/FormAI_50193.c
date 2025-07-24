//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp = 0;
    int minTemp = -10;
    int maxTemp = 50;
    srand(time(0)); //initialize srand with the current time

    printf("Welcome to the Post-Apocalyptic Temperature Monitor!\n");
    printf("Checking temperature readings...\n\n");

    for(int i = 1; i <= 10; i++)
    {
        temp = rand() % (maxTemp - minTemp + 1) + minTemp; //generate a random integer within the temperature range
        printf("Temperature Reading %d: %d degrees Celsius\n", i, temp);

        if(temp < 0)
        {
            printf("Warning! Extremely low temperature detected!\n");
            printf("Please take necessary actions to stay warm and prevent hypothermia\n");
        }
        else if(temp >= 0 && temp < 15)
        {
            printf("Caution! Below average temperature detected.\n");
            printf("Ensure you are wearing appropriate clothing to stay warm\n");
        }
        else if(temp >= 15 && temp < 30)
        {
            printf("Temperature is within normal range.\n");
            printf("Enjoy the mild weather while it lasts.\n");
        }
        else if(temp >= 30 && temp < 40)
        {
            printf("Warning! High temperature detected!\n");
            printf("Take necessary precautions to prevent heat exhaustion.\n");
        }
        else
        {
            printf("Danger! Extremely high temperature detected!\n");
            printf("Stay indoors or in a shaded area if possible.\n");
            printf("Hydrate frequently and avoid outdoor activities.\n");
        }
        printf("\n");
    }

    printf("Thank you for using the Post-Apocalyptic Temperature Monitor.\n");
    printf("Stay safe and adapt to the changing weather conditions.\n");
    return 0;
}