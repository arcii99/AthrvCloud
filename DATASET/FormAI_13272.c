//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: curious
#include <stdio.h> //includes standard input/output library

int main()
{
    int switcher = 0; //switcher variable used to control the traffic light
    printf("Welcome to the Traffic Light Controller Program!\n"); //welcome message
    
    while(1) //the program runs indefinitely
    {
        if(switcher == 0) //if switcher is 0, the traffic light is red
        {
            printf("Red light - STOP!\n");
            switcher++; //increment switcher to move to next traffic light
        }
        else if(switcher == 1) //if switcher is 1, the traffic light is yellow
        {
            printf("Yellow light - SLOW DOWN!\n");
            switcher++; //increment switcher to move to next traffic light
        }
        else if(switcher == 2) //if switcher is 2, the traffic light is green
        {
            printf("Green light - GO!\n");
            switcher = 0; //reset switcher to start the cycle again
        }
        
        //wait for 2 seconds before switching to next traffic light
        for(int i = 0; i < 2; i++)
        {
            printf("."); //visual cue of the delay
            sleep(1); //use sleep function to delay for 1 second
        }
        printf("\n"); //newline for clarity
    }
    return 0;
}