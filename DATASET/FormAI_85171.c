//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining simple data structures for robot position and direction
struct position {
    int x;
    int y;
};

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int main() {
    // Initializing variables and setting robot to random position and direction
    srand(time(NULL));
    int moves = 50;
    struct position robot;
    robot.x = rand() % 10;
    robot.y = rand() % 10;
    enum direction robot_direction = rand() % 4;
    
    printf("Starting robot at position (%d, %d)\n", robot.x, robot.y);
    
    // Looping through robot moves and printing out its current position and direction
    for (int i = 0; i < moves; i++) {
        switch(robot_direction) {
            case UP:
                robot.y--;
                printf("Moved up to position (%d, %d)\n", robot.x, robot.y);
                break;
            case DOWN:
                robot.y++;
                printf("Moved down to position (%d, %d)\n", robot.x, robot.y);
                break;
            case LEFT:
                robot.x--;
                printf("Moved left to position (%d, %d)\n", robot.x, robot.y);
                break;
            case RIGHT:
                robot.x++;
                printf("Moved right to position (%d, %d)\n", robot.x, robot.y);
                break;
        }
        
        // Checking if the robot has hit a wall and switching its direction if so
        if (robot.x < 0 || robot.x > 9 || robot.y < 0 || robot.y > 9) {
            switch(robot_direction) {
                case UP:
                    robot_direction = DOWN;
                    break;
                case DOWN:
                    robot_direction = UP;
                    break;
                case LEFT:
                    robot_direction = RIGHT;
                    break;
                case RIGHT:
                    robot_direction = LEFT;
                    break;
            }
        } else {
            // If the robot has not hit a wall, randomly changing its direction
            robot_direction = rand() % 4;
        }
    }
    
    printf("Final position: (%d, %d)\n", robot.x, robot.y);
    
    return 0;
}