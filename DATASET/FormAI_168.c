//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_BACKUPS 10

char files[MAX_FILES][256];
int num_files;

char backups[MAX_BACKUPS][256];
int num_backups = 0;

pthread_mutex_t mutex_files;
pthread_mutex_t mutex_backups;

void *backup_thread(void *arg) {
    int backup_num = *(int*)arg;
    printf("Starting backup %d...\n", backup_num);

    pthread_mutex_lock(&mutex_files);
    for (int i = 0; i < num_files; i++) {
        // Copy file to backup directory
        printf("Backing up file %s to %s...\n", files[i], backups[backup_num]);
    }
    pthread_mutex_unlock(&mutex_files);

    printf("Backup %d complete.\n", backup_num);

    pthread_exit(NULL);
}

int main() {
    // Initialize file list
    FILE *file_list = fopen("file_list.txt", "r");
    if (file_list == NULL) {
        perror("Failed to open file_list.txt");
        return 1;
    }

    pthread_mutex_init(&mutex_files, NULL);
    pthread_mutex_init(&mutex_backups, NULL);

    char filename[256];
    while (fgets(filename, 256, file_list) != NULL) {
        // Remove newline character
        int len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }
        // Add filename to list
        pthread_mutex_lock(&mutex_files);
        strncpy(files[num_files], filename, sizeof(files[num_files]));
        num_files++;
        pthread_mutex_unlock(&mutex_files);
    }

    fclose(file_list);

    printf("Files to backup:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]);
    }

    // Initialize backup directory list
    FILE *backup_list = fopen("backup_list.txt", "r");
    if (backup_list == NULL) {
        perror("Failed to open backup_list.txt");
        return 1;
    }

    char backup_dir[256];
    while (fgets(backup_dir, 256, backup_list) != NULL) {
        // Remove newline character
        int len = strlen(backup_dir);
        if (len > 0 && backup_dir[len - 1] == '\n') {
            backup_dir[len - 1] = '\0';
        }
        // Add backup directory to list
        pthread_mutex_lock(&mutex_backups);
        strncpy(backups[num_backups], backup_dir, sizeof(backups[num_backups]));
        num_backups++;
        pthread_mutex_unlock(&mutex_backups);
    }

    fclose(backup_list);

    printf("Backup directories:\n");
    for (int i = 0; i < num_backups; i++) {
        printf("%s\n", backups[i]);
    }

    // Start backup threads
    pthread_t threads[num_backups];
    for (int i = 0; i < num_backups; i++) {
        int *backup_num = malloc(sizeof(int));
        *backup_num = i;

        pthread_create(&threads[i], NULL, backup_thread, (void*)backup_num);
    }

    // Wait for backup threads to finish
    for (int i = 0; i < num_backups; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex_files);
    pthread_mutex_destroy(&mutex_backups);

    return 0;
}