//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_PATH 1024 /* Maximum path length */
#define MAX_BUF 1024 /* Maximum buffer length */

typedef struct file_synchronizer {
    char *src_path;
    char *dest_path;
} file_synchronizer_t;

/* Mutex locks */
pthread_mutex_t src_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dest_lock = PTHREAD_MUTEX_INITIALIZER;

/* Function to copy a file from source to destination */
void copy_file(const char *src_path, const char *dest_path) {
    fprintf(stdout, "Copying %s to %s\n", src_path, dest_path);
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    size_t bytes_read = 0;
    char buf[MAX_BUF];
    while ((bytes_read = fread(buf, 1, MAX_BUF, src_file)) > 0) {
        fwrite(buf, 1, bytes_read, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
}

/* Function to recursively synchronize files from source to destination */
void *sync_files(void *arg) {
    file_synchronizer_t *fs = (file_synchronizer_t *)arg;
    char src[MAX_PATH], dest[MAX_PATH];
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    if ((dir = opendir(fs->src_path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(src, MAX_PATH, "%s/%s", fs->src_path, entry->d_name);
            snprintf(dest, MAX_PATH, "%s/%s", fs->dest_path, entry->d_name);
            if (lstat(src, &statbuf) == -1) {
                perror(src);
                continue;
            }
            if (S_ISREG(statbuf.st_mode)) { /* Regular file */
                pthread_mutex_lock(&src_lock); /* Lock the source file */
                pthread_mutex_lock(&dest_lock); /* Lock the destination file to prevent race conditions */
                copy_file(src, dest); /* Copy the file */
                pthread_mutex_unlock(&src_lock); /* Unlock the source file */
                pthread_mutex_unlock(&dest_lock); /* Unlock the destination file */
            } else if (S_ISDIR(statbuf.st_mode)) { /* Directory */
                mkdir(dest, statbuf.st_mode); /* Create the directory in destination */
                file_synchronizer_t sub_dir_fs = {
                    .src_path = src,
                    .dest_path = dest
                };
                pthread_t tid;
                pthread_create(&tid, NULL, &sync_files, &sub_dir_fs); /* Recursively synchronize the subdirectory */
                pthread_join(tid, NULL);
            }
        }
        closedir(dir);
    } else {
        fprintf(stderr, "Error opening directory %s: %s\n", fs->src_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Allocate memory for the file synchronizer structure */
    file_synchronizer_t *fs = malloc(sizeof(file_synchronizer_t));
    if (fs == NULL) {
        fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fs->src_path = argv[1];
    fs->dest_path = argv[2];
    pthread_t tid;
    pthread_create(&tid, NULL, &sync_files, fs); /* Start synchronizing the files */
    pthread_join(tid, NULL);
    free(fs);
    return EXIT_SUCCESS;
}