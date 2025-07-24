//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random internet speed between 0-100 Mbps
int generateSpeed(){
    return rand() % 101;
}

// Function to calculate download time
float calculateDownloadTime(int speed, int size){
    return (float)size / ((float)speed / 8);
}

int main(){
    // Setting up seed for random number generator
    srand(time(NULL));

    // Declaring variables
    int speed, size;
    float downloadTime;

    // Printing the welcome message
    printf("Welcome to the Internet Speed Test!\n\n");

    // Asking user for input
    printf("Please enter the size of the file in megabytes: ");
    scanf("%d", &size);

    // Generating internet speed
    speed = generateSpeed();

    // Printing the internet speed
    printf("Your current internet speed is: %d Mbps\n\n", speed);

    // Calculating download time
    downloadTime = calculateDownloadTime(speed, size);

    // Printing download time
    printf("Your file will take approximately %.2f seconds to download.\n", downloadTime);

    return 0;
}