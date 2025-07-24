//FormAI DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

// Global audio buffers
float input_buffer[BUFFER_SIZE]; // input buffer
float output_buffer[BUFFER_SIZE]; // output buffer

// Global variables
int num_threads; // number of worker threads
int samples_per_thread; // number of samples each thread will process
float frequency; // frequency of the sine wave to be generated

// Function to generate sine wave
void generate_sine_wave(float *buffer, int num_samples) {
    float amplitude = 0.5;
    for(int i = 0; i < num_samples; i++) {
        buffer[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

// Function for thread worker
void* audio_processing(void* arg) {
    int thread_num = *((int*) arg);
    printf("Thread %d started.\n", thread_num);

    // Calculate start and end indices for this thread
    int start_index = thread_num * samples_per_thread;
    int end_index = start_index + samples_per_thread;

    // Apply gain to input buffer within this thread's range
    for(int i = start_index; i < end_index; i++) {
        output_buffer[i] = 2 * input_buffer[i];
    }

    printf("Thread %d done.\n", thread_num);
    return NULL;
}

int main() {
    // Set up audio input
    generate_sine_wave(input_buffer, BUFFER_SIZE);

    // Set up variables for multi-threading
    num_threads = 4;
    samples_per_thread = BUFFER_SIZE / num_threads;

    // Set up thread pool
    pthread_t thread_pool[num_threads];

    // Create threads
    for(int i = 0; i < num_threads; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&thread_pool[i], NULL, audio_processing, (void*) thread_num);
    }

    // Wait for threads to finish
    for(int i = 0; i < num_threads; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    // Write output buffer to file
    FILE* output_file = fopen("output.wav", "wb");
    fwrite(output_buffer, sizeof(float), BUFFER_SIZE, output_file);
    fclose(output_file);

    return 0;
}