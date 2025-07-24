//FormAI DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_FOLDER_NAME 20
#define MAX_FILES 50
#define MAX_FOLDERS 20

struct file {
    char name[MAX_FILE_NAME];
    int size;
};

struct folder {
    char name[MAX_FOLDER_NAME];
    struct file files[MAX_FILES];
    int num_files;
};

struct file_system {
    struct folder folders[MAX_FOLDERS];
    int num_folders;
};

void create_file(struct folder *folder, char *name, int size) {
    if (folder->num_files < MAX_FILES) {
        strcpy(folder->files[folder->num_files].name, name);
        folder->files[folder->num_files].size = size;
        folder->num_files++;
        printf("File '%s' created with size %d.\n", name, size);
    } else {
        printf("Max number of files reached.");
    }
}

void delete_file(struct folder *folder, char *name) {
    int i;
    for (i = 0; i < folder->num_files; i++) {
        if (strcmp(folder->files[i].name, name) == 0) {
            folder->num_files--;
            folder->files[i] = folder->files[folder->num_files];
            printf("File '%s' deleted.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

void create_folder(struct file_system *fs, char *name) {
    if (fs->num_folders < MAX_FOLDERS) {
        strcpy(fs->folders[fs->num_folders].name, name);
        fs->folders[fs->num_folders].num_files = 0;
        fs->num_folders++;
        printf("Folder '%s' created.\n", name);
    } else {
        printf("Max number of folders reached.\n");
    }
}

void delete_folder(struct file_system *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_folders; i++) {
        if (strcmp(fs->folders[i].name, name) == 0) {
            fs->num_folders--;
            fs->folders[i] = fs->folders[fs->num_folders];
            printf("Folder '%s' deleted.\n", name);
            return;
        }
    }
    printf("Folder '%s' not found.\n", name);
}

int main() {
    struct file_system fs;
    fs.num_folders = 0;
    char input[50];
    char command[50];
    char name[50];
    int size;
    printf("File System Simulation\n");
    printf("----------------------\n");
    while (1) {
        printf("> ");
        fgets(input, 50, stdin); // get user input
        sscanf(input, "%s %s %d", command, name, &size); // parse input
        if (strcmp(command, "create_file") == 0) {
            create_file(&fs.folders[0], name, size); // create file in root directory
        } else if (strcmp(command, "delete_file") == 0) {
            delete_file(&fs.folders[0], name); // delete file from root directory
        } else if (strcmp(command, "create_folder") == 0) {
            create_folder(&fs, name); // create folder in file system
        } else if (strcmp(command, "delete_folder") == 0) {
            delete_folder(&fs, name); // delete folder from file system
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}