//FormAI DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_FILE_COUNT 10
#define MAX_FILE_SIZE 1024

struct File{
    char filename[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
};

struct FileSystem{
    int file_count;
    int used_space;
    struct File files[MAX_FILE_COUNT];
};

void initialize_fs(struct FileSystem* fs){
    fs->file_count = 0;
    fs->used_space = 0;
}

void create_file(struct FileSystem* fs, char* filename, char* data){
    if(fs->file_count >= MAX_FILE_COUNT){
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    if(fs->used_space + strlen(data) >= MAX_FILE_SIZE){
        printf("Error: Not enough space to create the file.\n");
        return;
    }

    struct File* file = &fs->files[fs->file_count];
    strcpy(file->filename, filename);
    file->size = strlen(data);
    strcpy(file->data, data);

    fs->file_count++;
    fs->used_space += file->size;
}

void delete_file(struct FileSystem* fs, char* filename){
    int file_index = -1;
    for(int i=0; i<fs->file_count; i++){
        if(strcmp(fs->files[i].filename, filename) == 0){
            file_index = i;
            break;
        }
    }
    if(file_index == -1){
        printf("Error: File not found.\n");
        return;
    }

    fs->used_space -= fs->files[file_index].size;
    for(int i=file_index; i<fs->file_count-1; i++){
        fs->files[i] = fs->files[i+1];
    }
    fs->file_count--;
}

void print_file(struct FileSystem* fs, char* filename){
    for(int i=0; i<fs->file_count; i++){
        if(strcmp(fs->files[i].filename, filename) == 0){
            printf("File name: %s\n", fs->files[i].filename);
            printf("File size: %d\n", fs->files[i].size);
            printf("File content: %s\n", fs->files[i].data);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void list_files(struct FileSystem* fs){
    printf("Files in the file system:\n");
    for(int i=0; i<fs->file_count; i++){
        printf("- %s (%d bytes)\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main(){
    struct FileSystem fs;
    initialize_fs(&fs);

    create_file(&fs, "file1.txt", "Hello World!");
    create_file(&fs, "file2.txt", "This is a test.");
    create_file(&fs, "file3.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sagittis consectetur odio at ullamcorper. Donec eget purus vel enim posuere aliquam sit amet et leo. Sed venenatis neque ut turpis eleifend bibendum. Praesent interdum sollicitudin urna, ut interdum tellus feugiat nec. Nulla facilisi.");
    list_files(&fs);
    print_file(&fs, "file1.txt");
    delete_file(&fs, "file2.txt");
    list_files(&fs);

    return 0;
}