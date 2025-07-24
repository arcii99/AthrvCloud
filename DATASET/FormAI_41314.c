//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file{
    char name[20];
    int size;
    char type[5];
};

struct folder{
    char name[20];
    int num_files;
    struct file files[10];
};

struct drive{
    char name[20];
    char type[10];
    int num_folders;
    struct folder folders[10];
};

int main(){
    struct drive d;
    strcpy(d.name, "D:/");
    strcpy(d.type, "NTFS");
    d.num_folders = 0;
    
    struct folder f;
    strcpy(f.name, "My Documents");
    f.num_files = 0;
    
    struct file file1;
    strcpy(file1.name, "resume");
    file1.size = 500;
    strcpy(file1.type, "doc");
    
    struct file file2;
    strcpy(file2.name, "myimage");
    file2.size = 1024;
    strcpy(file2.type, "jpg");
    
    f.files[0] = file1;
    f.files[1] = file2;
    f.num_files = 2;
    
    d.folders[0] = f;
    d.num_folders = 1;
    
    printf("Drive Name: %s\n", d.name);
    printf("Drive Type: %s\n", d.type);
    printf("Number of Folders: %d\n\n", d.num_folders);
    
    for(int i=0; i<d.num_folders; i++){
        printf("Folder Name: %s\n", d.folders[i].name);
        printf("Number of Files: %d\n", d.folders[i].num_files);
        printf("Files:\n");
        for(int j=0; j<d.folders[i].num_files; j++){
            printf("\t %s.%s - %dKB\n", d.folders[i].files[j].name, d.folders[i].files[j].type, d.folders[i].files[j].size);
        }
        printf("\n");
    }
    
    return 0;
}