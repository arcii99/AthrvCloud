//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 20

pthread_mutex_t mutex;

char file_names[MAX_FILES][MAX_NAME_LENGTH];
int num_files = 0;

void* backup_files(void* arg) {
    char* file_name = (char*) arg;
    pthread_mutex_lock(&mutex); // Ensure mutual exclusion
    strcpy(file_names[num_files], file_name);
    num_files++;
    pthread_mutex_unlock(&mutex);
    printf("Backing up file: %s\n", file_name);
    // Code to backup the file
    printf("Successfully backed up file: %s\n", file_name);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid[MAX_FILES];
    char file_names_to_backup[MAX_FILES][MAX_NAME_LENGTH] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    int num_files_to_backup = 5;

    for(int i=0; i<num_files_to_backup; i++) {
        pthread_create(&tid[i], NULL, backup_files, (void*) file_names_to_backup[i]);
    }

    // Wait for all threads to finish
    for(int i=0; i<num_files_to_backup; i++) {
        pthread_join(tid[i], NULL);
    }

    // Print the list of all files backed up
    printf("Files backed up:\n");
    for(int i=0; i<num_files; i++) {
        printf("%s\n", file_names[i]);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}