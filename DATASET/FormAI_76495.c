//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initializes random seed
    
    int speed = rand() % 101; // generates random speed between 0 and 100
    
    printf("Welcome to the Internet Speed Test Application! Today's speed is %d Mbps.\n", speed);
    printf("Please wait while we test your connection...\n\n");
    
    // simulate testing connection speed
    int progress = 0;
    while (progress < 100) {
        int time = rand() % 501; // generates random time between 0 and 500 milliseconds
        progress += rand() % 21; // generates random progress between 0 and 20 percent
        printf("Testing in progress: %d%%\n", progress);
        usleep(time * 1000); // sleeps for generated time
    }
    
    // display results
    printf("\nTest complete! Your speed is %d Mbps.\n", speed);
    if (speed < 10) {
        printf("Sorry, your connection is too slow for our post-apocalyptic world. Good luck out there.\n");
    } else if (speed < 50) {
        printf("Your connection is decent enough for basic communication and information gathering. Stay safe.\n");
    } else if (speed < 80) {
        printf("Not bad! You can stream and do some light browsing with that speed. Keep scavenging.\n");
    } else {
        printf("Impressive! With that speed, you can do almost anything online. Hope you're using it wisely.\n");
    }
    
    return 0;
}