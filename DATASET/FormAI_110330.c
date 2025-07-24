//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOT_MOVEMENTS 10
#define MAX_X_COORDINATE 100
#define MAX_Y_COORDINATE 100

int x_coordinate = 0; // Starting X coordinate of the robot
int y_coordinate = 0; // Starting Y coordinate of the robot

void checkCoordinates(int x, int y);
void moveRobot(int movements);

int main()
{
    srand(time(NULL));
    int robot_movements = rand() % MAX_ROBOT_MOVEMENTS;
    printf("Robot is programmed to move %d times\n\n", robot_movements);
    moveRobot(robot_movements);
    return 0;
}

void checkCoordinates(int x, int y)
{
    if(x < 0 || x > MAX_X_COORDINATE || y < 0 || y > MAX_Y_COORDINATE)
    {
        printf("Error: Robot out of bounds.\n\n");
        exit(0);
    }
    if(x == MAX_X_COORDINATE && y == MAX_Y_COORDINATE)
    {
        printf("Warning: Robot has reached the edge of the grid.\n\n");
    }
}

void moveRobot(int movements)
{
    printf("Robot is starting the movement sequence:\n\n");

    for(int i = 0; i < movements; i++)
    {
        int random_direction = rand() % 4;

        switch(random_direction)
        {
           case 0:
                printf("Move to the left\n");
                x_coordinate--;
                checkCoordinates(x_coordinate, y_coordinate);
                break;
           case 1:
                printf("Move to the right\n");
                x_coordinate++;
                checkCoordinates(x_coordinate, y_coordinate);
                break;
           case 2:
                printf("Move up\n");
                y_coordinate--;
                checkCoordinates(x_coordinate, y_coordinate);
                break;
           case 3:
                printf("Move down\n");
                y_coordinate++;
                checkCoordinates(x_coordinate, y_coordinate);
                break;
           default:
                printf("Error: Invalid direction\n");
                exit(1);
        }
    }
    printf("\nRobot has successfully completed the sequence.\n");
}