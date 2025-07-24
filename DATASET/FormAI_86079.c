//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CPU_USAGE 100 // Maximum CPU usage percentage
#define MAX_SLEEP_TIME 10 // Maximum sleep time in seconds
#define SAMPLE_SIZE 50    // Number of samples to use for statistics

// Function to generate random CPU usage percentage
int generate_cpu_usage() {
    return rand() % (MAX_CPU_USAGE + 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array to store the samples
    int samples[SAMPLE_SIZE];
    int sum = 0;
    int i;

    // Generate and store the samples
    for (i = 0; i < SAMPLE_SIZE; i++) {
        samples[i] = generate_cpu_usage();
        sum += samples[i];
    }

    // Calculate the average CPU usage
    float average = sum / SAMPLE_SIZE;

    // Calculate the standard deviation
    float variance = 0.0;
    for (i = 0; i < SAMPLE_SIZE; i++) {
        variance += pow((samples[i] - average), 2);
    }
    float std_dev = sqrt(variance / SAMPLE_SIZE);

    // Print the statistics
    printf("CPU Usage Monitor Statistics\n");
    printf("----------------------------\n");
    printf("Average CPU usage: %.2f%%\n", average);
    printf("Standard deviation: %.2f%%\n", std_dev);

    // Sleep for a random amount of time to emulate real-world usage
    int sleep_time = rand() % MAX_SLEEP_TIME;
    printf("Sleeping for %d seconds...\n", sleep_time);
    sleep(sleep_time);

    return 0;
}