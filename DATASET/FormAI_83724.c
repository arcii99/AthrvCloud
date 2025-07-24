//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    double speed[10];
    double avg = 0.0;
    srand(time(0));

    printf("Welcome to the Shape Shifting Speed Test Application\n\n");
    printf("This program will simulate 10 internet speed tests and calculate the average speed.\n\n");
    printf("Please wait while we run the tests...\n\n");
  
    // simulating internet speed tests
    for (i = 0; i < 10; i++) {
        speed[i] = (double) (rand() % 200) + 1.0; // generating speeds between 1 and 200 Mbps
        printf("Test #%d: %.2f Mbps\n", i+1, speed[i]);
    }

    // calculating average speed
    for (j = 0; j < 10; j++) {
        avg += speed[j];
    }
    avg /= 10.0;

    // displaying results
    printf("\nAverage speed: %.2f Mbps\n\n", avg);

    // determining shape of internet connection based on average speed
    printf("Your internet connection speed is somewhere between:\n");
    if (avg < 10.0) {
        printf("- Snail (0 - 10 Mbps)\n");
    } else if (avg >= 10.0 && avg < 50.0) {
        printf("- Cheetah (10 - 50 Mbps)\n");
    } else if (avg >= 50.0 && avg < 100.0) {
        printf("- Falcon (50 - 100 Mbps)\n");
    } else if (avg >= 100.0 && avg < 200.0) {
        printf("- Supersonic (100 - 200 Mbps)\n");
    } else {
        printf("- Light Speed (>200 Mbps)\n");
    }

    printf("\nThank you for using the Shape Shifting Speed Test Application.\n");

    return 0;
}