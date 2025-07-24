//FormAI DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

//function to move forward
void moveForward(int steps){
    printf("Moving Forward %d steps\n",steps);
}

//function to move backward
void moveBackward(int steps){
    printf("Moving Backward %d steps\n",steps);
}

//function to turn left
void turnLeft(int degrees){
    printf("Turning Left %d degrees\n",degrees);
}

//function to turn right
void turnRight(int degrees){
    printf("Turning Right %d degrees\n",degrees);
}

//main function
int main(){
    int choice,steps,degrees;
    printf("Welcome to Robot Movement Control System\n");

    //menu for the user
    while(1){
        printf("\nChoose an option:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            //moving forward
            case 1:
                printf("Enter number of steps to move: ");
                scanf("%d",&steps);
                moveForward(steps);
                break;

            //moving backward
            case 2:
                printf("Enter number of steps to move: ");
                scanf("%d",&steps);
                moveBackward(steps);
                break;

            //turning left
            case 3:
                printf("Enter number of degrees to turn: ");
                scanf("%d",&degrees);
                turnLeft(degrees);
                break;

            //turning right
            case 4:
                printf("Enter number of degrees to turn: ");
                scanf("%d",&degrees);
                turnRight(degrees);
                break;

            //exiting the program
            case 5:
                printf("Exiting Robot Movement Control System\n");
                exit(0);

            //invalid choice by the user
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}