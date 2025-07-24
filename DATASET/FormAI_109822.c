//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 1000
#define MAX_NAME_LENGTH 16

struct directory {
    char name[MAX_NAME_LENGTH];
    int file_count;
    char files[MAX_FILES][MAX_NAME_LENGTH];
} root_dir;

void create_directory(char *name) {
    struct directory new_dir;
    strcpy(new_dir.name, name);
    new_dir.file_count = 0;
    memset(new_dir.files, 0, MAX_FILES*MAX_NAME_LENGTH);

    // add new_dir to root_dir's files
    strcpy(root_dir.files[root_dir.file_count], new_dir.name);
    root_dir.file_count += 1;

    printf("Directory '%s' created successfully!\n", name);
}

void create_file(char *filename) {
    // check if file already exists
    for (int i = 0; i < root_dir.file_count; i++) {
        if (strcmp(root_dir.files[i], filename) == 0) {
            printf("File '%s' already exists!\n", filename);
            return;
        }
    }

    if (root_dir.file_count >= MAX_FILES) {
        printf("Max file limit reached! Cannot create file '%s'\n", filename);
        return;
    }

    // add filename to root_dir's files
    strcpy(root_dir.files[root_dir.file_count], filename);
    root_dir.file_count += 1;

    printf("File '%s' created successfully!\n", filename);
}

int main() {
    // initialize root directory
    strcpy(root_dir.name, "/");
    root_dir.file_count = 0;
    memset(root_dir.files, 0, MAX_FILES*MAX_NAME_LENGTH);

    printf("\n\t\tFILE SYSTEM SIMULATOR\n");
    printf("Commands:\n");
    printf("\t- mkdir [directory_name]\n");
    printf("\t- touch [file_name]\n");
    printf("\t- list\n");
    printf("\t- exit\n");

    char input[256];
    while (1) {
        printf("\n$ ");
        scanf(" %[^\n]%*c", input);

        char *cmd = strtok(input, " ");

        if (cmd == NULL || (strcmp(cmd, "exit") == 0)) {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(cmd, "mkdir") == 0) {
            char *name = strtok(NULL, " ");
            if (name == NULL) {
                printf("Error: missing directory name\n");
                continue;
            }
            create_directory(name);
        }
        else if (strcmp(cmd, "touch") == 0) {
            char *name = strtok(NULL, " ");
            if (name == NULL) {
                printf("Error: missing file name\n");
                continue;
            }
            create_file(name);
        }
        else if (strcmp(cmd, "list") == 0) {
            printf("Contents of root directory:\n");
            printf("- %s (directory)\n", root_dir.name);
            for (int i = 0; i < root_dir.file_count; i++) {
                printf("- %s\n", root_dir.files[i]);
            }
        }
        else {
            printf("Invalid command. Type 'exit' to quit.\n");
        }
    }

    return 0;
}