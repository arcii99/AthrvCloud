//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILES 10
int file_count = 0; // To maintain number of files created

// Structure to represent file
typedef struct File {
    int id;
    char* name;
    char* content;
} File;

// Array of files
File file_system[MAX_FILES];

// Mutex for thread synchronization while creating or deleting file
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a file
void create_file(char* name, char* content) {
    pthread_mutex_lock(&mutex);
    if (file_count >= MAX_FILES) {
        printf("File system is full, cannot create new file.");
        return;
    }
    File new_file;
    new_file.id = file_count;
    new_file.name = name;
    new_file.content = content;
    file_system[file_count++] = new_file;
    printf("File %s created with content: %s\n", name, content);
    pthread_mutex_unlock(&mutex);
}

// Function to delete a file
void delete_file(int id) {
    pthread_mutex_lock(&mutex);
    if (id < 0 || id >= file_count) {
        printf("File with given id does not exist.\n");
        return;
    }
    printf("Deleted file %s with id %d\n", file_system[id].name, file_system[id].id);
    file_system[id].id = -1;
    free(file_system[id].name);
    free(file_system[id].content);
    for (int i = id; i < file_count - 1; i++) {
        file_system[i] = file_system[i+1];
        file_system[i].id--;
    }
    file_count--;
    pthread_mutex_unlock(&mutex);
}

// Function to read content of a file
char* read_file(int id) {
    pthread_mutex_lock(&mutex);
    if (id < 0 || id >= file_count) {
        printf("File with given id does not exist.\n");
        return NULL;
    }
    pthread_mutex_unlock(&mutex);
    return file_system[id].content;
}

// Function to modify content of a file
void modify_file(int id, char* new_content) {
    pthread_mutex_lock(&mutex);
    if (id < 0 || id >= file_count) {
        printf("File with given id does not exist.\n");
        return;
    }
    printf("Modifying file %s with new content: %s\n", file_system[id].name, new_content);
    free(file_system[id].content);
    file_system[id].content = new_content;
    pthread_mutex_unlock(&mutex);
}

// Main function to test file system
int main() {
    create_file("file1.txt", "Hello! This is file 1 content.");
    create_file("file2.txt", "Hey there! This is file 2 content.");
    create_file("file3.txt", "Good to see you! This is file 3 content.");
    delete_file(1);
    printf("Content of file 2: %s\n", read_file(1));
    modify_file(0, "Modified content for file 1.");
    printf("Content of file 1: %s\n", read_file(0));
    return 0;
}