//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOLDERS 100
#define MAX_FILES 500

int curr_folder_id = 0, curr_file_id = 0;

struct folder {
    int id;
    char name[50];
    int parent_id;
    int num_files;
    int files[MAX_FILES];
    int num_folders;
    int folders[MAX_FOLDERS];
};

struct file {
    int id;
    char name[50];
    int folder_id;
    int size;
};

struct folder folders[MAX_FOLDERS];
struct file files[MAX_FILES];

void create_folder(char name[], int parent_id) {
    folders[curr_folder_id].id = curr_folder_id;
    strcpy(folders[curr_folder_id].name, name);
    folders[curr_folder_id].parent_id = parent_id;
    folders[curr_folder_id].num_folders = 0;
    folders[curr_folder_id].num_files = 0;
    curr_folder_id++;
}

void create_file(char name[], int folder_id, int size) {
    files[curr_file_id].id = curr_file_id;
    strcpy(files[curr_file_id].name, name);
    files[curr_file_id].folder_id = folder_id;
    files[curr_file_id].size = size;
    folders[folder_id].files[folders[folder_id].num_files] = curr_file_id;
    folders[folder_id].num_files++;
    curr_file_id++;
}

void print_folder(int folder_id) {
    printf("Folder: %s\n", folders[folder_id].name);
    printf("Parent folder: %s\n", folders[folders[folder_id].parent_id].name);

    printf("Folders:\n");
    for (int i = 0; i < folders[folder_id].num_folders; i++) {
        printf("- %s\n", folders[folders[folder_id].folders[i]].name);
    }

    printf("Files:\n");
    for (int i = 0; i < folders[folder_id].num_files; i++) {
        printf("- %s (%d bytes)\n", files[folders[folder_id].files[i]].name, files[folders[folder_id].files[i]].size);
    }
}

int main() {
    create_folder("Documents", -1);
    create_folder("Pictures", -1);
    create_folder("Downloads", -1);
    create_folder("Vacation", 1);
    create_folder("Work", 1);
    create_file("resume.pdf", 4, 512);
    create_file("beach.jpg", 3, 1024);

    print_folder(1);
    return 0;
}