//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFF_SIZE 1024
#define MAX_SPEED 1000

// function that generates a random internet speed test result
int speedTest() {
    int speed = rand() % MAX_SPEED + 1;
    return speed;
}

int main() {
    // creating a buffer to store user input
    char buffer[BUFF_SIZE];

    // greeting the user
    printf("Welcome to the internet speed test!\n\n");

    // explaining the purpose of the program
    printf("This program will generate a random internet speed test result,\n");
    printf("and display it to you in the following format:\n\n");

    // explaining the output format
    printf("Download Speed: XX Mbps\n");
    printf("Upload Speed: XX Mbps\n");
    printf("Ping: XX ms\n\n");

    // asking the user if they want to proceed with the test
    printf("Do you want to proceed with the test? (y/n) ");
    fgets(buffer, BUFF_SIZE, stdin);

    // checking if the user wants to proceed with the test
    if (strncmp(buffer, "y", 1) == 0) {
        // generating the speed test results
        int downloadSpeed = speedTest();
        int uploadSpeed = speedTest();
        int ping = rand() % 100 + 1;

        // printing the results
        printf("Download Speed: %d Mbps\n", downloadSpeed);
        printf("Upload Speed: %d Mbps\n", uploadSpeed);
        printf("Ping: %d ms\n", ping);

        // thanking the user for participating in the test
        printf("\nThank you for taking the internet speed test!\n");
    } else {
        // informing the user that the test will not be conducted
        printf("Okay, the internet speed test will not be conducted.\n");
    }

    return 0;
}