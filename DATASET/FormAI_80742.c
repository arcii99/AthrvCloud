//FormAI DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILES 100
#define MAX_BUFFER_SIZE 1024

// A file structure to represent each file
typedef struct{
    char* name;
    char* content;
    int size;
} File;

// A structure to represent the state of the program
typedef struct{
    File* files[MAX_FILES];
    int num_files;
} State;

// A buffer to store files that are being synchronized
typedef struct{
    File* files[MAX_BUFFER_SIZE];
    int count;
    pthread_mutex_t mutex;
} FileBuffer;

// A thread function to synchronize files
void* synchronize_files(void* args){
    State* state = (State*) args;
    FileBuffer* buffer = (FileBuffer*) malloc(sizeof(FileBuffer));
    buffer->count = 0;
    pthread_mutex_init(&buffer->mutex, NULL);

    while(1){
        // Check if there are any files to synchronize
        if(state->num_files > 0){
            // Pick a file to synchronize
            int index = rand() % state->num_files;
            File* file = state->files[index];

            // Lock the buffer
            pthread_mutex_lock(&buffer->mutex);

            // Add the file to the buffer
            buffer->files[buffer->count] = file;
            buffer->count++;

            // Unlock the buffer
            pthread_mutex_unlock(&buffer->mutex);

            // Remove the file from the state
            state->files[index] = state->files[state->num_files-1];
            state->num_files--;

            printf("File %s has been added to the buffer\n", file->name);
        }

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }
}

// A thread function to synchronize files from the buffer
void* synchronize_files_buffer(void* args){
    State* state = (State*) args;
    FileBuffer* buffer = (FileBuffer*) malloc(sizeof(FileBuffer));
    buffer->count = 0;
    pthread_mutex_init(&buffer->mutex, NULL);

    while(1){
        // Lock the buffer
        pthread_mutex_lock(&buffer->mutex);

        // Check if there are any files in the buffer
        if(buffer->count > 0){
            // Pick a file to synchronize
            int index = rand() % buffer->count;
            File* file = buffer->files[index];

            // Remove the file from the buffer
            buffer->files[index] = buffer->files[buffer->count-1];
            buffer->count--;

            // Unlock the buffer
            pthread_mutex_unlock(&buffer->mutex);

            // Copy the file to the state
            state->files[state->num_files] = (File*) malloc(sizeof(File));
            state->files[state->num_files]->name = strdup(file->name);
            state->files[state->num_files]->content = strdup(file->content);
            state->files[state->num_files]->size = file->size;
            state->num_files++;

            printf("File %s has been synchronized\n", file->name);
        } else {
            // Unlock the buffer
            pthread_mutex_unlock(&buffer->mutex);
        }

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }
}

// The main function to start the program
int main(){
    // Initialize the state
    State state;
    state.num_files = 0;

    // Start the threads
    pthread_t threads[MAX_THREADS];
    pthread_create(&threads[0], NULL, synchronize_files, &state);
    pthread_create(&threads[1], NULL, synchronize_files_buffer, &state);

    // Wait for the threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}