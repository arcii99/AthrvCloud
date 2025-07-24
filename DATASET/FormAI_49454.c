//FormAI DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 20

typedef struct BackupFile {
    char filename[MAX_FILENAME_LEN];
    time_t timestamp;
} BackupFile;

BackupFile* create_backup_file(char* filename);
void print_all_files(BackupFile** files, int num_files);
void delete_old_files(BackupFile** files, int* num_files);
int compare_files(const void* a, const void* b);

int main() {
    srand(time(NULL));
    int num_files = 0;
    BackupFile** files = malloc(sizeof(BackupFile*) * 10);
    while (num_files < 10) {
        char filename[MAX_FILENAME_LEN];
        for (int i = 0; i < MAX_FILENAME_LEN - 1; i++) {
            filename[i] = rand() % 26 + 'a';
        }
        filename[MAX_FILENAME_LEN - 1] = '\0';
        BackupFile* file = create_backup_file(filename);
        files[num_files++] = file;
    }
    printf("Initial backup files:\n");
    print_all_files(files, num_files);
    delete_old_files(files, &num_files);
    printf("After deleting old files:\n");
    print_all_files(files, num_files);
    for (int i = 0; i < num_files; i++) {
        free(files[i]);
    }
    free(files);
    return 0;
}

BackupFile* create_backup_file(char* filename) {
    BackupFile* file = malloc(sizeof(BackupFile));
    strncpy(file->filename, filename, MAX_FILENAME_LEN - 1);
    file->filename[MAX_FILENAME_LEN - 1] = '\0';
    file->timestamp = time(NULL);
    return file;
}

void print_all_files(BackupFile** files, int num_files) {
    qsort(files, num_files, sizeof(BackupFile*), compare_files);
    printf("Filename\tTimestamp\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d\n", files[i]->filename, files[i]->timestamp);
    }
}

void delete_old_files(BackupFile** files, int* num_files) {
    time_t current_time = time(NULL);
    int i = 0;
    while (i < *num_files) {
        if (current_time - files[i]->timestamp > 3600) { // delete if older than 1 hour
            free(files[i]);
            for (int j = i; j < *num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            (*num_files)--;
        } else {
            i++;
        }
    }
}

int compare_files(const void* a, const void* b) {
    BackupFile* file1 = *(BackupFile**)a;
    BackupFile* file2 = *(BackupFile**)b;
    return file1->timestamp - file2->timestamp;
}