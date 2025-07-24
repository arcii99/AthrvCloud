//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4 // define maximum threads to be used
#define MAX_FILES 50 // define maximum number of files to be scanned
#define MAX_FILE_NAME_LENGTH 50 // define maximum file name length
#define VIRUS_SIGNATURE "malware" // define the virus signature to be searched for

pthread_mutex_t mutex; // mutex to synchronize the access to the shared variables

int number_of_files = 0; // the number of files that have been scanned
int infected_files = 0; // the number of infected files that have been found

char files[MAX_FILES][MAX_FILE_NAME_LENGTH]; // an array to store the file names that need to be scanned
int thread_numbers[MAX_THREADS]; // an array to store the thread numbers

// function to check if a file is infected
void scan_file(char *file_name) {
    FILE *file;
    char line[100];
    int is_infected = 0;

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Cannot open file: %s\n", file_name);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, VIRUS_SIGNATURE) != NULL) {
            is_infected = 1;
            break;
        }
    }

    if (is_infected == 1) {
        printf("File: %s is infected with %s\n", file_name, VIRUS_SIGNATURE);
        pthread_mutex_lock(&mutex);
        infected_files++;
        pthread_mutex_unlock(&mutex);
    }

    fclose(file);

    pthread_mutex_lock(&mutex);
    number_of_files++;
    pthread_mutex_unlock(&mutex);
}

// function to be executed by each thread
void *run_scanner(void *thread_number) {
    int tid = *(int*) thread_number;

    while (1) {
        pthread_mutex_lock(&mutex);
        if (number_of_files >= MAX_FILES) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        int file_index = number_of_files;
        pthread_mutex_unlock(&mutex);

        if (file_index < MAX_FILES) {
            scan_file(files[file_index]);
        }
    }

    printf("Thread %d finished scanning\n", tid);
    return NULL;
}

// main program
int main(int argc, char const *argv[]) {
    pthread_t threads[MAX_THREADS];

    // initialize the files array with some random file names
    for (int i = 0; i < MAX_FILES; i++) {
        char file_name[MAX_FILE_NAME_LENGTH];
        sprintf(file_name, "file%d.txt", i+1);
        strcpy(files[i],file_name);
    }

    pthread_mutex_init(&mutex, NULL);

    // create the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_numbers[i] = i;
        pthread_create(&threads[i], NULL, run_scanner, &thread_numbers[i]);
    }

    // wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scanning finished. %d files scanned, %d infected files found.\n", number_of_files, infected_files);

    pthread_mutex_destroy(&mutex);

    return 0;
}