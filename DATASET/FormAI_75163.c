//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random internet speed between 1 and 100 Mbps
int generate_speed() {
    return rand() % 100 + 1;
}

// Function to simulate a speed test
int test_speed() {
    int speed = generate_speed();
    printf("Testing internet speed... \n");
    printf("Download speed: %d Mbps \n", speed);
    printf("Upload speed: %d Mbps \n", speed);
    printf("Latency: %d ms \n", rand() % 50 + 1);
    return speed;
}

// Function to compare two internet speeds and return the higher speed
int compare_speeds(int speed1, int speed2) {
    if (speed1 > speed2) {
        return speed1;
    } else {
        return speed2;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    int speed1 = test_speed();
    int speed2 = test_speed();
    int max_speed = compare_speeds(speed1, speed2);
    printf("Your maximum internet speed is: %d Mbps \n", max_speed);
    return 0;
}