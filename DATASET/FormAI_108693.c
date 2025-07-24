//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int red_time=5, yellow_time=2, green_time=5;  //time(in sec) for each traffic light phase 
    int traffic_volume[3]={30,40,35};     //number of vehicles passing from each direction per minute
    int i;

    #pragma omp parallel for
    for(i=1;i<=1000;i++)   //The traffic controller runs for 1000 cycles 
    {
        int curr_time=0;   //variable to keep track of current time
        int curr_phase=1;  //variable to keep track of current traffic light phase(1 for red, 2 for yellow, 3 for green)

        while(curr_time<60)  //each cycle lasts 1 minute
        {
            if(curr_phase==1)  //RED phase
            {
                printf("\n\nRED light ON\n");
                sleep(red_time);   //wait for red time
                curr_phase=2;     //set curr_phase to yellow
            }
            else if(curr_phase==2)  //YELLOW phase
            {
                printf("\n\nYELLOW light ON\n");
                sleep(yellow_time);  //wait for yellow time
                curr_phase=3;       //set curr_phase to green
            }
            else if(curr_phase==3)  //GREEN phase
            {
                printf("\n\nGREEN light ON\n");
                sleep(green_time);   //wait for green time
                curr_phase=1;       //set curr_phase to red
            }
            curr_time+=red_time+yellow_time+green_time;  //update the current time
        }
        printf("\n\nCycle %d complete!\n\n",i);
    }
    return 0;
}