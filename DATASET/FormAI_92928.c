//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int droneX = 0, droneY = 0;
    int destinationX, destinationY;
    int batteryLife = 100;
    srand(time(NULL));
    
    printf("Welcome to the C Drone Remote Control system!\n");
    
    //randomly generate the destination coordinates
    destinationX = rand() % 100 + 1;
    destinationY = rand() % 100 + 1;
    
    printf("Your mission is to guide the drone to the destination coordinates (%d,%d).\n", destinationX, destinationY);
    printf("To control the drone, use the following commands:\n");
    printf("w = move up\n");
    printf("a = move left\n");
    printf("s = move down\n");
    printf("d = move right\n");
    printf("b = check battery life\n");
    printf("q = quit program\n");
    
    //loop until the destination is reached or the user quits
    while (droneX != destinationX || droneY != destinationY) {
        printf("Current coordinates: (%d,%d)\n", droneX, droneY);
        printf("Enter a command: ");
        char command = getchar(); //get user input
        
        switch(command) {
            case 'w':
                droneY++;
                batteryLife--;
                break;
            case 'a':
                droneX--;
                batteryLife--;
                break;
            case 's':
                droneY--;
                batteryLife--;
                break;
            case 'd':
                droneX++;
                batteryLife--;
                break;
            case 'b':
                printf("Battery life: %d%%\n", batteryLife);
                break;
            case 'q':
                printf("Program Terminated.\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }
        
        //check if drone is out of battery
        if (batteryLife == 0) {
            printf("Drone is out of battery and crashed.\n");
            exit(0);
        }
        
        //check if the drone went out of the map
        if (droneX < 0 || droneY < 0 || droneX > 100 || droneY > 100) {
            printf("Drone went out of map and crashed.\n");
            exit(0);
        }
    }
    
    printf("Congratulations, you guided the drone to the destination coordinates (%d,%d)!\n", destinationX, destinationY);
    return 0;
}