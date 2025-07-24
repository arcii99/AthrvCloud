//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SPEED 1
#define MAX_SPEED 10
#define MIN_DISTANCE 5
#define MAX_DISTANCE 50
#define MIN_TURN 1
#define MAX_TURN 10

int main() {
    srand(time(NULL)); //initialize rand
    
    int speed = 0;
    int distance = 0;
    int turn = 0;
    char direction = 'F';
    int total_distance = 0;
    int total_turn = 0;
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n\n");
    
    while (total_distance < MAX_DISTANCE) {
        //generate random speed between MIN_SPEED and MAX_SPEED
        speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        printf("Speed: %d\n", speed);
        
        //generate random distance between MIN_DISTANCE and MAX_DISTANCE
        distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
        printf("Distance: %d\n", distance);
        
        //generate random turn between MIN_TURN and MAX_TURN
        turn = rand() % (MAX_TURN - MIN_TURN + 1) + MIN_TURN;
        printf("Turn: %d\n", turn);
        
        //generate random direction (F - forward, B - backward)
        direction = rand() % 2 == 0 ? 'F' : 'B';
        printf("Direction: %c\n\n", direction);
        
        if (direction == 'B') {
            total_distance -= distance;
            total_turn -= turn;
        } else {
            total_distance += distance;
            total_turn += turn;
        }
    }
    
    printf("Simulation completed!\n");
    printf("Total distance traveled: %d\n", total_distance);
    printf("Total turns made: %d\n", total_turn);
    
    return 0;
}