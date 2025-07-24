//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>

#define MAX_FILE_COUNT 10
#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_DATA_SIZE 1024

typedef struct file
{
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_DATA_SIZE];
    int size;
} file_t;

typedef struct file_sync
{
    file_t files[MAX_FILE_COUNT];
    int file_count;
    int sync_period;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} file_sync_t;

void* thread_func(void* data)
{
    file_sync_t* file_sync = (file_sync_t*)data;

    while(1)
    {
        sleep(file_sync->sync_period);

        pthread_mutex_lock(&(file_sync->lock));

        printf("Starting file synchronization...\n");

        // Do file synchronization here
        // For simplicity, let's assume we just copy the first file data to all other files

        file_t* src_file = &(file_sync->files[0]);

        for(int i=1; i<file_sync->file_count; i++)
        {
            file_t* dest_file = &(file_sync->files[i]);
            memcpy(dest_file->data, src_file->data, src_file->size);
            dest_file->size = src_file->size;
        }

        printf("File synchronization completed.\n");

        pthread_cond_signal(&(file_sync->cond));
        pthread_mutex_unlock(&(file_sync->lock));
    }

    return NULL;
}

int main()
{
    file_sync_t file_sync;
    file_sync.file_count = 3;
    file_sync.sync_period = 5;
    pthread_mutex_init(&(file_sync.lock), NULL);
    pthread_cond_init(&(file_sync.cond), NULL);

    // Initialize files
    file_t file1, file2, file3;
    strncpy(file1.name, "file1.txt", MAX_FILE_NAME_LENGTH);
    strncpy(file2.name, "file2.txt", MAX_FILE_NAME_LENGTH);
    strncpy(file3.name, "file3.txt", MAX_FILE_NAME_LENGTH);
    strncpy(file1.data, "This is file1 data.", MAX_FILE_DATA_SIZE);
    strncpy(file2.data, "This is file2 data.", MAX_FILE_DATA_SIZE);
    strncpy(file3.data, "This is file3 data.", MAX_FILE_DATA_SIZE);
    file1.size = strlen(file1.data);
    file2.size = strlen(file2.data);
    file3.size = strlen(file3.data);
    file_sync.files[0] = file1;
    file_sync.files[1] = file2;
    file_sync.files[2] = file3;

    // Start synchronization thread
    pthread_t sync_thread;
    pthread_create(&sync_thread, NULL, thread_func, &file_sync);

    // Main thread
    while(1)
    {
        pthread_mutex_lock(&(file_sync.lock));
        pthread_cond_wait(&(file_sync.cond), &(file_sync.lock));
        pthread_mutex_unlock(&(file_sync.lock));

        printf("Updating local files...\n");
        // Updating local files
        for(int i=0; i<file_sync.file_count; i++)
        {
            file_t* file = &(file_sync.files[i]);
            printf("File %s updated, size=%d\n", file->name, file->size);
        }
    }

    return 0;
}