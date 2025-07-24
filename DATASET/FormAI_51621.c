//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char* data;
} File;

typedef struct directory {
    char name[MAX_FILENAME_LENGTH];
    struct directory* parent;
    File** files;
    struct directory** subdirectories;
    int num_files;
    int num_subdirectories;
} Directory;

void create_file(Directory* dir) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->name, filename);
    printf("Enter file size (max %d bytes): ", MAX_FILE_SIZE);
    scanf("%d", &new_file->size);
    new_file->data = malloc(new_file->size);
    printf("Enter file data: ");
    scanf("%s", new_file->data);
    dir->files[dir->num_files++] = new_file;
    printf("File created successfully.\n\n");
}

void create_directory(Directory* dir) {
    char dirname[MAX_FILENAME_LENGTH];
    printf("Enter directory name: ");
    scanf("%s", dirname);
    Directory* new_directory = malloc(sizeof(Directory));
    strcpy(new_directory->name, dirname);
    new_directory->parent = dir;
    dir->subdirectories[dir->num_subdirectories++] = new_directory;
    printf("Directory created successfully.\n\n");
}

void delete_file_or_directory(Directory* dir) {
    char name[MAX_FILENAME_LENGTH];
    printf("Enter name of file or directory to delete: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(name, dir->files[i]->name) == 0) {
            free(dir->files[i]->data);
            free(dir->files[i]);
            for (; i < dir->num_files - 1; i++) {
                dir->files[i] = dir->files[i+1];
            }
            dir->num_files--;
            printf("File deleted successfully.\n\n");
            return;
        }
    }
    for (i = 0; i < dir->num_subdirectories; i++) {
        if (strcmp(name, dir->subdirectories[i]->name) == 0) {
            delete_directory(dir->subdirectories[i]);
            for (; i < dir->num_subdirectories - 1; i++) {
                dir->subdirectories[i] = dir->subdirectories[i+1];
            }
            dir->num_subdirectories--;
            printf("Directory deleted successfully.\n\n");
            return;
        }
    }
    printf("File/directory not found.\n\n");
}

void delete_directory(Directory* dir) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        free(dir->files[i]->data);
        free(dir->files[i]);
    }
    free(dir->files);
    for (i = 0; i < dir->num_subdirectories; i++) {
        delete_directory(dir->subdirectories[i]);
    }
    free(dir->subdirectories);
    free(dir);
}

void display_file_contents(Directory* dir) {
    char name[MAX_FILENAME_LENGTH];
    printf("Enter name of file to display: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(name, dir->files[i]->name) == 0) {
            printf("File contents:\n%s\n\n", dir->files[i]->data);
            return;
        }
    }
    printf("File not found.\n\n");
}

void display_directory_contents(Directory* dir) {
    printf("Contents of directory %s:\n", dir->name);
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s (file)\n", dir->files[i]->name);
    }
    for (i = 0; i < dir->num_subdirectories; i++) {
        printf("%s (directory)\n", dir->subdirectories[i]->name);
    }
    if (dir->num_files == 0 && dir->num_subdirectories == 0) {
        printf("(empty)\n");
    }
    printf("\n");
}

int main() {
    Directory* root = malloc(sizeof(Directory));
    strcpy(root->name, "/");
    root->parent = NULL;
    root->files = malloc(0);
    root->subdirectories = malloc(0);
    root->num_files = 0;
    root->num_subdirectories = 0;
    
    int choice;
    while (1) {
        printf("Enter a command:\n");
        printf("1. Create file\n");
        printf("2. Create directory\n");
        printf("3. Delete file or directory\n");
        printf("4. Display file contents\n");
        printf("5. Display directory contents\n");
        printf("6. Exit\n\n");
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_file(root);
                break;
            case 2:
                create_directory(root);
                break;
            case 3:
                delete_file_or_directory(root);
                break;
            case 4:
                display_file_contents(root);
                break;
            case 5:
                display_directory_contents(root);
                break;
            case 6:
                delete_directory(root);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }
    return 0;
}