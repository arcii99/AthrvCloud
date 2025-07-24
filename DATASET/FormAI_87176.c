//FormAI DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILES 100
#define MAX_NAME_SIZE 20

typedef struct{
    char name[MAX_NAME_SIZE];
    int size;
    char* data;
} file;

typedef struct{
    file files[MAX_FILES];
    int num_files;
    int total_size;
} file_system;

void initialize_fs(file_system* fs){
    fs->num_files = 0;
    fs->total_size = 0;
}

void add_file(file_system* fs, char* name, int size, char* data){
    if(fs->num_files == MAX_FILES){
        printf("Error: Maximum number of files reached\n");
        return;
    }
    if(fs->total_size + size > MAX_FILE_SIZE){
        printf("Error: Not enough space in file system\n");
        return;
    }
    file f;
    strcpy(f.name, name);
    f.size = size;
    f.data = malloc(size);
    memcpy(f.data, data, size);
    fs->files[fs->num_files] = f;
    fs->num_files++;
    fs->total_size += size;
    printf("File \"%s\" successfully added to file system\n", name);
}

void delete_file(file_system* fs, char* name){
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            fs->total_size -= fs->files[i].size;
            free(fs->files[i].data);
            for(int j = i + 1; j < fs->num_files; j++){
                fs->files[j - 1] = fs->files[j];
            }
            fs->num_files--;
            printf("File \"%s\" successfully deleted from file system\n", name);
            return;
        }
    }
    printf("Error: File \"%s\" not found in file system\n", name);
}

file* get_file(file_system* fs, char* name){
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            return &fs->files[i];
        }
    }
    return NULL;
}

int main(){
    file_system fs;
    initialize_fs(&fs);
    add_file(&fs, "file1.txt", 10, "This is file 1");
    add_file(&fs, "file2.txt", 20, "This is file 2");
    file* f1 = get_file(&fs, "file1.txt");
    if(f1 != NULL){
        printf("File %s has size %d and data %s\n", f1->name, f1->size, f1->data);
    }
    delete_file(&fs, "file1.txt");
    delete_file(&fs, "file3.txt");
    return 0;
}