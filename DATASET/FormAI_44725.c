//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>

// Function to calculate the absolute value of an integer
int abs(int num) {
    if (num < 0) {
        return -num;
    } else {
        return num;
    }
}

// Function to simulate the elevator movement
void moveElevator(int floor, int dest) {
    // Calculate the difference between the destination floor and current floor
    int diff = abs(dest - floor);
    
    printf("Elevator doors closing...\n");
    
    // Move the elevator up or down depending on the destination floor
    if (dest > floor) {
        printf("Elevator moving up...\n");
    } else {
        printf("Elevator moving down...\n");
    }
    
    // Print each floor the elevator passes through
    for (int i = 0; i <= diff; i++) {
        printf("Floor %d\n", (floor + i));
    }
    
    printf("Elevator doors opening...\n");
}

int main() {
    // Assume the elevator starts on the first floor
    int currentFloor = 1;
    
    // Simulate passengers requesting the elevator on three different floors
    int floor1 = 5;
    int floor2 = 2;
    int floor3 = 10;
    
    // Simulate the elevator moving to each floor
    moveElevator(currentFloor, floor1);
    currentFloor = floor1;
    
    moveElevator(currentFloor, floor2);
    currentFloor = floor2;
    
    moveElevator(currentFloor, floor3);
    currentFloor = floor3;
    
    // Simulate a passenger requesting to go to the first floor
    int finalDest = 1;
    moveElevator(currentFloor, finalDest);
    currentFloor = finalDest;
    
    printf("All passengers have reached their destination.\n");
    
    return 0;
}