//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){

    int speed = 0;
    int direction = 0;
    printf("Welcome to Remote control car simulation!\n");
    printf("Please enter the speed (0-100): ");
    scanf("%d", &speed);
    printf("\nPlease enter the direction (0-360): ");
    scanf("%d", &direction);
    if(speed <= 0 || speed > 100)
    {
        printf("Invalid speed entered! Speed should be between 0-100.\n");
        exit(1);
    }
    if(direction < 0 || direction > 360)
    {
        printf("Invalid direction entered! Direction should be between 0-360.\n");
        exit(1);
    }
    printf("\nSimulating the car movement...\n");
    printf("The car is moving at a speed of %d with a direction of %d.\n", speed, direction);
    printf("Press 'x' to stop the simulation: \n");
    char stop;
  
    while(1)
    {
        scanf(" %c", &stop);
        if(stop == 'x')
        {
            printf("\nSimulation stopped!\n");
            break;
        }
    }

    return 0;
}