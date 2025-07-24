//FormAI DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>

#define MAX_FILE_SIZE 1024 // 1 KB
#define MAX_FILE_NAME_LENGTH 20 // 20 characters
#define MAX_NUM_FILES 10 // can hold up to 10 files

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} file;

file file_system[MAX_NUM_FILES];

int num_files = 0;
int total_size = 0;

void create_file(char* name, int size) {
    if (num_files < MAX_NUM_FILES && total_size + size <= MAX_NUM_FILES) {
        file new_file;
        strcpy(new_file.name, name);
        new_file.size = size;
        memset(new_file.data, 0, sizeof(new_file.data));
        file_system[num_files] = new_file;
        num_files++;
        total_size += size;
        printf("Successfully created file named %s with size %d\n", name, size);
    } else {
        printf("File creation failed. Maximum number of files or disk space exceeded.\n");
    }
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            total_size -= file_system[i].size;
            memmove(&file_system[i], &file_system[i+1], sizeof(file) * (num_files - i - 1));
            num_files--;
            printf("Successfully deleted file named %s\n", name);
            return;
        }
    }
    printf("File deletion failed. File not found.\n");
}

void list_files() {
    int i;
    printf("File System contains %d files:\n", num_files);
    for (i = 0; i < num_files; i++) {
        printf("%s - %d Bytes\n", file_system[i].name, file_system[i].size);
    }
}

int main() {
    char input[50];
    char name[MAX_FILE_NAME_LENGTH];
    int size;

    while(1) {
        printf("Enter a command (create, delete, list): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "create\n") == 0) {
            printf("Enter file name (up to %d characters): ", MAX_FILE_NAME_LENGTH - 1);
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0'; // remove newline character
            printf("Enter file size (up to %d Bytes): ", MAX_FILE_SIZE);
            scanf("%d", &size);
            getchar(); // remove newline character

            create_file(name, size);

        } else if (strcmp(input, "delete\n") == 0) {
            printf("Enter file name: ");
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0'; // remove newline character

            delete_file(name);

        } else if (strcmp(input, "list\n") == 0) {
            list_files();

        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}