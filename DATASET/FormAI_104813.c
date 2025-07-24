//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FLOORS 10
#define ELEVATORS 3

int current_floor[ELEVATORS] = {0};
int next_floor[ELEVATORS] = {0};

void move_elevator(int elevator_id){
    int floor_gap = next_floor[elevator_id] - current_floor[elevator_id];
    if(floor_gap > 0){
        printf("Elevator %d moving up from floor %d to floor %d\n",elevator_id+1,current_floor[elevator_id],next_floor[elevator_id]);
    }else{
        printf("Elevator %d moving down from floor %d to floor %d\n",elevator_id+1,current_floor[elevator_id],next_floor[elevator_id]);
    }
    current_floor[elevator_id] = next_floor[elevator_id];
}

int find_elevator(){
    int min_index = -1;
    int min_distance = FLOORS+1;
    for(int i=0;i<ELEVATORS;i++){
        int dist = abs(current_floor[i] - next_floor[i]);
        if(dist < min_distance){
            min_index = i;
            min_distance = dist;
        }
    }
    return min_index;
} 

int main(){
    srand(time(NULL));
    printf("Elevator Simulation\n");

    //initialize elevator positions randomly
    for(int i=0;i<ELEVATORS;i++){
        current_floor[i] = rand() % FLOORS;
        printf("Elevator %d is at floor %d\n",i+1,current_floor[i]);
    }

    while(1){
        //generate a new floor request randomly
        int requested_floor = rand() % FLOORS;

        printf("Floor %d requested an elevator\n",requested_floor);

        //find the nearest elevator
        int elevator_id = find_elevator();
        next_floor[elevator_id] = requested_floor;

        //move the elevator
        move_elevator(elevator_id);
    }

    return 0;
}