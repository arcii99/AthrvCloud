//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to generate a random number between min and max */
int rand_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to simulate internet speed test */
float internet_speed_test() {
    int download_speed, upload_speed;
    float latency;
    
    download_speed = rand_num(1, 50); // simulated download speed in MB/s
    upload_speed = rand_num(1, 10); // simulate upload speed in MB/s
    latency = rand_num(1, 1000); // simulated latency in ms
    
    printf("Simulating internet speed test...\n");
    printf("Download speed: %d MB/s\n", download_speed);
    printf("Upload speed: %d MB/s\n", upload_speed);
    printf("Latency: %0.2f ms\n\n", latency);
    
    return latency;
}

int main() {
    int i, num_tests;
    float sum_latency = 0.0, avg_latency;
    
    srand(time(NULL)); // set the seed for random number generation
    
    printf("Welcome to the Internet Speed Test Application!\n\n");
    
    printf("How many tests would you like to perform? ");
    scanf("%d", &num_tests);
    
    for (i = 0; i < num_tests; i++) {
        printf("Test %d:\n", i + 1);
        sum_latency += internet_speed_test();
    }
    
    avg_latency = sum_latency / num_tests;
    printf("Average latency over %d tests: %0.2f ms\n", num_tests, avg_latency);

    return 0;
}