//FormAI DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

// Constants
#define BUFFER_SIZE 1024
#define SAMPLING_RATE 44100
#define PI 3.14159265358979323846

// Global variables
double buffer[BUFFER_SIZE];
pthread_mutex_t lock, finished_lock;
int finished = 0;

// Thread function for generating sine wave
void* generate_sine(void* arg)
{
    double frequency = *(double*)arg;
    double phase = 0.0;
    double delta_phase = frequency * (2 * PI / SAMPLING_RATE);

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = sin(phase);
        phase += delta_phase;

        while (phase > 2 * PI)
            phase -= 2 * PI;
    }

    pthread_mutex_lock(&finished_lock);
    finished++;
    pthread_mutex_unlock(&finished_lock);

    pthread_exit(NULL);
}

// Thread function for applying low-pass filter
void* apply_low_pass_filter(void* arg)
{
    double cutoff_frequency = *(double*)arg;
    double RC = 1.0 / (2 * PI * cutoff_frequency);
    double dt = 1.0 / SAMPLING_RATE;
    double alpha = dt / (RC + dt);

    for (int i = 1; i < BUFFER_SIZE; i++)
    {
        buffer[i] = buffer[i-1] + alpha * (buffer[i] - buffer[i-1]);
    }

    pthread_mutex_lock(&finished_lock);
    finished++;
    pthread_mutex_unlock(&finished_lock);

    pthread_exit(NULL);
}

int main()
{
    pthread_t sine_thread, filter_thread;
    double frequency = 1000;
    double cutoff_frequency = 500;

    // Generate sine wave using a separate thread
    if (pthread_create(&sine_thread, NULL, generate_sine, &frequency))
    {
        fprintf(stderr, "Error creating sine thread\n");
        return 1;
    }

    // Apply low-pass filter using a separate thread
    if (pthread_create(&filter_thread, NULL, apply_low_pass_filter, &cutoff_frequency))
    {
        fprintf(stderr, "Error creating filter thread\n");
        return 1;
    }

    // Wait for both threads to finish
    while (finished < 2)
    {
        sleep(1);
    }

    // Print the output signal
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%f\n", buffer[i]);
    }

    // Clean up
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&finished_lock);
    return 0;
}