//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate remote control vehicle movement
void simulateRCVehicle(int duration){
    int speed, turn;
    printf("Starting remote control vehicle simulation for %d seconds...\n", duration);
    time_t start = time(NULL);

    while(difftime(time(NULL), start) < duration){
        //Randomly generate speed and turn values between -10 and 10
        speed = rand() % 21 - 10;
        turn = rand() % 21 - 10;

        //Simulate movement
        printf("Speed: %d, Turn: %d\n", speed, turn);

        //Pause for 1 second
        sleep(1);
    }

    printf("Remote control vehicle simulation complete.\n");
}

int main(){
    int duration;

    //Get simulation duration from user
    printf("Enter duration of remote control vehicle simulation (in seconds): ");
    scanf("%d", &duration);
    
    //Seed random number generator
    srand(time(NULL));

    //Simulate vehicle movement
    simulateRCVehicle(duration);

    return 0;
}