//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILENAME_SIZE 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct {
    char name[MAX_FILENAME_SIZE];
    File files[MAX_FILES];
    int file_count;
    int used_space;
} Directory;

Directory root;

void create_file(char* filename, char* data, int size) {
    if (root.file_count >= MAX_FILES) {
        printf("File system full.\n");
        return;
    }
    File new_file;
    strcpy(new_file.filename, filename);
    new_file.size = size;
    strcpy(new_file.data, data);
    root.files[root.file_count++] = new_file;
    root.used_space += size;
    printf("File %s created.\n", filename);
}

void delete_file(char* filename) {
    int i;
    for (i = 0; i < root.file_count; i++) {
        if (strcmp(root.files[i].filename, filename) == 0) {
            root.used_space -= root.files[i].size;
            int j;
            for (j = i; j < root.file_count - 1; j++) {
                root.files[j] = root.files[j + 1];
            }
            root.file_count--;
            printf("File %s deleted.\n", filename);
            return;
        }
    }
    printf("File not found.\n");
}

void list_files() {
    int i;
    for (i = 0; i < root.file_count; i++) {
        printf("%s (%d bytes)\n", root.files[i].filename, root.files[i].size);
    }
    printf("%d/%d files (%d/%d bytes used)\n", root.file_count, MAX_FILES, root.used_space, MAX_FILES * MAX_FILE_SIZE);
}

int main() {
    strcpy(root.name, "root");
    root.file_count = 0;
    root.used_space = 0;
    
    printf("Welcome to Cyberfile.\n");
    printf("Enter a command (create [filename] [size] [data], delete [filename], list):\n");
    
    char input[100];
    char command[10], filename[MAX_FILENAME_SIZE], data[MAX_FILE_SIZE];
    int size;
    
    while (fgets(input, 100, stdin)) {
        sscanf(input, "%s %s %d %[^\n]", command, filename, &size, data);
        if (strcmp(command, "create") == 0) {
            create_file(filename, data, size);
        } else if (strcmp(command, "delete") == 0) {
            delete_file(filename);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command.\n");
        }
        printf("Enter a command (create [filename] [size] [data], delete [filename], list):\n");
    }
    
    return 0;
}