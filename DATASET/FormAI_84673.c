//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random internet speeds
float generateInternetSpeed() {
    float speed = (float)rand()/(float)(RAND_MAX/100); // speeds range from 0 to 100 Mbps
    return speed;
}

// Function to test internet speed
float testInternetSpeed() {
    printf("Testing internet speed...\n");
    float speed = generateInternetSpeed();
    printf("Your internet speed is: %.2f Mbps\n", speed);
    return speed;
}

int main() {
    srand(time(NULL)); // seed for random number generation
    char choice = 'y';
    while(choice == 'y' || choice == 'Y') {
        float speed = testInternetSpeed();
        printf("Do you want to test again? (y/n): ");
        scanf(" %c", &choice);
    }
    printf("Thank you for using the internet speed test!\n");
    return 0;
}