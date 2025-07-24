//FormAI DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>

//Declare variables for movement control
int forward = 0;
int backward = 0;
int turn_left = 0;
int turn_right = 0;

//Function to control movement of robot
void move_robot()
{
    printf("Moving robot...\n");
    if (forward)
    {
        printf("Forward\n");
        //Code to move robot forward
    }
    else if (backward)
    {
        printf("Backward\n");
        //Code to move robot backward
    }
    else if (turn_left)
    {
        printf("Turn left\n");
        //Code to turn robot left
    }
    else if (turn_right)
    {
        printf("Turn right\n");
        //Code to turn robot right
    }
    else
    {
        printf("No movement\n");
    }
}

int main()
{
    //Sample code for getting input from user
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == 'w')
        {
            forward = 1;
            backward = 0;
            turn_left = 0;
            turn_right = 0;
        }
        else if (c == 's')
        {
            forward = 0;
            backward = 1;
            turn_left = 0;
            turn_right = 0;
        }
        else if (c == 'a')
        {
            forward = 0;
            backward = 0;
            turn_left = 1;
            turn_right = 0;
        }
        else if (c == 'd')
        {
            forward = 0;
            backward = 0;
            turn_left = 0;
            turn_right = 1;
        }
        else if (c == 'q')
        {
            printf("Exiting program...\n");
            return 0;
        }
        move_robot();
    }
    return 0;
}