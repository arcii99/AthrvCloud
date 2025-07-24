//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 6
#define NUM_ELEVATORS 4

pthread_mutex_t mutex;

int floors[NUM_FLOORS];    
int elevators[NUM_ELEVATORS];           
    
int elevator_floor[NUM_ELEVATORS];     
int elevator_direction[NUM_ELEVATORS];

void init();
void * run_elevator();
void riding_elevator(int elevator_num, int current_floor, int destination_floor); 
int get_elevator_direction(int elevator_num); 

int main()
{
    pthread_t elevator_tid[NUM_ELEVATORS];    
    int i;
    
    init();

    if(pthread_mutex_init(&mutex,NULL) != 0) {
        printf("Mutex initialization failed\n");
        exit(1);
    }
    
    for (i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_tid[i], NULL, run_elevator, (void *)i);
    }

    for (i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_tid[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}


void init()
{
    int i;

    for (i = 0; i < NUM_FLOORS; i++) {
        floors[i] = 0;
    }

    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i] = 1;  
        elevator_floor[i] = 0;  
        elevator_direction[i] = 1; 
    }
}


void * run_elevator(void * elevator_param)
{
    int elevator_num = (int)elevator_param;
    int current_floor = 0;  

    while(1) {
        pthread_mutex_lock(&mutex);

        if(floors[current_floor] > 0 || elevators[elevator_num]) { 
            int destination_floor = -1;
            int i; 
            
            for (i = 0; i < NUM_FLOORS; i++) {
                if(floors[i] > 0 && (destination_floor == -1 || abs(i - current_floor) < abs(destination_floor - current_floor))) {
                    destination_floor = i;
                }
            }
            
            if(destination_floor == -1) {
                elevators[elevator_num] = 0;
                pthread_mutex_unlock(&mutex);
                continue;
            }
            
            riding_elevator(elevator_num, current_floor, destination_floor); 
            floors[destination_floor]--;  
        }

        pthread_mutex_unlock(&mutex);

        current_floor = (current_floor + get_elevator_direction(elevator_num)) % NUM_FLOORS;
        if(current_floor < 0) {
            current_floor += NUM_FLOORS;
        }

        usleep(100000);  
    }

    return NULL;
}


void riding_elevator(int elevator_num, int current_floor, int destination_floor)
{  
    pthread_mutex_lock(&mutex);
    elevators[elevator_num] = 0;
    elevator_floor[elevator_num] = current_floor;
    pthread_mutex_unlock(&mutex);

    int i;
    while (current_floor != destination_floor) {
        printf("Elevator %d is currently at floor %d\n", elevator_num, current_floor);
        current_floor = (current_floor + get_elevator_direction(elevator_num)) % NUM_FLOORS;
        if(current_floor < 0) {
            current_floor += NUM_FLOORS;
        }
        usleep(100000);
    }

    printf("Elevator %d has arrived at floor %d\n", elevator_num, destination_floor);

    pthread_mutex_lock(&mutex);
    elevators[elevator_num] = 1;
    floors[destination_floor]++; 
    pthread_mutex_unlock(&mutex);
}


int get_elevator_direction(int elevator_num)
{
    if(floors[elevator_floor[elevator_num]] > 0) {
        return 0;
    }

    int i, direction;
    for(i = 0; i < NUM_FLOORS; i++) {
        if(floors[i]) {
            direction = (i - elevator_floor[elevator_num]) / abs(i - elevator_floor[elevator_num]);
            if(direction == elevator_direction[elevator_num]) {
                return elevator_direction[elevator_num];
            }
        }
    }

    elevator_direction[elevator_num] *= -1;
    return elevator_direction[elevator_num];
}