//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 255
#define BUFFER_LEN 1024
#define THREAD_COUNT 4

struct DirInfo {
    char path[MAX_PATH];
    size_t size;
};

void addDirInfo(struct DirInfo *di, const char *path, size_t size) {
    strcpy(di->path, path);
    di->size = size;
}

void analyzeDir(struct DirInfo *di, char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, ".", 1) == 0) {
            continue;
        }

        char fullpath[MAX_PATH];
        snprintf(fullpath, MAX_PATH, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            analyzeDir(di, fullpath);
        } else {
            size_t size = 0;

            FILE *file = fopen(fullpath, "rb");
            if (file) {
                fseek(file, 0, SEEK_END);
                size = ftell(file);
                fclose(file);
            }

            di->size += size;
        }
    }

    closedir(dir);
}

void *analyzeThread(void *args) {
    struct DirInfo *di = (struct DirInfo *) args;
    analyzeDir(di, di->path);

    return NULL;
}

int main(int argc, char *argv[]) {
    const char *dirPath = "/";
    size_t totalSize = 0;
    struct DirInfo dirList[THREAD_COUNT];
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        addDirInfo(&dirList[i], dirPath, 0);
        pthread_create(&threads[i], NULL, analyzeThread, &dirList[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        totalSize += dirList[i].size;
        printf("Directory %s has size %ld bytes\n", dirList[i].path, dirList[i].size);
    }

    printf("Total size of directory %s is %ld bytes\n", dirPath, totalSize);

    return 0;
}