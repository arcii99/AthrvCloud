//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[10];
    int size;
    int index;
} File;

typedef struct{
    char name[10];
    int size;
    int start;
    File files[10];
} Directory;

int main(){
    int memory[100]; //memory block of 100 for simplicity
    int occupied[100]; //array to keep track of occupied memory blocks (1=occupied, 0=free)
    int total_size = 100; //total size of memory block
    int curr_dir = 0; //current directory index
    int num_dirs = 0; //total number of directories
    int num_files = 0; //total number of files
    
    Directory directories[10];
    
    //initialize all memory blocks as free
    for(int i=0; i<total_size; i++){
        occupied[i] = 0;
    }
    
    //function to create a new directory
    void create_dir(char name[10]){
        //find free memory block to allocate directory
        for(int i=0; i<total_size; i++){
            if(occupied[i] == 0){
                directories[num_dirs].start = i;
                strcpy(directories[num_dirs].name, name);
                directories[num_dirs].size = 0;
                num_dirs++;
                return;
            }
        }
        printf("Error: no free memory for new directory\n");
    }
    
    //function to list all directories
    void list_dirs(){
        printf("Directories:\n");
        for(int i=0; i<num_dirs; i++){
            printf("%s\n", directories[i].name);
        }
    }
    
    //function to change directory
    void change_dir(char name[10]){
        for(int i=0; i<num_dirs; i++){
            if(strcmp(directories[i].name, name) == 0){
                curr_dir = i;
                return;
            }
        }
        printf("Error: directory not found\n");
    }
    
    //function to create a new file in current directory
    void create_file(char name[10], int size){
        //find free memory block for file
        for(int i=0; i<total_size; i++){
            if(occupied[i] == 0){
                //check if there is enough space in current directory for new file
                if(directories[curr_dir].size + size <= total_size){
                    directories[curr_dir].files[num_files].index = i;
                    strcpy(directories[curr_dir].files[num_files].name, name);
                    directories[curr_dir].files[num_files].size = size;
                    directories[curr_dir].size += size;
                    num_files++;
                    occupied[i] = 1;
                    return;
                } else {
                    printf("Error: not enough space\n");
                    return;
                }
            }
        }
        printf("Error: no free memory for new file\n");
    }
    
    //function to delete a file in current directory
    void delete_file(char name[10]){
        for(int i=0; i<num_files; i++){
            if(strcmp(directories[curr_dir].files[i].name, name) == 0){
                int start = directories[curr_dir].files[i].index;
                int end = start + directories[curr_dir].files[i].size;
                //clear occupied memory blocks
                for(int j=start; j<end; j++){
                    occupied[j] = 0;
                }
                //shift remaining files to fill gap
                for(int j=i+1; j<num_files; j++){
                    directories[curr_dir].files[j-1] = directories[curr_dir].files[j];
                }
                num_files--;
                directories[curr_dir].size -= end-start;
                return;
            }
        }
        printf("Error: file not found\n");
    }
    
    //function to list all files in current directory
    void list_files(){
        printf("Files:\n");
        for(int i=0; i<num_files; i++){
            printf("%s\n", directories[curr_dir].files[i].name);
        }
    }
    
    //function to display current directory
    void display_dir(){
        printf("Current directory: %s\n", directories[curr_dir].name);
    }
    
    //sample commands
    create_dir("folder1");
    create_dir("folder2");
    create_file("file1", 10);
    create_file("file2", 20);
    list_dirs();
    display_dir();
    change_dir("folder1");
    create_file("file3", 15);
    list_files();
    delete_file("file2");
    list_files();
    
    return 0;
}