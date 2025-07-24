//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10
#define ELEVATORS 3

bool floors[FLOORS][ELEVATORS];

void print_state(){
    printf("Elevator\t");
    for(int i=0;i<ELEVATORS;i++){
        printf("%d\t",i+1);
    }
    printf("\n");
    for(int i=FLOORS-1;i>=0;i--){
        printf("Floor %d\t",i+1);
        for(int j=0;j<ELEVATORS;j++){
            if(floors[i][j]){
                printf("O\t");
            }else{
                printf("-\t");
            }
        }
        printf("\n");
    }
}

void move_up(int elevator){
    for(int i=FLOORS-2;i>=0;i--){
        if(floors[i][elevator]){
            floors[i+1][elevator] = true;
            floors[i][elevator] = false;
        }
    }
}

void move_down(int elevator){
    for(int i=1;i<FLOORS;i++){
        if(floors[i][elevator]){
            floors[i-1][elevator] = true;
            floors[i][elevator] = false;
        }
    }
}

int main(){
    for(int i=0;i<ELEVATORS;i++){
        floors[0][i] = true; // Start with all elevators on first floor
    }

    // Print initial state
    printf("Initial State:\n");
    print_state();

    // Test moving elevator 1 up and elevator 2 down
    move_up(0);
    move_down(1);
    printf("State after moving elevator 1 up and elevator 2 down:\n");
    print_state();

    return 0;
}