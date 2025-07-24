//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILES 100 // Maximum number of files in system
#define MAX_THREADS 5 // Maximum number of threads accessing files at once
#define MAX_BUF_SIZE 256 // Size of buffer for read/write operations

// File structure to store information about each file in system
typedef struct {
    int file_id; // Unique ID for file
    char* filename; // Name of file
    int file_size; // Size of file
    char* file_data; // Data stored in file
} File;

// Global variables
File file_system[MAX_FILES]; // Array to store all files in system
int num_files = 0; // Current number of files in system
pthread_mutex_t mutex_files; // Mutex to ensure thread-safe access to files

// Function to create a new file
int create_file(char* filename) {
    pthread_mutex_lock(&mutex_files);

    // Check if file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            pthread_mutex_unlock(&mutex_files);
            return -1;
        }
    }

    // Create new file
    File new_file;
    new_file.file_id = num_files;
    new_file.filename = filename;
    new_file.file_size = 0;
    new_file.file_data = malloc(0);
    file_system[num_files] = new_file;
    num_files++;

    pthread_mutex_unlock(&mutex_files);
    return new_file.file_id;
}

// Function to delete a file
int delete_file(char* filename) {
    pthread_mutex_lock(&mutex_files);

    // Find file with matching filename
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    // Return error if file not found
    if (file_index == -1) {
        pthread_mutex_unlock(&mutex_files);
        return -1;
    }

    // Free memory and remove from file system array
    free(file_system[file_index].file_data);
    for (int i = file_index + 1; i < num_files; i++) {
        file_system[i - 1] = file_system[i];
    }
    num_files--;

    pthread_mutex_unlock(&mutex_files);
    return 0;
}

// Function to read data from a file
int read_file(int file_id, char* buf, int count, off_t offset) {
    pthread_mutex_lock(&mutex_files);

    // Find file with matching ID
    File file_to_read;
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (file_system[i].file_id == file_id) {
            file_to_read = file_system[i];
            file_index = i;
            break;
        }
    }

    // Return error if file not found
    if (file_index == -1) {
        pthread_mutex_unlock(&mutex_files);
        return -1;
    }

    // Read data from file
    int num_bytes_read = 0;
    for (int i = offset; i < file_to_read.file_size && num_bytes_read < count; i++) {
        buf[num_bytes_read] = file_to_read.file_data[i];
        num_bytes_read++;
    }

    pthread_mutex_unlock(&mutex_files);
    return num_bytes_read;
}

// Function to write data to a file
int write_file(int file_id, char* buf, int count, off_t offset) {
    pthread_mutex_lock(&mutex_files);

    // Find file with matching ID
    File file_to_write;
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (file_system[i].file_id == file_id) {
            file_to_write = file_system[i];
            file_index = i;
            break;
        }
    }

    // Return error if file not found
    if (file_index == -1) {
        pthread_mutex_unlock(&mutex_files);
        return -1;
    }

    // Resize file data if necessary
    if (offset + count > file_to_write.file_size) {
        int new_file_size = offset + count;
        file_to_write.file_data = realloc(file_to_write.file_data, new_file_size);
        file_to_write.file_size = new_file_size;
        file_system[file_index] = file_to_write;
    }

    // Write data to file
    for (int i = offset; i < offset + count; i++) {
        file_to_write.file_data[i] = buf[i - offset];
    }
    file_system[file_index] = file_to_write;

    pthread_mutex_unlock(&mutex_files);
    return count;
}

// Function to simulate file system operations using threads
void* simulate_file_system(void* arg) {
    // Generate random file name
    char filename[10];
    sprintf(filename, "file%d", rand() % 1000);

    // Create file
    int file_id = create_file(filename);
    if (file_id == -1) {
        printf("Thread %ld: Error creating file %s\n", pthread_self(), filename);
        return NULL;
    }
    printf("Thread %ld: Created file %s\n", pthread_self(), filename);

    // Write to file
    char data[MAX_BUF_SIZE];
    sprintf(data, "Thread %ld: Data written to %s", pthread_self(), filename);
    int num_bytes_written = write_file(file_id, data, strlen(data), 0);
    if (num_bytes_written == -1) {
        printf("Thread %ld: Error writing data to file %s\n", pthread_self(), filename);
        return NULL;
    }
    printf("Thread %ld: Wrote %d bytes to file %s\n", pthread_self(), num_bytes_written, filename);

    // Read from file
    char read_data[MAX_BUF_SIZE];
    int num_bytes_read = read_file(file_id, read_data, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        printf("Thread %ld: Error reading data from file %s\n", pthread_self(), filename);
        return NULL;
    }
    printf("Thread %ld: Read %d bytes from file %s: %s\n", pthread_self(), num_bytes_read, filename, read_data);

    // Delete file
    int delete_result = delete_file(filename);
    if (delete_result == -1) {
        printf("Thread %ld: Error deleting file %s\n", pthread_self(), filename);
        return NULL;
    }
    printf("Thread %ld: Deleted file %s\n", pthread_self(), filename);

    return NULL;
}

int main() {
    srand(time(NULL));

    // Initialize file system with empty files
    for (int i = 0; i < MAX_FILES; i++) {
        file_system[i].file_id = -1;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex_files, NULL);

    // Create threads to simulate file system operations
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, simulate_file_system, NULL);
    }

    // Wait for threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex_files);

    return 0;
}