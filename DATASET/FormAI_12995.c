//FormAI DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000
#define MAX_FILE_NUM 100

// struct for a file in the system
typedef struct file {
    char name[50];
    char content[MAX_FILE_SIZE];
} File;

// struct for the file system
typedef struct file_system {
    File files[MAX_FILE_NUM];
    int num_files;
} FileSystem;

// function to add a new file to the system
void add_file(FileSystem* fs, char* name, char* content) {
    // check if the file already exists
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("A file with that name already exists.\n");
            return;
        }
    }

    // add the new file
    File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;

    printf("File added successfully.\n");
}

// function to delete a file from the system
void delete_file(FileSystem* fs, char* name) {
    // find the file
    int file_index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    // if the file was found, delete it
    if (file_index != -1) {
        // shift all files after the deleted file back by one
        for (int i = file_index; i < fs->num_files - 1; i++) {
            fs->files[i] = fs->files[i+1];
        }
        fs->num_files--;

        printf("File deleted successfully.\n");
    } else {
        printf("File not found.\n");
    }
}

// function to display the content of a file
void display_file(FileSystem* fs, char* name) {
    // find the file
    int file_index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    // if the file was found, display its content
    if (file_index != -1) {
        printf("Content of file '%s':\n", name);
        printf("%s\n", fs->files[file_index].content);
    } else {
        printf("File not found.\n");
    }
}

// function to list all files in the system
void list_files(FileSystem* fs) {
    printf("Files in file system:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s\n", fs->files[i].name);
    }
}

int main() {
    // initialize the file system
    FileSystem fs;
    fs.num_files = 0;

    printf("Welcome to the file system simulator!\n");

    // main loop
    while (1) {
        // print menu
        printf("\nMenu:\n");
        printf("[1] Add a file\n");
        printf("[2] Delete a file\n");
        printf("[3] Display file contents\n");
        printf("[4] List all files\n");
        printf("[5] Exit\n");
        printf("Enter your choice: ");

        // get user choice
        int choice;
        scanf("%d", &choice);

        // handle user choice
        switch (choice) {
            case 1: {
                // add a file
                char name[50];
                printf("Enter file name: ");
                scanf("%s", name);
                getchar(); // clear newline from buffer
                char content[MAX_FILE_SIZE];
                printf("Enter file content:\n");
                fgets(content, MAX_FILE_SIZE, stdin);
                add_file(&fs, name, content);
                break;
            }
            case 2: {
                // delete a file
                char name[50];
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            }
            case 3: {
                // display file contents
                char name[50];
                printf("Enter file name: ");
                scanf("%s", name);
                display_file(&fs, name);
                break;
            }
            case 4: {
                // list all files
                list_files(&fs);
                break;
            }
            case 5: {
                // exit program
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}