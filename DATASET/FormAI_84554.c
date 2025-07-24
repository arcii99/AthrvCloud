//FormAI DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_FILENAME 100

typedef struct {
    char name[MAX_FILENAME];
    time_t last_modified;
} file_entry;

file_entry files[MAX_FILES];
int file_count = 0;

void add_file(char *filename) {
    if (file_count >= MAX_FILES) {
        printf("Too many files!\n");
        return;
    }
    strncpy(files[file_count].name, filename, MAX_FILENAME);
    files[file_count].last_modified = time(NULL);
    file_count++;
    printf("File %s added successfully!\n", filename);
}

void remove_file(char *filename) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            files[i] = files[file_count - 1];
            file_count--;
            printf("File %s removed successfully!\n", filename);
            return;
        }
    }
    printf("File %s not found!\n", filename);
}

void list_files() {
    int i;
    printf("Files:\n");
    for (i = 0; i < file_count; i++) {
        printf("%s last modified on %s", files[i].name, ctime(&files[i].last_modified));
    }
}

void backup_files() {
    FILE *fp;
    int i;
    char backup_filename[MAX_FILENAME+5];
    time_t now = time(NULL);
    strftime(backup_filename, MAX_FILENAME+5, "backup_%Y%m%d%H%M%S", localtime(&now));
    fp = fopen(backup_filename, "w");
    if (fp == NULL) {
        printf("Error creating backup file!\n");
        return;
    }
    for (i = 0; i < file_count; i++) {
        fprintf(fp, "%s,%ld\n", files[i].name, files[i].last_modified);
    }
    fclose(fp);
    printf("Backup created with filename %s\n", backup_filename);
}

int main() {
    char buffer[100];
    while(1) {
        printf("Enter command: ");
        fgets(buffer, 100, stdin);
        if (strncmp(buffer, "add ", 4) == 0) {
            add_file(buffer+4);
        } else if (strncmp(buffer, "remove ", 7) == 0) {
            remove_file(buffer+7);
        } else if (strncmp(buffer, "list", 4) == 0) {
            list_files();
        } else if (strncmp(buffer, "backup", 6) == 0) {
            backup_files();
        } else {
            printf("Unknown command!\n");
        }
    }
    return 0;
}