//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h> 
#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 4

pthread_t threads[THREAD_COUNT];
sem_t semaphores[THREAD_COUNT];

struct sync_data {
    char* src_dir;
    char* dest_dir;
};

void copy_file(char* src_path, char* dest_path) {
    FILE *src_file, *dest_file;
    char buffer[1024];
    size_t bytes_read, bytes_written;

    src_file = fopen(src_path, "rb");
    dest_file = fopen(dest_path, "wb");

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_read != bytes_written) {
            printf("Error while writing to %s\n", dest_path);
            break;
        }
    }

    fclose(src_file);
    fclose(dest_file);
}

void sync_directory(char* src_dir, char* dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[1024], dest_path[1024];
    struct stat st;

    if ((dir = opendir(src_dir)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.') {
                continue;
            }

            sprintf(src_path, "%s/%s", src_dir, entry->d_name);
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

            if (stat(src_path, &st) == -1) {
                printf("Error while getting the stats of %s\n", src_path);
                continue;
            }

            if (S_ISREG(st.st_mode)) {
                struct tm* modified_time = localtime(&st.st_mtime);
                printf("Checking %s ...\n", src_path);

                if (access(dest_path, F_OK) == -1) {
                    // file does not exist in dest dir, copy it over
                    printf("%s does not exist in %s, copying...\n", src_path, dest_dir);
                    copy_file(src_path, dest_path);
                } else {
                    // file exists in dest dir, compare modified time
                    struct stat dest_st;
                    stat(dest_path, &dest_st);

                    struct tm* dest_modified_time = localtime(&dest_st.st_mtime);

                    if (difftime(mktime(modified_time), mktime(dest_modified_time)) > 0) {
                        printf("%s in %s is older than %s in %s, copying over...\n", dest_path, dest_dir, src_path, src_dir);
                        copy_file(src_path, dest_path);
                    }
                }
            } else if (S_ISDIR(st.st_mode)) {
                sync_directory(src_path, dest_path);
            }
        }
        closedir (dir);
    } else {
        printf("Error while opening %s\n", src_dir);
    }
}

void* sync_worker(void* arg) {
    sem_wait((sem_t*) arg);

    struct sync_data* sync_data = (struct sync_data*) arg;

    sync_directory(sync_data->src_dir, sync_data->dest_dir);

    sem_post((sem_t*) arg);

    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        sem_init(&semaphores[i], 0, 1);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, sync_worker, &(struct sync_data) { .src_dir = argv[1], .dest_dir = argv[2], });
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        sem_destroy(&semaphores[i]);
    }

    printf("Synchronization complete!\n");

    return 0;
}