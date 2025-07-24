//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_LEN_FILENAME 50

// File structure to store information about each file
typedef struct file {
    char name[MAX_LEN_FILENAME];
    int size;
} File;

// Variables to keep track of the current file system state
File fileSystem[MAX_FILES];
int numFiles = 0;

// Mutex to ensure thread-safe access to the file system
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to add a file to the file system
void* add_file(void* arg) {
    char* filename = (char*) arg;

    pthread_mutex_lock(&mutex);

    // Check if the file already exists
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(filename, fileSystem[i].name) == 0) {
            printf("File %s already exists!\n", filename);
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
    }

    // Add the file to the file system
    strcpy(fileSystem[numFiles].name, filename);
    fileSystem[numFiles].size = 0;
    numFiles++;

    printf("File %s added!\n", filename);

    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Thread function to remove a file from the file system
void* remove_file(void* arg) {
    char* filename = (char*) arg;

    pthread_mutex_lock(&mutex);

    // Find the index of the file in the file system
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(filename, fileSystem[i].name) == 0) {
            break;
        }
    }

    // If the file is not found, return
    if (i == numFiles) {
        printf("File %s not found!\n", filename);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    // Remove the file from the file system
    numFiles--;
    memmove(&fileSystem[i], &fileSystem[i+1], (numFiles-i) * sizeof(File));

    printf("File %s removed!\n", filename);

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Add files to the file system using thread1
    char* file1 = "file1.txt";
    char* file2 = "file2.txt";
    pthread_create(&thread1, NULL, add_file, file1);
    pthread_create(&thread1, NULL, add_file, file2);

    // Wait for thread1 to finish
    pthread_join(thread1, NULL);

    // Remove a file from the file system using thread2
    char* file3 = "file3.txt";
    pthread_create(&thread2, NULL, remove_file, file3);

    // Wait for thread2 to finish
    pthread_join(thread2, NULL);

    return 0;
}