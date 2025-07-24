//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_LIGHT 20 //Green light duration in seconds
#define YELLOW_LIGHT 3 //Yellow light duration in seconds
#define RED_LIGHT (30 - GREEN_LIGHT - YELLOW_LIGHT) //Red light duration in seconds

//Function prototypes
int random_number(int min, int max);
void print_traffic_light(int light);
void simulate_traffic_flow();

int main()
{
    //Seed the random number generator
    srand(time(NULL));
    
    //Run the traffic flow simulation
    simulate_traffic_flow();
    
    return 0;
}

//Generates a random number between min and max
int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

//Prints the traffic light based on the current light value
void print_traffic_light(int light)
{
    switch (light)
    {
        case 0:
            printf("Green light\n");
            break;
        case 1:
            printf("Yellow light\n");
            break;
        case 2:
            printf("Red light\n");
            break;
        default:
            printf("Invalid light value\n");
            break;
    }
}

//Simulates the traffic flow for a given amount of time
void simulate_traffic_flow()
{
    int current_light = random_number(0, 2); //Start with a random traffic light
    int time_elapsed = 0; //Tracks the total time elapsed
    
    while (time_elapsed < 1800) //Run the simulation for 30 minutes (1800 seconds)
    {
        printf("Time elapsed: %d seconds\t", time_elapsed);
        print_traffic_light(current_light);
        
        //Wait for the current light duration
        switch (current_light)
        {
            case 0: //Green light
                printf("Traffic is flowing smoothly\n");
                usleep(GREEN_LIGHT * 1000000); //Sleep for green light duration in microseconds
                break;
            case 1: //Yellow light
                printf("Traffic is slowing down\n");
                usleep(YELLOW_LIGHT * 1000000); //Sleep for yellow light duration in microseconds
                break;
            case 2: //Red light
                printf("Traffic is stopped\n");
                usleep(RED_LIGHT * 1000000); //Sleep for red light duration in microseconds
                break;
            default:
                printf("Invalid light value\n");
                break;
        }
        
        //Switch to the next traffic light
        current_light = (current_light + 1) % 3;
        time_elapsed += GREEN_LIGHT + YELLOW_LIGHT + RED_LIGHT; //Add the duration of the current light cycle to the time elapsed
    }
}