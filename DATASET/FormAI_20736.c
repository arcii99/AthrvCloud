//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function declarations
void displayTrafficSignal(int,int,int);

int main() {
    int i;
    int signalTime[3]; // Store time for each signal
    int totalTime = 0; // Total time for signal cycle (Sum of all signal times)
    srand(time(0)); // Seed for random number generation

    // Generate random values for each signal time between 10 to 30 seconds
    for(i=0;i<3;i++) {
        signalTime[i] = rand()%21 + 10;
        totalTime += signalTime[i];
    }

    // Display initial signal state
    displayTrafficSignal(1,0,0);

    // Loop for signal cycle
    for(i=0;i<totalTime;i++) {
        if(i<signalTime[0]) { // Green signal time
            displayTrafficSignal(1,0,0); // Green light ON
        } else if(i>=signalTime[0] && i<signalTime[0]+signalTime[1]) { // Yellow signal time
            displayTrafficSignal(0,1,0); // Yellow light ON
        } else if(i>=signalTime[0]+signalTime[1] && i<totalTime) { // Red signal time
            displayTrafficSignal(0,0,1); // Red light ON
        }
        // Delay for 1 second
        printf("Time Remaining: %d seconds\n",totalTime-i);
        sleep(1);
    }
    return 0;
}

void displayTrafficSignal(int r,int y,int g) {
    // Clear console
    system("clear");

    // Print traffic signal
    printf("\n\n\n");
    printf("\t\t||===============||\n");
    printf("\t\t||   RED    |  %c  ||\n",r==1?'O':'X');
    printf("\t\t||=========|======||\n");
    printf("\t\t||  YELLOW |  %c  ||\n",y==1?'O':'X');
    printf("\t\t||=========|======||\n");
    printf("\t\t||  GREEN  |  %c  ||\n",g==1?'O':'X');
    printf("\t\t||===============||\n"); 
}