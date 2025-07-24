//FormAI DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    short *input_buffer;
    short *output_buffer;
    int buffer_size;
} thread_args;

void *process_audio_on_thread(void *arg) {
    thread_args *args = (thread_args *) arg;
    short *in_buf = args->input_buffer;
    short *out_buf = args->output_buffer;
    int buffer_size = args->buffer_size;

    // Audio processing code goes here
    // For example, let's just double the volume:
    for (int i = 0; i < buffer_size; i++) {
        out_buf[i] = in_buf[i] * 2;
    }

    pthread_exit(NULL);
}

int main() {
    short input_buffer[BUFFER_SIZE];
    short output_buffer[BUFFER_SIZE];
    pthread_t thread_id;
    thread_args args;
    int rc;

    // Generate test audio data
    for (int i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = rand() % 32768 - 16384;
    }

    args.input_buffer = input_buffer;
    args.output_buffer = output_buffer;
    args.buffer_size = BUFFER_SIZE;

    rc = pthread_create(&thread_id, NULL, process_audio_on_thread, (void *) &args);
    if (rc) {
        fprintf(stderr, "Error creating thread\n");
        exit(1);
    }

    // Main thread does other work while audio processing is happening
    // In this example, we just sleep for 1 second
    sleep(1);

    // Wait for audio processing thread to complete
    pthread_join(thread_id, NULL);

    // Output processed audio data
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", output_buffer[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}