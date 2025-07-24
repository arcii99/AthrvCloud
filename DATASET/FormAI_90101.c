//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char *data;
} File;

File files[MAX_FILES];
int free_space = MAX_FILES * MAX_FILE_SIZE;

void create_file(char *name, char *data) {
    if (strlen(name) > MAX_FILE_NAME) {
        printf("Error: Filename is too long\n");
        return;
    }

    if (free_space < strlen(data)) {
        printf("Error: Not enough memory\n");
        return;
    }

    File file;

    strcpy(file.name, name);
    file.size = strlen(data);
    file.data = (char *) malloc(file.size + 1);
    strcpy(file.data, data);

    files[MAX_FILES - (free_space / MAX_FILE_SIZE) - 1] = file;
    free_space -= file.size;

    printf("File '%s' created successfully!\n", name);
}

void delete_file(char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].data);
            files[i].name[0] = '\0';
            free_space += files[i].size;

            printf("File '%s' deleted successfully!\n", name);
            return;
        }
    }

    printf("Error: File '%s' not found\n", name);
}

void display_files() {
    printf("Files:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] != '\0') {
            printf("'%s' (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter a command (create, delete, display, exit): ");
        fgets(input, sizeof(input), stdin);

        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0'; // Remove newline character from input

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "create") == 0) {
            char name[MAX_FILE_NAME];
            char data[MAX_FILE_SIZE];

            printf("Enter a filename: ");
            fgets(name, sizeof(name), stdin);
            len = strlen(name);
            if (len > 0 && name[len - 1] == '\n') name[len - 1] = '\0'; // Remove newline character from filename

            printf("Enter file data: ");
            fgets(data, sizeof(data), stdin);
            len = strlen(data);
            if (len > 0 && data[len - 1] == '\n') data[len - 1] = '\0'; // Remove newline character from file data

            create_file(name, data);
        } else if (strcmp(input, "delete") == 0) {
            char name[MAX_FILE_NAME];
            printf("Enter a filename: ");
            fgets(name, sizeof(name), stdin);
            len = strlen(name);
            if (len > 0 && name[len - 1] == '\n') name[len - 1] = '\0'; // Remove newline character from filename

            delete_file(name);
        } else if (strcmp(input, "display") == 0) {
            display_files();
        } else {
            printf("Error: Invalid command\n");
        }

        printf("\n");
    }

    return 0;
}