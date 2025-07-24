//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_THREADS 5
#define MAX_FILENAME 20
#define MAX_SCAN_TIME 10

char* infected_files[MAX_FILES];
int num_infected_files = 0;
pthread_mutex_t lock;

void *scan_file(void *filename) {
    char* file = (char*) filename;
    // Simulate a file scan process
    int scan_time = rand() % MAX_SCAN_TIME + 1;
    printf("Scanning %s...\n", file);
    sleep(scan_time);
    // Simulate a detection result
    int is_infected = rand() % 2;
    if (is_infected) {
        pthread_mutex_lock(&lock);
        printf("Virus detected in %s!\n", file);
        infected_files[num_infected_files++] = strdup(file);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char files[MAX_FILES][MAX_FILENAME] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt", "file11.txt"};
    srand(time(NULL));
    // Create threads to scan all the files
    for (int i = 0; i < MAX_FILES; i++) {
        pthread_create(&threads[i%MAX_THREADS], NULL, scan_file, (void*) files[i]);
        sleep(1);
    }
    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Print infected files
    printf("\nInfected files:\n");
    for (int i = 0; i < num_infected_files; i++) {
        printf("%d. %s\n", i+1, infected_files[i]);
    }
    return 0;
}