//FormAI DATASET v1.0 Category: File Backup System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 100
#define MAX_FILES 10
#define FILE_CONTENT_SIZE 100

typedef struct {
    char filename[FILENAME_LEN];
    char content[FILE_CONTENT_SIZE];
} file;

typedef struct {
    file files[MAX_FILES];
    int num_files;
} backup;

void backup_file(backup *b, char *filename, char *content) {
    if (b->num_files < MAX_FILES) {
        file f;
        strcpy(f.filename, filename);
        strcpy(f.content, content);
        b->files[b->num_files++] = f;
        printf("File backed up: %s\n", filename);
    } else {
        printf("Backup is full. Cannot backup file: %s\n", filename);
    }
}

void display_backup(backup *b) {
    if (b->num_files == 0) {
        printf("Backup is empty.\n");
    } else {
        printf("Files in backup:\n");
        for (int i = 0; i < b->num_files; i++) {
            printf("%s: %s\n", b->files[i].filename, b->files[i].content);
        }
    }
}

int main() {
    backup b;
    b.num_files = 0;

    // Backup some files
    backup_file(&b, "file1.txt", "contents of file1");
    backup_file(&b, "file2.txt", "contents of file2");
    backup_file(&b, "file3.txt", "contents of file3");
    backup_file(&b, "file4.txt", "contents of file4");

    // Display backup
    display_backup(&b);

    // Try to backup more files than allowed
    backup_file(&b, "file5.txt", "contents of file5");
    backup_file(&b, "file6.txt", "contents of file6");

    // Display backup again
    display_backup(&b);

    return 0;
}