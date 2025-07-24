//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LEN 50
#define MAX_FILE_SIZE 1000

// Represents a file in the file system
typedef struct {
    char name[MAX_NAME_LEN];
    char data[MAX_FILE_SIZE];
    int size;
    int in_use;
} File;

// Represents the file system
typedef struct {
    File files[MAX_FILES];
    int num_files;
} FileSystem;

// Initializes the file system
void init_fs(FileSystem* fs) {
    fs->num_files = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].in_use = 0;
    }
}

// Creates a new file with the given name in the file system
void create_file(FileSystem* fs, char* name) {
    if (fs->num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File with name '%s' already exists\n", name);
            return;
        }
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = 0;
    new_file.in_use = 1;
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    printf("File '%s' created successfully\n", name);
}

// Deletes the file with the given name from the file system
void delete_file(FileSystem* fs, char* name) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    fs->files[index].in_use = 0;
    printf("File '%s' deleted successfully\n", name);
}

// Writes data to the file with the given name in the file system
void write_file(FileSystem* fs, char* name, char* data) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    strcpy(fs->files[index].data, data);
    fs->files[index].size = strlen(data);
    printf("Data written to file '%s' successfully\n", name);
}

// Reads data from the file with the given name in the file system
void read_file(FileSystem* fs, char* name) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File with name '%s' not found\n", name);
        return;
    }
    printf("%s\n", fs->files[index].data);
}

int main() {
    FileSystem fs;
    init_fs(&fs);
    printf("Welcome to the File System\n");
    while (1) {
        printf("Enter command (create, delete, write, read, exit): ");
        char command[MAX_NAME_LEN];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            create_file(&fs, name);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            delete_file(&fs, name);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter file name: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            printf("Enter file data: ");
            char data[MAX_FILE_SIZE];
            scanf(" %[^\t\n]s", data);
            write_file(&fs, name, data);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            read_file(&fs, name);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: Invalid command\n");
        }
    }
    return 0;
}