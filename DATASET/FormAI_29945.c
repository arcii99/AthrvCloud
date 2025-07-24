//FormAI DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>

int main() {
    int xCoordinate = 0;
    int yCoordinate = 0;
    int speed = 1;
    char direction = 'E';
    int distance = 10;
    
    printf("Current position: (%d, %d)\n", xCoordinate, yCoordinate);
    printf("Current direction: %c\n", direction);
    
    // move forward
    if (direction == 'E') {
        xCoordinate += distance * speed;
    } else if (direction == 'W') {
        xCoordinate -= distance * speed;
    } else if (direction == 'N') {
        yCoordinate += distance * speed;
    } else if (direction == 'S') {
        yCoordinate -= distance * speed;
    }
    
    printf("Moved forward %d units\n", distance);
    printf("New position: (%d, %d)\n", xCoordinate, yCoordinate);
    
    // turn left
    if (direction == 'E') {
        direction = 'N';
    } else if (direction == 'W') {
        direction = 'S';
    } else if (direction == 'N') {
        direction = 'W';
    } else if (direction == 'S') {
        direction = 'E';
    }
    
    printf("Turned left. New direction: %c\n", direction);
    
    // move backward
    if (direction == 'E') {
        xCoordinate -= distance * speed;
    } else if (direction == 'W') {
        xCoordinate += distance * speed;
    } else if (direction == 'N') {
        yCoordinate -= distance * speed;
    } else if (direction == 'S') {
        yCoordinate += distance * speed;
    }
    
    printf("Moved backward %d units\n", distance);
    printf("New position: (%d, %d)\n", xCoordinate, yCoordinate);
    
    return 0;
}