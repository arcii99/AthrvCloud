//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random internet speed
float get_speed() {
    float speed = ((float)rand()/(float)(RAND_MAX)) * 100; // Generate a random number between 0 and 100
    return speed;
}

int main() {
    int time_elapsed = 0;
    float total_speed = 0, avg_speed = 0;
    int num_tests = 0;
    srand(time(0)); // Seed for random number generator

    printf("Welcome to the Internet Speed Test Application!\n\n");

    printf("Please enter the number of tests you want to run: ");
    scanf("%d", &num_tests);
    printf("\n");
    
    printf("Running internet speed test(s)...\n\n");
    while (num_tests > 0) {
        float speed = get_speed();
        printf("Test %d: %.2f Mbps\n", num_tests, speed);
        total_speed += speed;
        num_tests--;
        time_elapsed++;
        sleep(1); // Sleep for a second to simulate each test taking 1 second
    }

    printf("\nInternet speed tests complete!\n");
    avg_speed = total_speed / (float)time_elapsed;
    printf("Average speed: %.2f Mbps\n", avg_speed);

    return 0;
}