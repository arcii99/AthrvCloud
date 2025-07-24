//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold information about each file (name, size, etc.) */
struct File {
    char name[50];
    int size;
};

/* Define a structure to hold information about each directory (name, contents, etc.) */
struct Directory {
    char name[50];
    int num_files;
    struct File *files;
    int num_subdirectories;
    struct Directory *subdirectories;
};

/* Define a function to create a new file with the given name and size */
void create_file(struct Directory *dir, char *name, int size) {
    if (dir->num_files == 0) {
        dir->files = malloc(sizeof(struct File));
    } else {
        dir->files = realloc(dir->files, (dir->num_files + 1) * sizeof(struct File));
    }

    struct File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;

    dir->files[dir->num_files] = new_file;
    dir->num_files++;
}

/* Define a function to create a new directory with the given name */
void create_directory(struct Directory *parent_dir, char *name) {
    if (parent_dir->num_subdirectories == 0) {
        parent_dir->subdirectories = malloc(sizeof(struct Directory));
    } else {
        parent_dir->subdirectories = realloc(parent_dir->subdirectories, (parent_dir->num_subdirectories + 1) * sizeof(struct Directory));
    }

    struct Directory new_dir;
    strcpy(new_dir.name, name);
    new_dir.num_files = 0;
    new_dir.files = NULL;
    new_dir.num_subdirectories = 0;
    new_dir.subdirectories = NULL;

    parent_dir->subdirectories[parent_dir->num_subdirectories] = new_dir;
    parent_dir->num_subdirectories++;
}

/* Define a function to print the contents of a directory (including files and subdirectories) */
void print_directory_contents(struct Directory *dir, int level) {
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%s/\n", dir->name);

    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("---Files:\n");

    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < level; j++) {
            printf("   ");
        }
        printf("   %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }

    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("---Subdirectories:\n");

    for (int i = 0; i < dir->num_subdirectories; i++) {
        print_directory_contents(&dir->subdirectories[i], level + 1);
    }
}

int main() {
    struct Directory root_dir;
    strcpy(root_dir.name, "root");
    root_dir.num_files = 0;
    root_dir.files = NULL;
    root_dir.num_subdirectories = 0;
    root_dir.subdirectories = NULL;

    create_file(&root_dir, "file1.txt", 100);
    create_file(&root_dir, "file2.txt", 50);

    create_directory(&root_dir, "dir1");

    struct Directory *dir1 = &root_dir.subdirectories[0];
    create_file(dir1, "file3.txt", 75);

    create_directory(dir1, "dir2");

    struct Directory *dir2 = &dir1->subdirectories[0];
    create_file(dir2, "file4.txt", 200);

    print_directory_contents(&root_dir, 0);

    return 0;
}