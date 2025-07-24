//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));   //seed for random function
    int speed, direction, choice;
    printf("Welcome to Remote Controlled Vehicle Simulation\n");
    printf("Please choose the type of vehicle: \n1.Car\n2.Truck\n3.Helicopter\n4.Boat\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Car selected\n");
            break;
        case 2:
            printf("Truck selected\n");
            break;
        case 3:
            printf("Helicopter selected\n");
            break;
        case 4:
            printf("Boat selected\n");
            break;
        default:
            printf("Invalid choice, exiting\n");
            return 0;
    }
    //generate random speed and direction
    speed = rand() % 51;
    direction = rand() % 361;
    printf("Vehicle is moving at a speed of %d mph in the direction of %d degrees.\n", speed, direction);
    printf("Please enter the desired speed (0-50 mph): ");
    scanf("%d",&speed);
    printf("Please enter the desired direction (0-360 degrees): ");
    scanf("%d",&direction);
    printf("Sending signal to vehicle...\n");
    printf("Vehicle now moving at a speed of %d mph in the direction of %d degrees.\n", speed, direction);
    printf("End of Simulation\n");
}