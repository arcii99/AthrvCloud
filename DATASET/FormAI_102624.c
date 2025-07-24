//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define FLOORS 10 //number of floors in the building
#define ELEVATORS 4 //number of elevators in the building

enum Direction {UP, DOWN};
int current_floor[ELEVATORS] = {1,1,1,1}; //current floor of each elevator
enum Direction direction[ELEVATORS] = {UP,UP,UP,UP}; //initial direction of each elevator
int passengers[ELEVATORS][FLOORS] = {0}; //number of passengers in each elevator on each floor
int destination[ELEVATORS][FLOORS] = {0}; //destination floor of each passenger in each elevator on each floor

void *elevator(void *arg){
    int id = (int)arg; //elevator number
    while(1){
        sleep(1); //wait for passengers to get on and off
        //check for passengers getting off at current floor
        for(int i=0;i<FLOORS;i++){
            if(destination[id][i] && current_floor[id] == i+1){
                printf("Elevator %d: Passenger(s) exiting at floor %d\n", id+1, i+1);
                passengers[id][i] = 0;
                destination[id][i] = 0;
            }
        }
        //check for passengers getting on in current direction
        int floor_stop = 0;
        for(int i=0;i<FLOORS;i++){
            if(passengers[id][i] && direction[id] == UP && i+1 > current_floor[id]){
                floor_stop = i+1;
                break;
            }
            if(passengers[id][i] && direction[id] == DOWN && i+1 < current_floor[id]){
                floor_stop = i+1;
                break;
            }
        }
        if(floor_stop){
            printf("Elevator %d: Stopping to pick up passengers at floor %d\n", id+1, floor_stop);
            for(int i=0;i<ELEVATORS;i++){
                passengers[id][floor_stop-1] += passengers[i][floor_stop-1];
                passengers[i][floor_stop-1] = 0;
            }
        }
        //check for passengers getting on in opposite direction
        if(!floor_stop){
            for(int i=0;i<FLOORS;i++){
                if(passengers[id][i] && direction[id] == UP && i+1 < current_floor[id]){
                    floor_stop = i+1;
                    direction[id] = DOWN;
                    break;
                }
                if(passengers[id][i] && direction[id] == DOWN && i+1 > current_floor[id]){
                    floor_stop = i+1;
                    direction[id] = UP;
                    break;
                }
            }
            if(floor_stop){
                printf("Elevator %d: Stopping to pick up passengers going in opposite direction at floor %d\n", id+1, floor_stop);
                for(int i=0;i<ELEVATORS;i++){
                    passengers[id][floor_stop-1] += passengers[i][floor_stop-1];
                    passengers[i][floor_stop-1] = 0;
                }
            }
        }
        //check for passengers in opposite direction with no current direction
        if(!floor_stop){
            for(int i=0;i<FLOORS;i++){
                if(passengers[id][i] && destination[id][i] < current_floor[id]) {
                    floor_stop = i+1;
                    break;
                }
                if(passengers[id][i] && destination[id][i] > current_floor[id]) {
                    floor_stop = i+1;
                    break;
                }
            }
            if(floor_stop){
                printf("Elevator %d: Stopping to pick up passengers with no current direction at floor %d\n", id+1, floor_stop);
                for(int i=0;i<ELEVATORS;i++){
                    passengers[id][floor_stop-1] += passengers[i][floor_stop-1];
                    passengers[i][floor_stop-1] = 0;
                }
                direction[id] = destination[id][floor_stop-1] > current_floor[id] ? UP : DOWN;
            }
        }
        //randomly pick a destination for each passenger on each floor
        for(int i=0;i<FLOORS;i++){
            if(passengers[id][i] && !destination[id][i]){
                destination[id][i] = rand() % FLOORS + 1;
            }
        }
        //move elevator in current direction
        if(direction[id] == UP && current_floor[id] < FLOORS){
            current_floor[id]++;
        }
        else if(direction[id] == DOWN && current_floor[id] > 1){
            current_floor[id]--;
        }
        printf("Elevator %d: Currently on floor %d\n", id+1, current_floor[id]);
    }   
}

int main(){
    srand(time(NULL));
    pthread_t threads[ELEVATORS];
    //create elevator threads
    for(int i=0;i<ELEVATORS;i++){
        pthread_create(&threads[i], NULL, elevator, (void *)i);
    }
    //create passengers
    while(1){
        sleep(rand() % 5 + 1); //random delay to simulate arrival of passengers
        int floor = rand() % FLOORS; //random starting floor for passengers
        int num_passengers = rand() % 5 + 1; //random number of passengers
        int elevator = -1; //preferred elevator
        int min_distance = FLOORS+1; //minimum distance to elevator
        for(int i=0;i<ELEVATORS;i++){
            int distance = abs(floor+1-current_floor[i]);
            if(distance<min_distance && passengers[i][floor] < 10){
                elevator = i;
                min_distance = distance;
            }
        }
        if(elevator == -1){
            printf("No available elevators for passengers on floor %d\n", floor+1);
        }
        else{
            printf("%d passengers on floor %d waiting for elevator %d\n", num_passengers, floor+1, elevator+1);
            passengers[elevator][floor] += num_passengers;
        }
    }
    return 0;
}