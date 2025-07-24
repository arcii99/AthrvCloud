//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 1000
#define MAX_FILE_SIZE 1024

char file_system[MAX_FILES][MAX_FILE_SIZE];
int file_size[MAX_FILES] = {0};
pthread_mutex_t file_mutex[MAX_FILES];

void write_to_file(int file_index, char data[])
{
    pthread_mutex_lock(&file_mutex[file_index]);
    strcpy(file_system[file_index], data);
    file_size[file_index] = strlen(data);
    pthread_mutex_unlock(&file_mutex[file_index]);
}

void read_from_file(int file_index, char buffer[])
{
    pthread_mutex_lock(&file_mutex[file_index]);
    strcpy(buffer, file_system[file_index]);
    pthread_mutex_unlock(&file_mutex[file_index]);
}

void *write_thread(void *arg)
{
    int file_index = *(int *) arg;
    char buffer[MAX_FILE_SIZE];

    snprintf(buffer, MAX_FILE_SIZE, "This is file %d", file_index);
    write_to_file(file_index, buffer);

    return NULL;
}

void *read_thread(void *arg)
{
    int file_index = *(int *) arg;
    char buffer[MAX_FILE_SIZE];

    read_from_file(file_index, buffer);
    printf("File %d contains: %s\n", file_index, buffer);

    return NULL;
}

int main()
{
    pthread_t write_threads[MAX_FILES], read_threads[MAX_FILES];
    int i = 0;

    for (i = 0; i < MAX_FILES; i++) {
        pthread_mutex_init(&file_mutex[i], NULL);
    }

    for (i = 0; i < MAX_FILES; i++) {
        pthread_create(&write_threads[i], NULL, &write_thread, (void *)&i);
        pthread_create(&read_threads[i], NULL, &read_thread, (void *)&i);

        pthread_join(write_threads[i], NULL);
        pthread_join(read_threads[i], NULL);
    }

    for (i = 0; i < MAX_FILES; i++) {
        pthread_mutex_destroy(&file_mutex[i]);
    }

    return 0;
}