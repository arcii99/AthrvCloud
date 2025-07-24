//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_NAME 256
#define MAX_NUM_FILES 100

// Defines the file structure
typedef struct{
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
} File;

// Defines the file system structure
typedef struct{
    File files[MAX_NUM_FILES];
    int num_files;
} FileSystem;

// Creates a new file
File create_file(char* name, char* content){
    File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    new_file.size = strlen(content);
    return new_file;
}

// Displays all files in the file system
void display_files(FileSystem fs){
    printf("Files in file system:\n");
    for(int i=0; i<fs.num_files; i++){
        printf("%s\n", fs.files[i].name);
    }
    printf("\n");
}

int main(){
    // Initializes the file system
    FileSystem file_system;
    file_system.num_files = 0;
    
    // Creates some files and adds them to the file system
    file_system.files[0] = create_file("file1.txt", "This is the content of file1");
    file_system.num_files++;
    file_system.files[1] = create_file("file2.txt", "This is the content of file2");
    file_system.num_files++;
    
    // Displays all files in the file system
    display_files(file_system);
    
    return 0;
}