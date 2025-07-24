//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

#define FLOOR_COUNT 10 //Total number of floors including the ground floor
#define ELEVATOR_CAPACITY 8 //Maximum passenger capacity of the elevator

int elevator[FLOOR_COUNT]; //Array representing the elevator, floors 1 to 10


//Function to simulate the elevator moving up
void moveUp(int curFloor) {
    printf("Elevator moving up from floor %d\n", curFloor);
    for(int i = curFloor; i < FLOOR_COUNT; i++) {
        printf("Now at floor %d\n", i+1);
        elevator[i] = 0; //Clear the floor once the elevator leaves
    }
}

//Function to simulate the elevator moving down
void moveDown(int curFloor) {
    printf("Elevator moving down from floor %d\n", curFloor);
    for(int i = curFloor; i >= 0; i--) {
        printf("Now at floor %d\n", i);
        elevator[i] = 0; //Clear the floor once the elevator leaves
    }
}

int main() {
    int curFloor = 0; //Set initial floor to ground floor
    int passengers = 0; //No passengers initially

    //Main elevator loop
    while(true) {
        printf("Elevator is currently on floor %d\n", curFloor);
        printf("There are currently %d passengers in the elevator\n", passengers);

        //Check if there are any passengers waiting on the current floor
        if (elevator[curFloor] != 0) {
            printf("%d passengers entered the elevator on floor %d\n", elevator[curFloor], curFloor);
            passengers += elevator[curFloor];
            elevator[curFloor] = 0; //Clear the floor of passengers
        }

        //Check if the elevator is at maximum capacity
        if (passengers >= ELEVATOR_CAPACITY) {
            printf("Elevator is at maximum capacity\n");
        } else {
            
            //Simulate passengers entering the elevator
            int availableSpace = ELEVATOR_CAPACITY - passengers;
            for(int i = curFloor; i < FLOOR_COUNT; i++) {
                if (elevator[i] <= availableSpace) {
                    passengers += elevator[i];
                    availableSpace -= elevator[i];
                    elevator[i] = 0; //Clear the floor of passengers
                }
                if (passengers == ELEVATOR_CAPACITY) {
                    break; //Stop picking up passengers when maximum capacity reached
                }
            }
        }

        //Move the elevator to the next floor
        if(curFloor == FLOOR_COUNT-1) {
            //If the elevator is at the top floor, move down
            moveDown(curFloor);
            curFloor--;
        } else if(curFloor == 0) {
            //If the elevator is at the ground floor, move up
            moveUp(curFloor);
            curFloor++;
        } else {
            //Otherwise, randomly decide whether to move up or down
            int direction = rand() % 2;
            if(direction) {
                moveUp(curFloor);
                curFloor++;
            } else {
                moveDown(curFloor);
                curFloor--;
            }
        }
    }
    return 0;
}