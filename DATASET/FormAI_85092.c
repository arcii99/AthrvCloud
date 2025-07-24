//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
// This program measures the internet speed of the user and displays the results
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between given range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // seed for random generator
    srand(time(NULL));

    // generate random internet speed between 1-100 Mbps
    int internetSpeed = generateRandomNumber(1, 100);

    printf("Welcome to the Internet Speed Test Application\n");
    printf("We are checking your internet speed...\n");
    printf("Your internet speed is %d Mbps\n\n", internetSpeed);

    // display appropriate message based on internet speed
    if (internetSpeed < 10) {
        printf("Your internet speed is very slow. Please contact your ISP to resolve this issue.\n");
    } else if (internetSpeed < 25) {
        printf("Your internet speed is average. You can perform all regular tasks with ease.\n");
    } else if (internetSpeed < 50) {
        printf("Your internet speed is above average. You can stream videos and download files with ease.\n");
    } else {
        printf("Your internet speed is excellent. You can stream HD videos and play online games with ease.\n");
    }

    return 0;
}