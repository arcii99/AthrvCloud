//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main(){
    //Welcome message
    printf("Welcome to CyberNav GPS Navigation System\n");
    printf("Initializing system... Please wait...\n");

    //Generating random destination coordinates
    int destination_x = rand() % 100;
    int destination_y = rand() % 100;

    //Initializing current location coordinates
    int current_x = 50;
    int current_y = 50;

    //Calculating distance between current location and destination
    float distance = sqrt(pow(destination_x - current_x, 2) + pow(destination_y - current_y, 2));

    //Simulating navigation
    while(distance >= 5){
        printf("Current location: (%d,%d)\n", current_x, current_y);
        printf("Destination: (%d,%d)\n", destination_x, destination_y);
        printf("Distance remaining: %.2f units\n", distance);
        printf("Enter direction to move: (North/N), (South/S), (East/E), (West/W)\n");

        //Reading user input
        char direction;
        scanf(" %c", &direction);

        //Updating current location based on user input
        switch (direction){
            case 'N':
                current_y++;
                break;
            case 'S':
                current_y--;
                break;
            case 'E':
                current_x++;
                break;
            case 'W':
                current_x--;
                break;
        }

        //Calculating new distance between current location and destination
        distance = sqrt(pow(destination_x - current_x, 2) + pow(destination_y - current_y, 2));

        //Checking if user has reached destination
        if(distance < 5){
            printf("You have arrived at your destination!\n");
        }
    }

    return 0;
}