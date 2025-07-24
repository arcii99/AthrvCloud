//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: detailed
#include <stdio.h>

// function to simulate the traffic flow
void simulate_traffic_flow(int red_light_time, int green_light_time)
{
    int time = 0; // variable to keep track of time
    int num_cars_crossed = 0; // variable to keep track of number of cars crossed during simulation

    while (time < 1000) // simulate for 1000 seconds
    {
        if (time % (red_light_time + green_light_time) < red_light_time) // red light is on
        {
            printf("Red Light: Stop!\n");
        }
        else // green light is on
        {
            printf("Green Light: Go!\n");
            num_cars_crossed++; // increment number of cars crossed
        }

        // increment time
        time++;
    }

    printf("Simulation finished. %d cars crossed the traffic light.\n", num_cars_crossed);
}

int main()
{
    int red_light_time, green_light_time;

    printf("Enter red light time in seconds: ");
    scanf("%d", &red_light_time);

    printf("Enter green light time in seconds: ");
    scanf("%d", &green_light_time);

    simulate_traffic_flow(red_light_time, green_light_time);

    return 0;
}