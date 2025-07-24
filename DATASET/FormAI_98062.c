//FormAI DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>

#define MAX_FILES 10
#define FILE_NAME_LEN 20

struct file {
    char name[FILE_NAME_LEN];
    int size;
};

struct directory {
    char name[FILE_NAME_LEN];
    struct file files[MAX_FILES];
    int num_files;
};

struct filesystem {
    struct directory root;
};

void print_filesystem(struct filesystem fs) {
    printf("Files in root directory:\n");
    for (int i = 0; i < fs.root.num_files; i++) {
        printf("%s - %d bytes\n", fs.root.files[i].name, fs.root.files[i].size);
    }
}

int main() {
    struct filesystem fs;

    // initialize root directory
    sprintf(fs.root.name, "root");
    fs.root.num_files = 0;

    // create some files
    struct file f1 = {"file1.txt", 100};
    struct file f2 = {"file2.txt", 200};
    struct file f3 = {"file3.txt", 300};

    // add files to root directory
    fs.root.files[fs.root.num_files++] = f1;
    fs.root.files[fs.root.num_files++] = f2;
    fs.root.files[fs.root.num_files++] = f3;

    print_filesystem(fs);

    return 0;
}