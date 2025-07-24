//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_THREADS 5 //maximum number of threads to run simultaneously

void *reader_function(void *filename);
void *parser_function(void *line);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //mutex initialization

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Error: Please specify at least one log file to analyze");
        exit(1);
    }
    pthread_t tids[MAX_THREADS]; //array to store thread ID's
    int thread_count = 0; //counter to keep track of the number of threads

    for (int i = 1; i < argc; i++) { //iterate over the input files
        pthread_create(&tids[thread_count], NULL, reader_function, argv[i]); //start a new thread to read the file
        thread_count++;

        if (thread_count == MAX_THREADS) { //check if the maximum number of threads has been reached
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(tids[j], NULL); //wait for threads to finish before creating new ones
            }
            thread_count = 0;
        }
    }

    //wait for remaining threads to finish
    for (int k = 0; k < thread_count; k++) {
        pthread_join(tids[k], NULL);
    }

    printf("Log analysis complete!\n");
    pthread_mutex_destroy(&mutex); //destroy mutex
    return 0;
}

void *reader_function(void *filename) {
    FILE *file = fopen(filename, "r");
    char line[256];

    if (file == NULL) {
        printf("Error: could not open file %s", filename);
        pthread_exit(NULL);
    }

    while (fgets(line, sizeof(line), file)) { //iterate over each line of the log file
        pthread_t tid;
        pthread_create(&tid, NULL, parser_function, line); //start a new thread to parse each line
        pthread_join(tid, NULL);
    }

    fclose(file);
    pthread_exit(NULL);
}

void *parser_function(void *line) {
    char *log_line = (char *)line; //convert line to char array
    pthread_mutex_lock(&mutex); //acquire lock on the shared resource
    //do the analysis here
    printf("%s", log_line);
    pthread_mutex_unlock(&mutex); //release lock on the shared resource
    pthread_exit(NULL);
}