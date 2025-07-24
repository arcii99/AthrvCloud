//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct{
    char name[20];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct{
    File files[MAX_FILES];
    int num_files;
} File_System;

void init_file_system(File_System *fs){
    fs->num_files = 0;
}

void create_file(File_System *fs, char *name){
    if(fs->num_files == MAX_FILES){
        printf("Error: File system full\n");
        return;
    }

    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            printf("Error: File with the same name already exists\n");
            return;
        }
    }

    strcpy(fs->files[fs->num_files].name, name);
    fs->files[fs->num_files].size = 0;
    fs->num_files++;

    printf("File created successfully\n");
}

void delete_file(File_System *fs, char *name){
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            for(int j=i; j<fs->num_files-1; j++){
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File deleted successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

void display_files(File_System *fs){
    printf("List of all files in file system:\n");
    for(int i=0; i<fs->num_files; i++){
        printf("%s\t%d bytes\n", fs->files[i].name, fs->files[i].size);
    }
}

void write_file(File_System *fs, char *name, char *data){
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            int len = strlen(data);
            if(len > MAX_FILE_SIZE){
                printf("Error: File size too large\n");
                return;
            }
            strcpy(fs->files[i].data, data);
            fs->files[i].size = len;
            printf("File written successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

void read_file(File_System *fs, char *name){
    for(int i=0; i<fs->num_files; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            printf("Content of file %s:\n", name);
            printf("%s\n", fs->files[i].data);
            return;
        }
    }
    printf("Error: File not found\n");
}

int main(){
    File_System fs;
    init_file_system(&fs);

    while(1){
        char command[20];
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "create") == 0){
            char name[20];
            printf("Enter name of file to create: ");
            scanf("%s", name);
            create_file(&fs, name);
        }else if(strcmp(command, "delete") == 0){
            char name[20];
            printf("Enter name of file to delete: ");
            scanf("%s", name);
            delete_file(&fs, name);
        }else if(strcmp(command, "display") == 0){
            display_files(&fs);
        }else if(strcmp(command, "write") == 0){
            char name[20];
            char data[MAX_FILE_SIZE];
            printf("Enter name of file to write: ");
            scanf("%s", name);
            printf("Enter data to write in file: ");
            getchar();
            fgets(data, MAX_FILE_SIZE, stdin);
            write_file(&fs, name, data);
        }else if(strcmp(command, "read") == 0){
            char name[20];
            printf("Enter name of file to read: ");
            scanf("%s", name);
            read_file(&fs, name);
        }else if(strcmp(command, "exit") == 0){
            printf("Exiting file system program\n");
            exit(0);
        }else{
            printf("Invalid command\n");
        }
    }

    return 0;
}