//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define MIN_DURATION 5
#define MAX_DURATION 10

// Function declarations
void print_traffic_lights(int current_light);
int select_next_light(int current_light);
int generate_duration();
void wait_seconds(int seconds);

// Main function
int main()
{
    int current_light = RED_LIGHT;
    while(true)
    {
        print_traffic_lights(current_light);
        int duration = generate_duration();
        wait_seconds(duration);

        current_light = select_next_light(current_light);
    }

    return 0;
}

// Functions
void print_traffic_lights(int current_light)
{
    int red_time, yellow_time, green_time;

    if (current_light == RED_LIGHT)
    {
        red_time = generate_duration();
        yellow_time = generate_duration();
        green_time = 0;
    }
    else if (current_light == YELLOW_LIGHT)
    {
        red_time = 0;
        yellow_time = generate_duration();
        green_time = 0;
    }
    else
    {
        red_time = 0;
        yellow_time = generate_duration();
        green_time = generate_duration();
    }

    printf("Red Light for %d seconds\n", red_time);
    printf("Yellow Light for %d seconds\n", yellow_time);
    printf("Green Light for %d seconds\n", green_time);
}

int select_next_light(int current_light)
{
    if (current_light == RED_LIGHT)
    {
        return GREEN_LIGHT;
    }
    else if (current_light == YELLOW_LIGHT)
    {
        return RED_LIGHT;
    }
    else
    {
        return YELLOW_LIGHT;
    }
}

int generate_duration()
{
    srand(time(NULL));
    int duration = rand() % (MAX_DURATION + 1 - MIN_DURATION) + MIN_DURATION;
    return duration;
}

void wait_seconds(int seconds)
{
    time_t start_time = time(NULL);
    while(difftime(time(NULL), start_time) < seconds);
}