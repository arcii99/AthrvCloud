//FormAI DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_DIRECTORY_NAME 100

typedef struct File {
    char filename[MAX_FILENAME];
    char directory[MAX_DIRECTORY_NAME];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void backup_add_file(char *filename, char *directory, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }
    
    strcpy(files[num_files].filename, filename);
    strcpy(files[num_files].directory, directory);
    files[num_files].size = size;
    
    num_files++;
    
    printf("File backed up successfully: %s\n", filename);
}

void backup_list_files() {
    printf("List of backed up files:\n");
    
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }
}

void backup_restore_file(char *filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("Restoring file: %s\n", files[i].filename);
            printf("File size: %d bytes\n", files[i].size);
            return;
        }
    }
    
    printf("Error: File not found\n");
}

int main(void) {
    backup_add_file("file1.txt", "/user/documents", 1024);
    backup_add_file("file2.jpg", "/user/pictures", 2048);
    backup_add_file("file3.doc", "/user/documents", 3072);
    backup_add_file("file4.png", "/user/pictures", 4096);
    backup_list_files();
    backup_restore_file("file2.jpg");
    
    return 0;
}