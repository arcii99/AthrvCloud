//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to wait for a given number of seconds
void delay(int seconds)
{
    int milliseconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main()
{
    int green = 1, yellow = 2, red = 3;
    int signal_time = 10; //time for each signal in seconds
    
    //Loop to run the traffic signal controller indefinitely
    while(1)
    {
        //Set Green signal for North-South traffic       
        printf("\nGREEN signal for North-South traffic\n");
        delay(signal_time);
        
        //Set Yellow signal for North-South traffic
        printf("\nYELLOW signal for North-South traffic\n");
        delay(signal_time/3);
        
        //Set Red signal for North-South traffic
        printf("\nRED signal for North-South traffic\n");
        delay(signal_time);
        
        //Set Green signal for East-West traffic
        printf("\nGREEN signal for East-West traffic\n");
        delay(signal_time);
        
        //Set Yellow signal for East-West traffic
        printf("\nYELLOW signal for East-West traffic\n");
        delay(signal_time/3);
        
        //Set Red signal for East-West traffic
        printf("\nRED signal for East-West traffic\n");
        delay(signal_time);
    }
    
    return 0;
}