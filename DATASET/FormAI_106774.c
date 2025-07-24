//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int red=0,yellow=0,green=1; // initializing the traffic light controller with green light
    char ch;
    printf("\nTraffic Light Controller Program");
    printf("\n\nPress any key to start the traffic light:");
    fflush(stdout);
    getchar();

    while(1)
    {
        if(green==1) // green light
        {
            printf("\nGreen Light!\n");
            printf("\nTraffic Flowing...\n");

            printf("\nPress 'r' to switch to Red Light, 'y' to switch to Yellow Light, 'q' to quit:");

            fflush(stdout);
            ch=getchar();
            getchar();

            if(ch=='r' || ch=='R') // switch to red light
            {
                green=0;
                yellow=0;
                red=1;
            }
            else if(ch=='y' || ch=='Y') // switch to yellow light
            {
                green=0;
                yellow=1;
                red=0;
            }
            else if(ch=='q' || ch=='Q') // quit the program
            {
                printf("\nQuitting the Traffic Light Controller Program\n");
                break;
            }
            else // invalid input
            {
                printf("\nInvalid Input. Press 'r' to switch to Red Light, 'y' to switch to Yellow Light, 'q' to quit\n");
            }
        }
        else if(yellow==1) // yellow light
        {
            printf("\nYellow Light!\n");
            printf("\nTraffic Slowing down...\n");

            printf("\nPress 'g' to switch to Green Light, 'r' to switch to Red Light, 'q' to quit:");

            fflush(stdout);
            ch=getchar();
            getchar();

            if(ch=='g' || ch=='G') // switch to green light
            {
                green=1;
                yellow=0;
                red=0;
            }
            else if(ch=='r' || ch=='R') // switch to red light
            {
                green=0;
                yellow=0;
                red=1;
            }
            else if(ch=='q' || ch=='Q') // quit the program
            {
                printf("\nQuitting the Traffic Light Controller Program\n");
                break;
            }
            else // invalid input
            {
                printf("\nInvalid Input. Press 'g' to switch to Green Light, 'r' to switch to Red Light, 'q' to quit\n");
            }
        }
        else if(red==1) // red light
        {
            printf("\nRed Light!\n");
            printf("\nTraffic Stopped...\n");

            printf("\nPress 'g' to switch to Green Light, 'y' to switch to Yellow Light, 'q' to quit:");

            fflush(stdout);
            ch=getchar();
            getchar();

            if(ch=='g' || ch=='G') // switch to green light
            {
                green=1;
                yellow=0;
                red=0;
            }
            else if(ch=='y' || ch=='Y') // switch to yellow light
            {
                green=0;
                yellow=1;
                red=0;
            }
            else if(ch=='q' || ch=='Q') // quit the program
            {
                printf("\nQuitting the Traffic Light Controller Program\n");
                break;
            }
            else // invalid input
            {
                printf("\nInvalid Input. Press 'g' to switch to Green Light, 'y' to switch to Yellow Light, 'q' to quit\n");
            }
        }
    }

    return 0;
}