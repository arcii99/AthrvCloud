//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20

struct file {
    char name[20];
    int size;
    char data[100];
};

struct directory {
    char name[20];
    struct file files[MAX_FILES];
    int num_files;
};

struct disk {
    struct directory root;
};

void init_disk(struct disk *d) {
    strcpy(d->root.name, "/");
    d->root.num_files = 0;
}

void init_directory(struct directory *dir, char *name) {
    strcpy(dir->name, name);
    dir->num_files = 0;
}

void add_file(struct directory *dir, char *name, char *data, int size) {
    if (dir->num_files >= MAX_FILES) {
        printf("Directory is full!\n");
        return;
    }
    struct file f;
    strcpy(f.name, name);
    f.size = size;
    strcpy(f.data, data);
    dir->files[dir->num_files++] = f;
}

void print_directory(struct directory *dir) {
    printf("Directory name: %s\n", dir->name);
    printf("Files:\n");
    for (int i = 0; i < dir->num_files; ++i) {
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    struct disk d;
    init_disk(&d);
    printf("Creating directories and files...\n");
    struct directory dir1, dir2;
    init_directory(&dir1, "documents");
    init_directory(&dir2, "photos");
    add_file(&dir1, "resume.txt", "A summary of my work experience.", 27);
    add_file(&dir1, "cover_letter.txt", "A personalized cover letter for each job application.", 51);
    add_file(&dir2, "vacation.jpg", "A beautiful photo taken during my vacation.", 10000);
    printf("Printing directories...\n");
    print_directory(&d.root);
    print_directory(&dir1);
    print_directory(&dir2);
    return 0;
}