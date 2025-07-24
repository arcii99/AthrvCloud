//FormAI DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>

#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 100

struct File {
    char name[20];
    int size;
    char* data;
};

struct FileSystem {
     struct File files[MAX_NUM_FILES];
     int num_files;
};

struct FileSystem fs = { .num_files = 0 };

void create_file(char* name) {
    struct File file = { .size = 0, .data = NULL };
    if (fs.num_files < MAX_NUM_FILES) {
        snprintf(file.name, 20, "%s", name);
        fs.files[fs.num_files++] = file;
        printf("File created successfully: %s\n", name);
    }
    else {
        printf("File system full - file creation failed.\n");
    }
}

void delete_file(char* name) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            found = 1;
            for (int j = i+1; j < fs.num_files; j++) {
                fs.files[j-1] = fs.files[j];
            }
            fs.num_files--;
            printf("File deleted successfully: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("File not found: %s\n", name);
    }
}

void write_file(char* name, char* data) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            fs.files[i].size = strlen(data);
            fs.files[i].data = (char*) malloc(fs.files[i].size * sizeof(char));
            snprintf(fs.files[i].data, fs.files[i].size + 1, "%s", data);
            found = 1;
            printf("Data written successfully to file: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("File not found: %s\n", name);
    }
}

void read_file(char* name) {
    int found = 0;
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            found = 1;
            printf("%s contains:\n%s\n", name, fs.files[i].data);
            break;
        }
    }
    if (!found) {
        printf("File not found: %s\n", name);
    }
}

int main() {
    create_file("file1.txt");
    write_file("file1.txt", "Hello World!");
    read_file("file1.txt");
    delete_file("file1.txt");
    return 0;
}