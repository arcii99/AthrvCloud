//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Linus Torvalds
#include<stdio.h>
#include<time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping until required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main()
{
    int green = 1, yellow = 0, red =0;

    printf("Traffic Light Controller\n");

    while(1)
    {
        printf("\nGreen light on\n");
        delay(10);
        green = 0;
        yellow = 1;
        printf("\nGreen light off\n");

        printf("\nYellow light on\n");
        delay(2);
        yellow = 0;
        red = 1;
        printf("\nYellow light off\n");

        printf("\nRed light on\n");
        delay(10);
        red = 0;
        green = 1;
        printf("\nRed light off\n");
    }

    return 0;
}