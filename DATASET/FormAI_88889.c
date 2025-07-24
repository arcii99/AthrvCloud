//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_FILES 100000

struct file {
    int fd;
    char* data;
    int size;
};

struct file files[MAX_FILES];
int num_files = 0;

pthread_rwlock_t file_lock;

void* file_thread(void* arg) {
    int fd = rand() % MAX_FILES;

    pthread_rwlock_rdlock(&file_lock);
    if (files[fd].fd != -1) {
        printf("File %d is being read by thread %ld: %s\n", fd, pthread_self(), files[fd].data);
    }
    pthread_rwlock_unlock(&file_lock);

    pthread_rwlock_wrlock(&file_lock);
    if (files[fd].fd != -1) {
        printf("File %d is being written by thread %ld\n", fd, pthread_self());
        char* new_data = malloc(sizeof(char) * 100);
        sprintf(new_data, "New data written by thread %ld", pthread_self());
        files[fd].data = new_data;
    } else {
        printf("File %d is being created by thread %ld\n", fd, pthread_self());
        char* new_data = malloc(sizeof(char) * 100);
        sprintf(new_data, "Data created by thread %ld", pthread_self());
        files[fd].data = new_data;
        files[fd].size = 100;
        files[fd].fd = fd;
        num_files++;
    }
    pthread_rwlock_unlock(&file_lock);

    pthread_rwlock_rdlock(&file_lock);
    if (num_files > 0) {
        int file_id = rand() % num_files;
        printf("Thread %ld is reading file %d: %s\n", pthread_self(), files[file_id].fd, files[file_id].data);
    }
    pthread_rwlock_unlock(&file_lock);

    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < MAX_FILES; i++) {
        files[i].fd = -1;
        files[i].data = NULL;
        files[i].size = 0;
    }

    pthread_t threads[10];
    pthread_rwlock_init(&file_lock, NULL);

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, file_thread, NULL);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_rwlock_destroy(&file_lock);
    return 0;
}