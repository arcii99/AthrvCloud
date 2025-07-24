//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>

#define MAX_FILES 10
#define MAX_NAME_LEN 20
#define MAX_FILE_SIZE 10240

struct File {
    char name[MAX_NAME_LEN];
    int size;
    char contents[MAX_FILE_SIZE];
};

struct Directory {
    char name[MAX_NAME_LEN];
    struct File files[MAX_FILES];
    int num_files;
};

struct Filesystem {
    char name[MAX_NAME_LEN];
    struct Directory root;
};

void init_filesystem(struct Filesystem *fs, char *name) {
    strcpy(fs->name, name);
    strcpy(fs->root.name, "root");
    fs->root.num_files = 0;
}

void create_file(struct Directory *dir, char *name, char *contents, int size) {
    if (dir->num_files < MAX_FILES) {
        struct File new_file;
        strcpy(new_file.name, name);
        new_file.size = size;
        strcpy(new_file.contents, contents);
        dir->files[dir->num_files] = new_file;
        dir->num_files++;
    } else {
        printf("Error: maximum files reached for this directory\n");
    }
}

void delete_file(struct Directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            int last_file = dir->num_files - 1;
            dir->files[i] = dir->files[last_file];
            dir->num_files--;
            break;
        }
    }
}

void print_dir(struct Directory *dir) {
    printf("%s:\n", dir->name);
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    struct Filesystem fs;
    init_filesystem(&fs, "MyFS");
    
    create_file(&fs.root, "file1", "File 1 contents", 17);
    create_file(&fs.root, "file2", "File 2 contents", 17);
    create_file(&fs.root, "file3", "File 3 contents", 17);

    print_dir(&fs.root);

    delete_file(&fs.root, "file2");
    
    print_dir(&fs.root);
    
    return 0;
}