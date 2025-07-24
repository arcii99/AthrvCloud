//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *extract_metadata(void *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) { // if no filename was passed
        printf("Please provide filename as argument.\n");
        exit(1);
    }
    
    pthread_t tid; // thread identifier
    
    if (pthread_create(&tid, NULL, extract_metadata, argv[1])) { // creating new thread
        printf("Error: Failed to create thread.\n");
        exit(1);
    }
    
    if (pthread_join(tid, NULL)) { // waiting for thread to finish
        printf("Error: Failed to join thread.\n");
        exit(1);
    }
    
    printf("Metadata extraction complete.\n");
    return 0;
}

void *extract_metadata(void *filename) {
    char *fname = (char *) filename;
    printf("Extracting metadata for file: %s\n", fname);
    // TODO: Write code to extract metadata from file
    return NULL;
}