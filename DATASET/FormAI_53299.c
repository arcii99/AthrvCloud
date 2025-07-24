//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_FLOORS 10   //Maximum number of floors in the building
#define MAX_ELEVATORS 4 //Maximum number of elevators in the building

int floors[MAX_FLOORS];     //An array to keep track of the number of people at each floor
int current_floor[MAX_ELEVATORS];    //An array to keep track of the current floor of each elevator
bool direction[MAX_ELEVATORS];  //An array to keep track of the direction of each elevator
bool stop[MAX_ELEVATORS][MAX_FLOORS];    //A 2D array to keep track of the floors each elevator needs to stop at
pthread_mutex_t mutex_elevator[MAX_ELEVATORS]; //An array of mutex locks for each elevator

void *elevator(void *arg) { //Function to simulate each elevator
    int *elevator_id = arg;
    bool elevator_direction = true; //True if elevator is going up, false if going down
    int elevator_floor = 0; //Start at first floor
    int i;

    for(i=0;i<MAX_FLOORS;i++) stop[*elevator_id][i] = false;    //Initialize all stops to false

    while(true) {
        pthread_mutex_lock(&mutex_elevator[*elevator_id]); //Lock the elevator so someone can't request it while it's moving

        //Check if there are any stops for the elevator in its current direction
        bool found_stop = false;
        for(i=elevator_floor+1;i<MAX_FLOORS;i++) {
            if((direction[*elevator_id] && floors[i]>0 && !stop[*elevator_id][i]) || (!direction[*elevator_id] && floors[MAX_FLOORS-i-1]>0 && !stop[*elevator_id][MAX_FLOORS-i-1])) {
                found_stop = true;
                break;
            }
        }

        if(!found_stop) { //If there are no stops in this direction, then switch direction and check again
            elevator_direction = !elevator_direction;
            for(i=0;i<MAX_FLOORS;i++) {
                if((elevator_direction && floors[i]>0 && !stop[*elevator_id][i]) || (!elevator_direction && floors[MAX_FLOORS-i-1]>0 && !stop[*elevator_id][MAX_FLOORS-i-1])) {
                    found_stop = true;
                    break;
                }
            }

            if(!found_stop) { //If there are no stops in the new direction, then the elevator is idle
                printf("Elevator %d is idle.\n", *elevator_id);
                pthread_mutex_unlock(&mutex_elevator[*elevator_id]); //Release the lock so someone can request the elevator
                continue;
            }
        }

        printf("Elevator %d is moving %s.\n", *elevator_id, elevator_direction?"up":"down"); //Print the direction of the elevator

        while(true) { //Loop through each floor as long as there are stops in this direction
            if(direction[*elevator_id]) {
                elevator_floor++;
            } else {
                elevator_floor--;
            }

            usleep(500000); //Add sleep time to simulate moving

            if(stop[*elevator_id][elevator_floor]) { //Check if this is one of the stops
                stop[*elevator_id][elevator_floor] = false; //Clear the stop for this floor
                printf("Elevator %d stopped at floor %d.\n", *elevator_id, elevator_floor+1);

                if(direction[*elevator_id] && floors[elevator_floor]>0) floors[elevator_floor]--; //Decrement the number of people waiting to go up
                if(!direction[*elevator_id] && floors[MAX_FLOORS-elevator_floor-1]>0) floors[MAX_FLOORS-elevator_floor-1]--; //Decrement the number of people waiting to go down

                if(floors[elevator_floor]==0 && floors[MAX_FLOORS-elevator_floor-1]==0) { //If there is no one waiting on this floor, then clear this stop for all elevators
                    for(i=0;i<MAX_ELEVATORS;i++) stop[i][elevator_floor] = false;
                }

                usleep(2000000); //Add sleep time for people to get on/off
            }

            bool found_stop = false;
            for(i=elevator_floor+1;i<MAX_FLOORS;i++) { //Check if there are any more stops in this direction
                if((direction[*elevator_id] && floors[i]>0 && !stop[*elevator_id][i]) || (!direction[*elevator_id] && floors[MAX_FLOORS-i-1]>0 && !stop[*elevator_id][MAX_FLOORS-i-1])) {
                    found_stop = true;
                    break;
                }
            }

            if(!found_stop) { //If there are no more stops in this direction, then stop and switch direction
                elevator_direction = !elevator_direction;
                printf("Elevator %d is now moving %s.\n", *elevator_id, elevator_direction?"up":"down");
                usleep(1000000); //Add sleep time to simulate stopping and switching direction

                for(i=0;i<MAX_FLOORS;i++) {
                    if((elevator_direction && floors[i]>0 && !stop[*elevator_id][i]) || (!elevator_direction && floors[MAX_FLOORS-i-1]>0 && !stop[*elevator_id][MAX_FLOORS-i-1])) {
                        found_stop = true;
                        break;
                    }
                }

                if(!found_stop) { //If there are no more stops in the new direction, then the elevator is idle
                    printf("Elevator %d is now idle.\n", *elevator_id);
                    pthread_mutex_unlock(&mutex_elevator[*elevator_id]); //Release the lock so someone can request the elevator
                    break;
                }
            }
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL)); //Initialize random seed

    int i,j;

    for(i=0;i<MAX_FLOORS;i++) floors[i] = 0; //Initialize number of people at each floor to 0

    pthread_t elevator_threads[MAX_ELEVATORS];

    for(i=0;i<MAX_ELEVATORS;i++) {
        current_floor[i] = 0; //Initialize each elevator to the first floor
        direction[i] = true; //Initialize each elevator to go up
        pthread_mutex_init(&mutex_elevator[i], NULL); //Initialize the mutex lock for each elevator
        pthread_create(&elevator_threads[i], NULL, elevator, &i); //Create a thread for each elevator
    }

    while(true) {
        int floor_request = rand()%MAX_FLOORS; //Pick a random floor for someone to request
        bool direction_request = rand()%2; //Pick a random direction for the person to go

        floors[floor_request]++; //Increment the number of people waiting at this floor

        bool elevator_found = false;

        for(i=0;i<MAX_ELEVATORS;i++) { //Check if there is an idle elevator at this floor
            if(current_floor[i]==floor_request && !elevator_found && !pthread_mutex_trylock(&mutex_elevator[i])) {
                //If elevator is idle at this floor, then use it
                elevator_found = true;
                direction[i] = direction_request;
                stop[i][floor_request] = true;
            } else if((direction[i] && floor_request>current_floor[i]) || (!direction[i] && floor_request<current_floor[i])) {
                //If elevator is moving in the direction of the requested floor, then use it
                stop[i][floor_request] = true;
                elevator_found = true;
            }

            if(elevator_found) { //If an elevator was found, then break out of the loop
                break;
            }
        }

        if(!elevator_found) { //If no elevator was found, then try again in a few seconds
            usleep(5000000);
            continue;
        }

        printf("Person requested elevator at floor %d going %s.\n", floor_request+1, direction_request?"up":"down");

        pthread_mutex_unlock(&mutex_elevator[i]); //Release the lock so the elevator can move
    }

    for(i=0;i<MAX_ELEVATORS;i++) {
        pthread_join(elevator_threads[i], NULL); //Wait for each elevator thread to finish
    }

    for(i=0;i<MAX_ELEVATORS;i++) {
        pthread_mutex_destroy(&mutex_elevator[i]); //Destroy each mutex lock
    }

    return 0;
}