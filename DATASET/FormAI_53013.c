//FormAI DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 100

typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

typedef struct directory_node {
    char name[MAX_FILENAME_LENGTH];
    struct directory_node* parent;
    struct directory_node* subdirectories;
    struct file* files;
} Directory_Node;

void print_directory_tree(Directory_Node* root, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("-");
    }
    printf(" %s\n", root->name);
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        if (root->files[i].name[0] != '\0') {
            for (int j = 0; j < depth+1; j++) {
                printf("-");
            }
            printf(" %s\n", root->files[i].name);
        }
    }
    Directory_Node* current_directory = root->subdirectories;
    while (current_directory != NULL) {
        print_directory_tree(current_directory, depth+1);
        current_directory = current_directory->subdirectories;
    }
}

void create_directory(Directory_Node* current_directory, char* directory_name) {
    Directory_Node* new_directory = (Directory_Node*) malloc(sizeof(Directory_Node));
    strcpy(new_directory->name, directory_name);
    new_directory->parent = current_directory;
    new_directory->subdirectories = NULL;
    new_directory->files = (File*) malloc(MAX_FILE_SIZE * sizeof(File));
    memset(new_directory->files, 0, MAX_FILE_SIZE * sizeof(File));
    if (current_directory->subdirectories == NULL) {
        current_directory->subdirectories = new_directory;
    } else {
        Directory_Node* last_directory = current_directory->subdirectories;
        while (last_directory->subdirectories != NULL) {
            last_directory = last_directory->subdirectories;
        }
        last_directory->subdirectories = new_directory;
    }
}

void create_file(Directory_Node* current_directory, char* file_name, char* file_data, int file_size) {
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        if (current_directory->files[i].name[0] == '\0') {
            strcpy(current_directory->files[i].name, file_name);
            strcpy(current_directory->files[i].data, file_data);
            current_directory->files[i].size = file_size;
            return;
        }
    }
    printf("Error: Maximum file limit reached in current directory!\n");
}

Directory_Node* get_directory(Directory_Node* root, char* directory_name) {
    if (strcmp(root->name, directory_name) == 0) {
        return root;
    } else {
        Directory_Node* current_directory = root->subdirectories;
        while (current_directory != NULL) {
            Directory_Node* matching_directory = get_directory(current_directory, directory_name);
            if (matching_directory != NULL) {
                return matching_directory;
            }
            current_directory = current_directory->subdirectories;
        }
        return NULL;
    }
}

int main() {
    Directory_Node* root_directory = (Directory_Node*) malloc(sizeof(Directory_Node));
    strcpy(root_directory->name, "/");
    root_directory->parent = NULL;
    root_directory->subdirectories = NULL;
    root_directory->files = (File*) malloc(MAX_FILE_SIZE * sizeof(File));
    memset(root_directory->files, 0, MAX_FILE_SIZE * sizeof(File));

    create_directory(root_directory, "Desktop");
    create_directory(root_directory, "Downloads");
    create_directory(get_directory(root_directory, "Desktop"), "Pictures");

    create_file(root_directory, "readme.txt", "This is the root directory.\n", strlen("This is the root directory.\n"));
    create_file(get_directory(root_directory, "Desktop"), "note.txt", "Don't forget to call your mom.", strlen("Don't forget to call your mom."));
    create_file(get_directory(get_directory(root_directory, "Desktop"), "Pictures"), "vacation.jpg", "This was a great trip.", strlen("This was a great trip."));

    print_directory_tree(root_directory, 0);

    return 0;
}