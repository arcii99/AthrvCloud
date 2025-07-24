//FormAI DATASET v1.0 Category: File Synchronizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SYNC_FILES 100
#define MAX_FILE_LENGTH 256

int num_files = 0;
char synced_files[MAX_SYNC_FILES][MAX_FILE_LENGTH];
pthread_mutex_t mutex;

void sync_file(char *file_path){
    pthread_mutex_lock(&mutex);
    int file_found = 0;
    for(int i=0; i<num_files; i++){
        if(strcmp(file_path, synced_files[i]) == 0){
            file_found = 1;
            break;
        }
    }
    if(!file_found){
        printf("Syncing new file %s\n", file_path);
        strcpy(synced_files[num_files], file_path);
        num_files++;
    }
    pthread_mutex_unlock(&mutex);
}

void* thread_func(void *dir_name){
    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];
    dir = opendir((char*)dir_name);
    if(dir == NULL){
        fprintf(stderr, "Could not open directory %s\n", (char*)dir_name);
        pthread_exit(NULL);
    }

    while((entry = readdir(dir)) != NULL){
        if(entry->d_type == DT_DIR){
            if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                snprintf(path, (size_t) PATH_MAX, "%s/%s", (char*)dir_name, entry->d_name);
                thread_func(path);
            }
        }
        else if(entry->d_type == DT_REG){
            snprintf(path, (size_t) PATH_MAX, "%s/%s", (char*)dir_name, entry->d_name);
            sync_file(path);
        }
    }
    closedir(dir);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    // Check usage
    if(argc != 3){
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        return 1;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize threads
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    // Traverse directory 1
    if(pthread_create(&threads[num_threads], NULL, thread_func, argv[1]) != 0){
        fprintf(stderr, "Could not create thread.\n");
        return 1;
    }
    num_threads++;

    // Traverse directory 2
    if(pthread_create(&threads[num_threads], NULL, thread_func, argv[2]) != 0){
        fprintf(stderr, "Could not create thread.\n");
        return 1;
    }
    num_threads++;

    // Wait for threads to finish
    for(int i=0; i<num_threads; i++){
        pthread_join(threads[i], NULL);
    }

    // Print synced files
    printf("Synced files:\n");
    for(int i=0; i<num_files; i++){
        printf("%s\n", synced_files[i]);
    }
    
    // Cleanup
    pthread_mutex_destroy(&mutex);
    return 0;
}