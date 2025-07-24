//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int red = 0, yellow = 0, green = 0, timeLeft = 0;
    srand(time(0));

    while(1)
    {
        int random = rand()%3 + 1;

        if(random == 1 && (red == 0 || green > 0))
        {
            red = 30;
            green = 0;
            yellow = 0;
            printf("\nRed Light ON\n\n");
        }
        else if(random == 2 && (yellow == 0 || red > 0))
        {
            yellow = 5;
            green = 0;
            red = 0;
            printf("\nYellow Light ON\n\n");
        }
        else if(random == 3 && (green == 0 || red > 0))
        {
            green = 40;
            red = 0;
            yellow = 0;
            printf("\nGreen Light ON\n\n");
        }

        while(red > 0)
        {
            printf("Time Left: %d\n", red);
            red--;
            sleep(1);
        }

        while(yellow > 0)
        {
            printf("Time Left: %d\n", yellow);
            yellow--;
            sleep(1);
        }

        while(green > 0)
        {
            printf("Time Left: %d\n", green);
            green--;
            sleep(1);
        }

    }

    return 0;
}