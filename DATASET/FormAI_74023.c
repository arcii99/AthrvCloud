//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// constants
#define FLOORS 10
#define TIME_BETWEEN_FLOORS 2 // 2 seconds
#define TIME_BETWEEN_PASSENGERS 5 // 5 seconds
#define NUM_PASSENGERS 20
#define MAX_WEIGHT 100 // kg
#define ELEVATOR_CAPACITY 500 // kg

// global variables
pthread_mutex_t mutex;

int current_floor = 0;
bool elevator_is_moving = false;
bool elevator_doors_open = false;
bool up_button_pressed[FLOORS];
bool down_button_pressed[FLOORS];
int floor_queue[FLOORS];

int passengers_waiting[FLOORS]; // number of passengers waiting on each floor
int passengers_in_elevator = 0; // number of passengers in the elevator
int total_passengers_served = 0;

// function prototypes
void *elevator_main(void *);
void *passenger_main(void *);

// main function
int main()
{
    // initialize mutex
    if(pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("\nMutex initialization failed.\n");
        return 1;
    }
    
    // initialize up and down buttons as unpressed
    for(int i = 0; i < FLOORS; i++)
    {
        up_button_pressed[i] = false;
        down_button_pressed[i] = false;
    }
    
    // create elevator thread
    pthread_t elevator_thread;
    if(pthread_create(&elevator_thread, NULL, elevator_main, NULL) != 0)
    {
        printf("\nElevator thread creation failed.\n");
        return 1;
    }
    
    // create passenger threads
    pthread_t passenger_threads[NUM_PASSENGERS];
    for(int i = 0; i < NUM_PASSENGERS; i++)
    {
        if(pthread_create(&passenger_threads[i], NULL, passenger_main, (void *)&i) != 0)
        {
            printf("\nPassenger thread creation failed.\n");
            return 1;
        }
        usleep(TIME_BETWEEN_PASSENGERS * 1000); // wait for some time until next passenger is created
    }
    
    // wait for passenger threads to finish
    for(int i = 0; i < NUM_PASSENGERS; i++)
    {
        if(pthread_join(passenger_threads[i], NULL) != 0)
        {
            printf("\nPassenger thread join failed.\n");
            return 1;
        }
    }
    
    // signal to elevator thread that no more passengers are coming
    pthread_mutex_lock(&mutex);
    passengers_waiting[0] = -1;
    pthread_mutex_unlock(&mutex);
    
    // wait for elevator thread to finish
    if(pthread_join(elevator_thread, NULL) != 0)
    {
        printf("\nElevator thread join failed.\n");
        return 1;
    }
    
    // destroy mutex
    pthread_mutex_destroy(&mutex);
    
    printf("\nTotal passengers served: %d\n", total_passengers_served);
    
    return 0;
}

void *elevator_main(void *args)
{
    while(true)
    {
        // check if any button is pressed
        bool any_up_button_pressed = false;
        bool any_down_button_pressed = false;
        for(int i = 0; i < FLOORS; i++)
        {
            if(up_button_pressed[i] && i > current_floor)
            {
                any_up_button_pressed = true;
            }
            if(down_button_pressed[i] && i < current_floor)
            {
                any_down_button_pressed = true;
            }
        }
        
        // close doors if they are open and there is no one waiting
        if(elevator_doors_open && !any_up_button_pressed && !any_down_button_pressed && passengers_in_elevator == 0)
        {
            printf("\nDoors closing.\n");
            elevator_doors_open = false;
        }
        
        // if doors are closed, check if any button is pressed and move to that floor if so
        if(!elevator_doors_open)
        {
            if(any_up_button_pressed || any_down_button_pressed)
            {
                bool going_up = true;
                if(any_up_button_pressed && any_down_button_pressed && current_floor == 0)
                {
                    // if we are on ground floor and both buttons are pressed, choose direction based on weight
                    int total_weight_up = 0;
                    int total_weight_down = 0;
                    for(int i = 0; i < FLOORS; i++)
                    {
                        if(up_button_pressed[i])
                        {
                            total_weight_up += passengers_waiting[i];
                        }
                        if(down_button_pressed[i])
                        {
                            total_weight_down += passengers_waiting[i];
                        }
                    }
                    going_up = (total_weight_up >= total_weight_down);
                }
                else if(any_up_button_pressed && !any_down_button_pressed)
                {
                    going_up = true;
                }
                else if(!any_up_button_pressed && any_down_button_pressed)
                {
                    going_up = false;
                }
                int next_floor;
                if(going_up)
                {
                    next_floor = current_floor + 1;
                    while(next_floor < FLOORS && !up_button_pressed[next_floor])
                    {
                        next_floor++;
                    }
                    if(next_floor == FLOORS) // no more up buttons pressed
                    {
                        while(next_floor >= 0 && !down_button_pressed[next_floor])
                        {
                            next_floor--;
                        }
                        going_up = false;
                    }
                }
                else
                {
                    next_floor = current_floor - 1;
                    while(next_floor >= 0 && !down_button_pressed[next_floor])
                    {
                        next_floor--;
                    }
                    if(next_floor < 0) // no more down buttons pressed
                    {
                        while(next_floor < FLOORS && !up_button_pressed[next_floor])
                        {
                            next_floor++;
                        }
                        going_up = true;
                    }
                }
                floor_queue[0] = next_floor;
                for(int i = 1; i < FLOORS; i++)
                {
                    if(going_up)
                    {
                        if(up_button_pressed[i])
                        {
                            floor_queue[i] = i;
                        }
                        else
                        {
                            floor_queue[i] = -1;
                        }
                    }
                    else
                    {
                        if(down_button_pressed[i])
                        {
                            floor_queue[i] = i;
                        }
                        else
                        {
                            floor_queue[i] = -1;
                        }
                    }
                }
                printf("\nGoing to floor %d.\n", next_floor);
                elevator_is_moving = true;
            }
        }
        
        // if elevator is moving, update current floor after 2 seconds
        if(elevator_is_moving)
        {
            usleep(TIME_BETWEEN_FLOORS * 1000); // wait for 2 seconds (simulated floor travel time)
            current_floor = floor_queue[0];
            elevator_is_moving = false;
            printf("\nArrived at floor %d.\n", current_floor);
            floor_queue[0] = -1;
            up_button_pressed[current_floor] = false;
            down_button_pressed[current_floor] = false;
            if(passengers_waiting[current_floor] > 0 || passengers_in_elevator > 0)
            {
                printf("\nDoors opening.\n");
                elevator_doors_open = true;
                usleep(2000 * 1000); // wait for 2 seconds (simulated time to let passengers in/out)
                printf("\nDoors closing.\n");
                elevator_doors_open = false;
                total_passengers_served += passengers_in_elevator;
                passengers_in_elevator = 0;
            }
        }
        
        // if we have served all passengers, break the loop and exit the thread
        bool all_served = true;
        for(int i = 0; i < FLOORS; i++)
        {
            if(passengers_waiting[i] > 0)
            {
                all_served = false;
                break;
            }
        }
        if(all_served)
        {
            break;
        }
    }
    
    return NULL;
}

void *passenger_main(void *args)
{
    int id = *(int *)args;
    int weight = rand() % MAX_WEIGHT + 50; // random weight between 50 and 149 kg
    int starting_floor = rand() % FLOORS;
    int destination_floor = rand() % FLOORS;
    while(destination_floor == starting_floor) // make sure destination floor is not the same as starting floor
    {
        destination_floor = rand() % FLOORS;
    }
    printf("\nPassenger %d with weight %d kg created on floor %d and going to floor %d.\n", id, weight, starting_floor, destination_floor);
    pthread_mutex_lock(&mutex);
    passengers_waiting[starting_floor]++;
    pthread_mutex_unlock(&mutex);
    while(true)
    {
        if(current_floor == starting_floor && elevator_doors_open)
        {
            // try to enter the elevator
            bool allowed_to_enter = false;
            pthread_mutex_lock(&mutex);
            if(passengers_in_elevator < (ELEVATOR_CAPACITY - weight))
            {
                allowed_to_enter = true;
                passengers_in_elevator += weight;
            }
            pthread_mutex_unlock(&mutex);
            if(allowed_to_enter)
            {
                printf("\nPassenger %d entered the elevator on floor %d.\n", id, starting_floor);
                pthread_mutex_lock(&mutex);
                passengers_waiting[starting_floor]--;
                pthread_mutex_unlock(&mutex);
                break;
            }
            else
            {
                printf("\nPassenger %d couldn't enter the elevator on floor %d.\n", id, starting_floor);
                usleep(TIME_BETWEEN_PASSENGERS * 1000); // wait for some time before trying again
            }
        }
        else if(current_floor == destination_floor && elevator_doors_open)
        {
            // leave the elevator
            pthread_mutex_lock(&mutex);
            passengers_in_elevator -= weight;
            pthread_mutex_unlock(&mutex);
            printf("\nPassenger %d left the elevator on floor %d.\n", id, destination_floor);
            break;
        }
        else if(passengers_waiting[starting_floor] == -1) // signaled by the main thread that they should stop waiting
        {
            printf("\nPassenger %d could not get on the elevator on floor %d and is leaving the building.\n", id, starting_floor);
            pthread_mutex_lock(&mutex);
            passengers_waiting[starting_floor]--;
            pthread_mutex_unlock(&mutex);
            break;
        }
        else
        {
            // wait for elevator
            usleep(TIME_BETWEEN_PASSENGERS * 1000); // wait for some time before trying again
        }
    }
    
    return NULL;
}