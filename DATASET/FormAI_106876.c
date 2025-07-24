//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define THREADS_NUM 3
#define MAX_FILES_BACKUP 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char backup_path[50] = "/home/user/backup"; // example backup path

typedef struct {
    char file_path[50];
    char backup_file_path[50];
} backup_info;

backup_info files_to_backup[MAX_FILES_BACKUP] = {
    {"/home/user/Desktop/file1.txt", "/home/user/backup/file1.txt"},
    {"/home/user/Documents/file2.txt", "/home/user/backup/file2.txt"},
    {"/home/user/Pictures/file3.jpg", "/home/user/backup/file3.jpg"},
    {"/home/user/Music/file4.mp3", "/home/user/backup/file4.mp3"},
    {"/home/user/Videos/file5.mp4", "/home/user/backup/file5.mp4"}
};

void *backup_file(void *args) {
    backup_info *file_info = args;
    printf("Backing up file %s...\n", file_info->file_path);
    pthread_mutex_lock(&mutex);
    FILE *source_file = fopen(file_info->file_path, "r");
    FILE *destination_file = fopen(file_info->backup_file_path, "w");
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file))) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }
    fclose(source_file);
    fclose(destination_file);
    pthread_mutex_unlock(&mutex);
    printf("File %s backed up successfully.\n", file_info->file_path);
    return NULL;
}

int main() {
    // create backup directory if it does not exist
    DIR* backup_dir = opendir(backup_path);
    if (!backup_dir) {
        mkdir(backup_path, 0777);
    } else {
        closedir(backup_dir);
    }

    // create backup threads
    pthread_t backup_threads[THREADS_NUM];
    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_create(&backup_threads[i], NULL, backup_file, (void *)&files_to_backup[i]);
    }

    // wait for backup threads to finish
    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_join(backup_threads[i], NULL);
    }

    printf("All files backed up successfully!\n");

    return 0;
}