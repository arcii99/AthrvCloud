//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define constants
#define MAX_FILES 5
#define FILE_NAME_SIZE 20
#define MAX_FILE_SIZE 1024

// define data struct for file
typedef struct File {
    char name[FILE_NAME_SIZE];
    char data[MAX_FILE_SIZE];
} File;

// define data struct for directory entry
typedef struct Directory {
    File files[MAX_FILES];
    int count;
} Directory;

// function to recover file data
char* recover_file_data(char* file_name, Directory* dir) {
    int i;
    for(i=0; i<dir->count; i++) {
        if(strcmp(dir->files[i].name, file_name) == 0) {
            return dir->files[i].data;
        }
    }
    return NULL;
}

int main() {
    Directory dir;
    dir.count = 0;
    
    // simulate file recovery
    char file1[] = "file1.txt";
    char data1[] = "Hello World!";
    strcpy(dir.files[dir.count].name, file1);
    strcpy(dir.files[dir.count].data, data1);
    dir.count++;
    
    char file2[] = "file2.txt";
    char data2[] = "Lorem Ipsum Dolor Sit Amet";
    strcpy(dir.files[dir.count].name, file2);
    strcpy(dir.files[dir.count].data, data2);
    dir.count++;
    
    char file3[] = "file3.txt";
    char data3[] = "12345";
    strcpy(dir.files[dir.count].name, file3);
    strcpy(dir.files[dir.count].data, data3);
    dir.count++;
    
    // test file recovery
    char* result = recover_file_data(file2, &dir);
    printf("Data for %s: %s\n", file2, result);

    return 0;
}