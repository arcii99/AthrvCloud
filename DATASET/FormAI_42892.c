//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_FILES 10

char* files[MAX_FILES]; // array of file names
int num_files = 0; // number of files in the system

pthread_mutex_t file_lock;

void* create_file(void* arg)
{
    char* file_name = (char*) arg;
    pthread_mutex_lock(&file_lock);
    if (num_files < MAX_FILES) {
        files[num_files++] = file_name;
        printf("File created: %s\n", file_name);
    } else {
        printf("Error: Maximum number of files reached!\n");
    }
    pthread_mutex_unlock(&file_lock);
    pthread_exit(NULL);
}

void* delete_file(void* arg)
{
    char* file_name = (char*) arg;
    pthread_mutex_lock(&file_lock);
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i], file_name) == 0) {
            printf("Deleting file: %s\n", file_name);
            num_files--;
            for (int j = i; j < num_files; j++) {
                files[j] = files[j+1];
            }
            pthread_mutex_unlock(&file_lock);
            pthread_exit(NULL);
        }
    }
    printf("Error: File not found!\n");
    pthread_mutex_unlock(&file_lock);
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&file_lock, NULL);

    // Create files
    pthread_create(&threads[0], NULL, create_file, "file1.txt");
    pthread_create(&threads[1], NULL, create_file, "file2.txt");
    pthread_create(&threads[2], NULL, create_file, "file3.txt");

    // Wait for file creation threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Delete a file
    pthread_create(&threads[3], NULL, delete_file, "file2.txt");
    pthread_join(threads[3], NULL);

    // Print remaining files
    printf("Remaining files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]);
    }

    pthread_mutex_destroy(&file_lock);
    return 0;
}