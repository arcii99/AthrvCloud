//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_SPEED 100 //in mbps
#define MIN_SPEED 1 //in mbps

int main() {
    srand(time(NULL)); //initialize random number generator with system time
    int speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED; //generate random speed between MAX_SPEED and MIN_SPEED
    printf("Your internet speed is currently %d mbps\n\n", speed);
    printf("Testing internet speed...\n\n");
    sleep(5); //simulate internet speed test delay of 5 seconds
    printf("Test complete! Here are your results:\n\n");
    printf("Download Speed: %d mbps\n", speed);
    printf("Upload Speed: %d mbps\n", speed / 2);
    printf("Ping: %d ms\n\n", rand() % 100 + 1); //generate random ping between 1ms and 100ms
    printf("Would you like to run another speed test? (y/n): ");
    char input[2];
    scanf("%s", input); //get user input
    if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
        printf("\n"); //add blank line for readability
        main(); //restart program
    } else {
        printf("Thank you for using our internet speed test application!\n");
    }
    return 0;
}