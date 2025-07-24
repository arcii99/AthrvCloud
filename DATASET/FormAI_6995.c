//FormAI DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 //maximum number of files that can be stored in the file system
#define MAX_FILE_NAME_LEN 20 //maximum length of file name

struct file{
    char name[MAX_FILE_NAME_LEN]; //file name
    int size; //file size in bytes
    char* data; //file data
};

struct file_system{
    struct file files[MAX_FILES]; //array of files
    int file_count; //total number of files in the file system
    int total_size; //total size of all files in the file system
};

//function to initialize the file system
void init_file_system(struct file_system* fs){
    fs->file_count = 0;
    fs->total_size = 0;
}

//function to add a file to the file system
void add_file(struct file_system* fs, char* name, int size, char* data) {
    if(fs->file_count >= MAX_FILES) {
        printf("File System full\n");
        return;
    }
    
    //creating a new file
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    
    //allocating memory for file data
    new_file.data = malloc(size*sizeof(char));
    memcpy(new_file.data, data, size);
    
    //adding the file to the file system
    fs->files[fs->file_count] = new_file;
    fs->file_count++;
    fs->total_size += size;
}

//function to delete a file from the file system
void delete_file(struct file_system* fs, char* name) {
    int index = -1;
    for(int i=0; i<fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("File not found\n");
        return;
    }
    
    //removing the file from the file system
    struct file file_to_delete = fs->files[index];
    fs->total_size -= file_to_delete.size;
    for(int i=index; i<fs->file_count-1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->file_count--;
    
    //freeing memory allocated for file data
    free(file_to_delete.data);
}

//function to print the file system contents
void print_file_system(struct file_system* fs) {
    printf("Total files in file system: %d\n", fs->file_count);
    printf("Total size of file system: %d bytes\n", fs->total_size);
    printf("Files in file system:\n");
    for(int i=0; i<fs->file_count; i++) {
        printf("\tFile name: %s\n", fs->files[i].name);
        printf("\tFile size: %d bytes\n", fs->files[i].size);
    }
}

int main() {
    struct file_system fs;
    init_file_system(&fs);
    
    //adding files to the file system
    add_file(&fs, "file1.txt", 100, "This is file 1");
    add_file(&fs, "file2.txt", 200, "This is file 2");
    add_file(&fs, "file3.txt", 300, "This is file 3");
    
    //printing file system contents
    print_file_system(&fs);
    
    //deleting a file from the file system
    delete_file(&fs, "file2.txt");
    
    //printing file system contents again
    print_file_system(&fs);
    
    return 0;
}