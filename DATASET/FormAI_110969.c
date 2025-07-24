//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_THREADS 8

struct thread_args {
    char* dirname;
    int id;
};

int num_threads = 0;
pthread_mutex_t mutex;

void* analyze_directory(void* args) {
    struct thread_args* targs = (struct thread_args*) args;
    char* dirname = targs->dirname;

    DIR* dirp = opendir(dirname);
    if (!dirp) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    struct stat entry_info;
    char path[PATH_MAX];
    long long size = 0;

    while ((entry = readdir(dirp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
        if (lstat(path, &entry_info) < 0) {
            perror("stat");
            continue;
        }

        if (S_ISREG(entry_info.st_mode)) {
            size += entry_info.st_size;
        } else if (S_ISDIR(entry_info.st_mode) && num_threads < MAX_THREADS) {
            pthread_t tid;
            struct thread_args child_args = { .dirname = path, .id = targs->id + 1 };
            pthread_create(&tid, NULL, analyze_directory, &child_args);
            pthread_mutex_lock(&mutex);
            num_threads++;
            pthread_mutex_unlock(&mutex);
        }
    }

    printf("Directory [%d]: %s, Size: %lld bytes\n", targs->id, dirname, size);
    closedir(dirp);
    pthread_mutex_lock(&mutex);
    num_threads--;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* dirname = argv[1];
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid;

    struct thread_args targs = { .dirname = dirname, .id = 0 };
    pthread_create(&tid, NULL, analyze_directory, &targs);
    num_threads++;

    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}