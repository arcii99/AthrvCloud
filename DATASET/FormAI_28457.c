//FormAI DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>

#define MAX_FILE_SIZE 1024 // maximum file size
#define MAX_FILES 100 // maximum number of files in the file system

struct File {
    char* name; // file name
    int size; // file size in bytes
    char* data; // file content
};

// variables to keep track of the file system
struct File files[MAX_FILES]; // all files in the file system
int num_files = 0; // number of files in the file system
int total_size = 0; // total size of all files in the file system

int create_file(char* name, char* data, int size) {
    // check if the file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File %s already exists\n", name);
            return -1;
        }
    }

    // check if there is enough space in the file system
    if (total_size + size > MAX_FILE_SIZE * MAX_FILES) {
        printf("Not enough space in the file system\n");
        return -1;
    }

    // create the file
    struct File file = {name, size, data};
    files[num_files] = file;
    num_files++;
    total_size += size;

    printf("File %s created\n", name);
    return 0;
}

int delete_file(char* name) {
    // find the file in the file system
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("File %s not found\n", name);
        return -1;
    }

    // delete the file
    total_size -= files[index].size;
    for (int i = index; i < num_files - 1; i++) {
        files[i] = files[i+1];
    }
    num_files--;

    printf("File %s deleted\n", name);
    return 0;
}

int main() {
    // create some files in the file system
    create_file("file1.txt", "Hello, World!", 14);
    create_file("file2.txt", "This is a test file.", 21);
    create_file("file3.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec tincidunt, risus nec pulvinar blandit, sapien sapien finibus justo, vel molestie felis justo id nisi. Praesent vestibulum elit et orci gravida, vel bibendum sapien gravida. Curabitur eget neque at mi euismod dictum.", 231);

    // delete a file from the file system
    delete_file("file2.txt");

    return 0;
}