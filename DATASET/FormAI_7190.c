//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024
#define MAX_FILE_NAME 32

typedef struct File {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
} file_t;

typedef struct FileSystem {
    file_t files[MAX_FILES];
    int num_files;
    int total_size;
} fs_t;

void init_fs(fs_t *fs) {
    fs->num_files = 0;
    fs->total_size = 0;
}

void create_file(fs_t *fs, char *name, char *data) {
    if (fs->num_files == MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    int size = strlen(data);
    if (size > MAX_FILE_SIZE) {
        printf("Error: File too large\n");
        return;
    }

    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File already exists\n");
            return;
        }
    }

    file_t new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    strcpy(new_file.data, data);

    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->total_size += size;

    printf("File created successfully\n");
}

void delete_file(fs_t *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->total_size -= fs->files[i].size;
            fs->num_files--;
            fs->files[i] = fs->files[fs->num_files];
            printf("File deleted successfully\n");
            return;
        }
    }

    printf("Error: File not found\n");
}

void list_files(fs_t *fs) {
    printf("Total Files: %d\n", fs->num_files);

    int i;
    for (i = 0; i < fs->num_files; i++) {
        file_t file = fs->files[i];
        printf("%s (%d bytes)\n", file.name, file.size);
    }
}

void print_menu() {
    printf("\nFileSystem Simulation\n");
    printf("----------------------\n");
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. List Files\n");
    printf("4. Exit\n");
}

int main() {
    fs_t fs;
    init_fs(&fs);

    int choice;
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];

    do {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file data: ");
                scanf(" %[^\n]", data);
                create_file(&fs, name, data);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            case 3:
                list_files(&fs);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}