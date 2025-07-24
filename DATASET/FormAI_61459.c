//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 255

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
    char content[100000];
};

struct directory {
    char name[MAX_NAME_LENGTH];
    struct file files[MAX_FILES];
    struct directory *subdirectories[MAX_FILES];
    int num_files;
    int num_subdirectories;
};

void create_file(struct directory *dir, char *name, int size, char *content) {
    if (dir->num_files == MAX_FILES) {
        printf("Error: maximum number of files reached\n");
        return;
    }
    
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    strcpy(new_file.content, content);
    
    dir->files[dir->num_files++] = new_file;
}

void update_file(struct directory *dir, char *name, char *new_content) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            strcpy(dir->files[i].content, new_content);
            return;
        }
    }
    
    printf("Error: file not found\n");
}

void delete_file(struct directory *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            for (int j = i + 1; j < dir->num_files; j++) {
                dir->files[j - 1] = dir->files[j];
            }
            dir->num_files--;
            return;
        }
    }
    
    printf("Error: file not found\n");
}

void create_directory(struct directory *dir, char *name) {
    if (dir->num_subdirectories == MAX_FILES) {
        printf("Error: maximum number of directories reached\n");
        return;
    }
    
    struct directory *new_directory = malloc(sizeof(struct directory));
    strcpy(new_directory->name, name);
    new_directory->num_files = 0;
    new_directory->num_subdirectories = 0;
    
    dir->subdirectories[dir->num_subdirectories++] = new_directory;
}

struct directory *traverse_directory(struct directory *root, char *path) {
    char *delim = "/";
    char *token = strtok(path, delim);
    
    if (strcmp(token, root->name) != 0) {
        printf("Error: incorrect path\n");
        return NULL;
    }
    
    struct directory *curr = root;
    
    // traverse subdirectories
    while (token = strtok(NULL, delim)) {
        int found = 0;
        for (int i = 0; i < curr->num_subdirectories; i++) {
            if (strcmp(curr->subdirectories[i]->name, token) == 0) {
                found = 1;
                curr = curr->subdirectories[i];
                break;
            }
        }
        if (!found) {
            printf("Error: incorrect path\n");
            return NULL;
        }
    }
    
    return curr;
}

int main() {
    struct directory root;
    strcpy(root.name, "root");
    root.num_files = 0;
    root.num_subdirectories = 0;
    
    create_directory(&root, "dir1");
    create_directory(&root, "dir2");
    create_directory(root.subdirectories[0], "dir3");
    
    create_file(&root, "file1.txt", 10, "hello world");
    create_file(&root, "file2.txt", 5, "foo");
    create_file(root.subdirectories[0], "file3.txt", 7, "bar");
    
    struct directory *curr_dir = traverse_directory(&root, "root/dir1/dir3");
    if (curr_dir != NULL) {
        create_file(curr_dir, "file4.txt", 8, "baz");
    }
    
    update_file(&root, "file1.txt", "goodbye world");
    delete_file(&root, "file2.txt");
    
    return 0;
}