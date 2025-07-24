//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 256

pthread_mutex_t mutex;

void file_copy(char* source_path, char* dest_path) {
    FILE* source_file = fopen(source_path, "rb");
    FILE* dest_file = fopen(dest_path, "wb");
    if (source_file == NULL || dest_file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    int nbyte;
    char buffer[BUFSIZ];
    while ((nbyte = fread(buffer, sizeof(char), BUFSIZ, source_file)) > 0) {
        fwrite(buffer, sizeof(char), nbyte, dest_file);
    }
    fclose(source_file);
    fclose(dest_file);
}

void* synchronize_files(void* args) {
    char* source_dir = ((char**)args)[0];
    char* dest_dir = ((char**)args)[1];
    DIR* source_dp = opendir(source_dir);
    DIR* dest_dp = opendir(dest_dir);
    if (source_dp == NULL || dest_dp == NULL) {
        printf("Unable to open directory.\n");
        exit(1);
    }
    struct dirent* source_dentry;
    while ((source_dentry = readdir(source_dp)) != NULL) {
        if (source_dentry->d_name[0] == '.') {
            continue;
        }
        char source_path[MAX_PATH_LENGTH], dest_path[MAX_PATH_LENGTH];
        sprintf(source_path, "%s/%s", source_dir, source_dentry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, source_dentry->d_name);
        struct stat source_buf, dest_buf;
        int source_ret = stat(source_path, &source_buf);
        int dest_ret = stat(dest_path, &dest_buf);
        if (S_ISREG(source_buf.st_mode)) {
            if (dest_ret == -1) {
                printf("File %s not found in destination directory. Copying file...\n", source_dentry->d_name);
                file_copy(source_path, dest_path);
                printf("File %s copied successfully.\n", source_dentry->d_name);
            } else if (S_ISREG(dest_buf.st_mode)) {
                if (source_buf.st_mtime > dest_buf.st_mtime) {
                    printf("File %s in destination directory is outdated. Updating file...\n", source_dentry->d_name);
                    file_copy(source_path, dest_path);
                    printf("File %s updated successfully.\n", source_dentry->d_name);
                }
            }
        } else if (S_ISDIR(source_buf.st_mode)) {
            if (dest_ret == -1) {
                printf("Directory %s not found in destination directory. Creating directory...\n", source_dentry->d_name);
                mkdir(dest_path, S_IRWXU | S_IRWXG | S_IRWXO);
                printf("Directory %s created successfully.\n", source_dentry->d_name);
            } else if (S_ISDIR(dest_buf.st_mode)) {
                char* subdirs[2] = {source_path, dest_path};
                pthread_t thread;
                pthread_mutex_lock(&mutex);
                pthread_create(&thread, NULL, synchronize_files, subdirs);
                pthread_mutex_unlock(&mutex);
                pthread_join(thread, NULL);
            }
        }
    }
    closedir(source_dp);
    closedir(dest_dp);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments. Usage: ./sync_files <source_dir> <dest_dir>\n");
        exit(1);
    }
    char* source_dir = (char*)argv[1];
    char* dest_dir = (char*)argv[2];
    pthread_mutex_init(&mutex, NULL);
    char* dirs[2] = {source_dir, dest_dir};
    pthread_t thread;
    pthread_create(&thread, NULL, synchronize_files, dirs);
    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);
    printf("File synchronization complete.\n");
    return 0;
}