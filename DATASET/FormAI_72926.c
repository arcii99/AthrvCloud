//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define FREQUENCY 1000
#define Q_FACTOR 2.0

// Global variables
float gBuffer[BUFFER_SIZE];
float gFilteredBuffer[BUFFER_SIZE];

// Locks and conditions
pthread_mutex_t gMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gBufferReady = PTHREAD_COND_INITIALIZER;
pthread_cond_t gBufferProcessed = PTHREAD_COND_INITIALIZER;

// Functions
float calculateFilterCoefficient(float fc, float Q) {
    float w0 = 2 * M_PI * fc / SAMPLE_RATE;
    float alpha = sin(w0) / (2 * Q);
    float a0 = 1 + alpha;
    return alpha / a0;
}

void* filterThread(void* arg) {
    float fc = FREQUENCY / SAMPLE_RATE;
    float Q = Q_FACTOR;
    float b0 = 1;
    float b1 = -2 * cos(2 * M_PI * fc) / (1 + calculateFilterCoefficient(fc, Q));
    float b2 = (1 - calculateFilterCoefficient(fc, Q)) / (1 + calculateFilterCoefficient(fc, Q));
    float a1 = -b1;
    float a2 = (1 - calculateFilterCoefficient(fc, Q)) / (1 + calculateFilterCoefficient(fc, Q));
    float x0, x1, x2, y0, y1, y2;
    x1 = x2 = y1 = y2 = 0.0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&gMutex);
        while (gBuffer[i] == 0)
            pthread_cond_wait(&gBufferReady, &gMutex);
        x0 = gBuffer[i];
        y0 = b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        gFilteredBuffer[i] = y0;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        gBuffer[i] = 0;
        pthread_cond_signal(&gBufferProcessed);
        pthread_mutex_unlock(&gMutex);
    }
    pthread_exit(NULL);
}

int main() {
    // Create filter thread
    pthread_t filter;
    pthread_create(&filter, NULL, filterThread, NULL);

    // Generate test signal
    float testSignal[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++)
        testSignal[i] = sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);

    // Process signal in chunks
    for (int i = 0; i < BUFFER_SIZE; i += BUFFER_SIZE / 4) {
        // Copy chunk to buffer
        pthread_mutex_lock(&gMutex);
        for (int j = 0; j < BUFFER_SIZE / 4; j++)
            gBuffer[i+j] = testSignal[i+j];
        pthread_cond_signal(&gBufferReady);
        pthread_mutex_unlock(&gMutex);

        // Wait for filter thread to finish
        pthread_mutex_lock(&gMutex);
        while (gBuffer[i+BUFFER_SIZE/4-1] != 0)
            pthread_cond_wait(&gBufferProcessed, &gMutex);
        pthread_mutex_unlock(&gMutex);
    }

    // Join filter thread and print filtered signal
    pthread_join(filter, NULL);
    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%f\n", gFilteredBuffer[i]);

    return 0;
}