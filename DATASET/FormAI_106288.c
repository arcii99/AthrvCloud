//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int red = 1, yellow = 0, green = 0;
    int time = 0;

    while(1)
    {
        system("clear"); // Clears the console window

        printf("\n\n\t\tTraffic Light Controller\n\n");

        if (red == 1) // If red light is on
        {
            printf("\t\t  RED LIGHT ON\n\n");
            printf("\t\t  YELLOW LIGHT OFF\n\n");
            printf("\t\t  GREEN LIGHT OFF\n\n");

            if (time >= 10) // If 10 seconds have passed
            {
                red = 0;
                yellow = 1;
                time = 0;
            }
        }

        else if (yellow == 1) // If yellow light is on
        {
            printf("\t\t  RED LIGHT OFF\n\n");
            printf("\t\t  YELLOW LIGHT ON\n\n");
            printf("\t\t  GREEN LIGHT OFF\n\n");

            if (time >= 5) // If 5 seconds have passed
            {
                yellow = 0;
                green = 1;
                time = 0;
            }
        }

        else if (green == 1) // If green light is on
        {
            printf("\t\t  RED LIGHT OFF\n\n");
            printf("\t\t  YELLOW LIGHT OFF\n\n");
            printf("\t\t  GREEN LIGHT ON\n\n");

            if (time >= 15) // If 15 seconds have passed
            {
                green = 0;
                yellow = 1;
                time = 0;
            }
        }

        time++; // Increment time by 1 second

        // Wait for 1 second before showing the next light
        sleep(1);
    }

    return 0;
}