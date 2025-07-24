//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/resource.h>
#include <time.h>

// Define the maximum number of samples
#define MAX_SAMPLES 10

// Define the number of seconds between samples
#define SAMPLE_INTERVAL 5

// Define the signal to use for shutting down gracefully
#define SIGNAL_GRACEFUL_SHUTDOWN SIGINT

// Define an array to store the samples
int samples[MAX_SAMPLES];

// Define a variable to keep track of the current sample index
int current_sample = 0;

// Define a variable to keep track of whether the program should continue running
int should_continue = 1;

// Define a function to handle the graceful shutdown signal
void handle_graceful_shutdown(int signal)
{
    should_continue = 0;
}

// Define a function to calculate and display the average RAM usage
void display_average_ram_usage()
{
    int total_ram_usage = 0;

    for (int i = 0; i < MAX_SAMPLES; ++i)
    {
        total_ram_usage += samples[i];
    }

    float average_ram_usage = (float)total_ram_usage / MAX_SAMPLES;

    printf("Average RAM usage over the past %d samples: %.2fMB\n", MAX_SAMPLES, average_ram_usage / 1024.0);
}

// Define the main function
int main(int argc, char *argv[])
{
    // Register the signal handler for the graceful shutdown signal
    signal(SIGNAL_GRACEFUL_SHUTDOWN, handle_graceful_shutdown);

    // Print a message to indicate that the program has started
    printf("C RAM usage monitor program started.\n");

    // Initialize the random number generator
    srand(time(NULL));

    // Enter a loop to take and store RAM usage samples
    while (should_continue)
    {
        // Allocate some memory to force the system to use more RAM
        void *p = malloc(rand() % (512 * 1024 * 1024));

        // Get the RAM usage and store it in the samples array
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        samples[current_sample] = usage.ru_maxrss;

        // Free the memory to avoid memory leaks
        free(p);

        // Increment the current sample index, or reset it to 0 if it has reached the end of the array
        current_sample = (current_sample + 1) % MAX_SAMPLES;

        // Sleep for the specified interval
        sleep(SAMPLE_INTERVAL);
    }

    // Print a message to indicate that the program is shutting down
    printf("C RAM usage monitor program shutting down gracefully.\n");

    // Call the function to calculate and display the average RAM usage
    display_average_ram_usage();

    // Exit the program
    exit(0);
}