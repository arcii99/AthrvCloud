//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char* content;
    char is_deleted;
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
} FileSystem;

FileSystem fs;

void create_file(char* name, int size) {
    if(fs.num_files >= MAX_FILES) {
        printf("File system full!\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.content = (char*)malloc(size);
    new_file.is_deleted = 0;

    fs.files[fs.num_files] = new_file;
    fs.num_files++;

    printf("File created successfully!\n");
}

void delete_file(char* name) {
    int i;
    for(i=0; i<fs.num_files; i++) {
        if(strcmp(fs.files[i].name, name)==0) {
            free(fs.files[i].content);
            fs.files[i].is_deleted = 1;
            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("File not found!\n");
}

void write_file(char* name, char* content) {
    int i;
    for(i=0; i<fs.num_files; i++) {
        if(strcmp(fs.files[i].name, name)==0) {
            if(fs.files[i].is_deleted) {
                printf("File not found!\n");
                return;
            }
            if(strlen(content) > fs.files[i].size) {
                printf("File size exceeded!\n");
                return;
            }
            strcpy(fs.files[i].content, content);
            printf("File written successfully!\n");
            return;
        }
    }

    printf("File not found!\n");
}

void read_file(char* name) {
    int i;
    for(i=0; i<fs.num_files; i++) {
        if(strcmp(fs.files[i].name, name)==0) {
            if(fs.files[i].is_deleted) {
                printf("File not found!\n");
                return;
            }
            printf("File content:\n%s\n", fs.files[i].content);
            return;
        }
    }

    printf("File not found!\n");
}

int main() {
    fs.num_files = 0;

    create_file("file1.txt", 100);
    create_file("file2.txt", 50);

    write_file("file1.txt", "This is file 1");
    write_file("file2.txt", "This is file 2");

    read_file("file1.txt");
    read_file("file2.txt");

    delete_file("file1.txt");

    read_file("file1.txt");
    read_file("file2.txt");

    return 0;
}