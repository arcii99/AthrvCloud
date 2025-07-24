//FormAI DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 16
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
    int deleted;
};

struct directory {
    char name[MAX_FILENAME_LENGTH];
    struct file files[10];
    int num_files;
};

struct filesystem {
    struct directory root;
    int num_directories;
};

void create_directory(struct filesystem *fs, char *name) {
    if (fs->num_directories == 10) {
        printf("The filesystem is full.\n");
        return;
    }

    struct directory d = {0};
    strcpy(d.name, name);
    fs->root.num_files++;
    fs->num_directories++;
}

void create_file(struct directory *d, char *name, char *data, int size) {
    if (d->num_files == 10) {
        printf("The directory is full.\n");
        return;
    }

    struct file f = {0};
    strcpy(f.name, name);
    memcpy(f.data, data, size);
    f.size = size;
    d->files[d->num_files] = f;
    d->num_files++;
}

void delete_file(struct directory *d, char *name) {
    for (int i = 0; i < d->num_files; i++) {
        if (strcmp(d->files[i].name, name) == 0) {
            d->files[i].deleted = 1;
            printf("File %s deleted.\n", name);
            return;
        }
    }

    printf("File %s not found.\n", name);
}

void list_files(struct directory *d) {
    printf("Listing files in directory %s:\n", d->name);
    for (int i = 0; i < d->num_files; i++) {
        if (!d->files[i].deleted) {
            printf("%s\n", d->files[i].name);
        }
    }
}

void list_directories(struct filesystem *fs) {
    printf("Listing directories:\n");
    printf("%s\n", fs->root.name);
    for (int i = 0; i < fs->num_directories; i++) {
        printf("%s\n", fs->root.name);
    }
}

int main() {
    struct filesystem fs = {0};
    strcpy(fs.root.name, "root");

    create_directory(&fs, "home");
    create_directory(&fs, "var");

    struct directory *home = &fs.root;
    while (strcmp(home->name, "home") != 0) {
        home++;
    }

    create_file(home, "hello.txt", "Hello, world!", 13);

    list_files(home);

    delete_file(home, "hello.txt");

    list_files(home);

    list_directories(&fs);

    return 0;
}