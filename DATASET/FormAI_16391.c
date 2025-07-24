//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include<stdio.h>
#include<string.h>

#define MAX_FILES 100
#define MAX_NAME 20

// struct to represent file in the file system
typedef struct {
    char name[MAX_NAME];
    int size;
} File;

// array of files representing the file system
File file_sys[MAX_FILES];
int num_files = 0;

// function to add file to the file system
void add_file(char* name, int size) {
    if(num_files == MAX_FILES) {
        printf("File system is full!\n");
        return;
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    file_sys[num_files] = new_file;
    num_files++;
}

// function to delete file from file system
void delete_file(char* name) {
    int i;
    for(i=0; i<num_files; i++) {
        if(strcmp(file_sys[i].name, name) == 0) {
            int j;
            for(j=i+1; j<num_files; j++) {
                file_sys[j-1] = file_sys[j];
            }
            num_files--;
            printf("File %s deleted from file system.\n", name);
            return;
        }
    }
    printf("File %s not found in file system.\n", name);
}

// function to list all files in the file system
void list_files() {
    if(num_files == 0) {
        printf("No files in file system.\n");
        return;
    }
    int i;
    printf("Files in file system:\n");
    for(i=0; i<num_files; i++) {
        printf("%s (size: %d bytes)\n", file_sys[i].name, file_sys[i].size);
    }
}

int main() {
    add_file("file1.txt", 100);
    add_file("file2.txt", 50);
    add_file("file3.txt", 200);

    list_files();

    delete_file("file2.txt");

    list_files();

    return 0;
}