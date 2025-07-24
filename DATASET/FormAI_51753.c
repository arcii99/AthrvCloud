//FormAI DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_NUM_FILES 10

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int file_size;
} file;

file file_system[MAX_NUM_FILES];
int num_files = 0;
int total_space = 1000; // in KB
int used_space = 0; // in KB

void add_file(char* filename, int file_size) {
    if (num_files >= MAX_NUM_FILES) {
        printf("No more space to add files.\n");
        return;
    }
    if (file_size > total_space - used_space) {
        printf("Not enough space to add the file.\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            printf("Filename already exists.\n");
            return;
        }
    }
    file new_file;
    strcpy(new_file.filename, filename);
    new_file.file_size = file_size;
    file_system[num_files++] = new_file;
    used_space += file_size;
    printf("File added successfully.\n");
}

void delete_file(char* filename) {
    int file_deleted = 0;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            used_space -= file_system[i].file_size;
            for (int j = i; j < num_files - 1; j++) {
                file_system[j] = file_system[j+1];
            }
            num_files--;
            file_deleted = 1;
            printf("File deleted successfully.\n");
            break;
        }
    }
    if (!file_deleted) {
        printf("File not found.\n");
    }
}

void print_files() {
    printf("File System Contents\n");
    printf("--------------------\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s - %d KB\n", file_system[i].filename, file_system[i].file_size);
    }
    printf("Total Space: %d KB\n", total_space);
    printf("Used Space: %d KB\n", used_space);
    printf("Free Space: %d KB\n", total_space - used_space);
}

int main() {
    char command[100];
    char filename[MAX_FILENAME_LEN];
    int file_size;
    while (1) {
        printf("Enter command (add/delete/print): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter file size (in KB): ");
            scanf("%d", &file_size);
            add_file(filename, file_size);
        }
        else if (strcmp(command, "delete") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            delete_file(filename);
        }
        else if (strcmp(command, "print") == 0) {
            print_files();
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}