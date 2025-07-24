//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function definition for internet speed test
int internetSpeedTest() {
    int downloadSpeed, uploadSpeed;
    srand(time(NULL)); // initialize random seed

    // generate download speed between 10 and 100 Mbps
    downloadSpeed = (rand() % (100 - 10 + 1)) + 10;

    // generate upload speed between 5 and 50 Mbps
    uploadSpeed = (rand() % (50 - 5 + 1)) + 5;

    printf("Your Download Speed is: %d Mbps\n", downloadSpeed);
    printf("Your Upload Speed is: %d Mbps\n", uploadSpeed);

    return 0;
}

int main() {
    char choice;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Would you like to begin the test? (Y/N)");

    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        // call the internet speed test function
        internetSpeedTest();
    } else if (choice == 'N' || choice == 'n') {
        printf("Okay, maybe next time.\n");
    } else {
        printf("Invalid Input. Please try again.\n");
    }

    return 0;
}