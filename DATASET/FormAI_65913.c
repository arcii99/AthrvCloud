//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include<stdio.h>

//This program is an example of a system administration task which calculates the total size of files in a directory.

int main(){
    char directory_path[100]; //Stores the directory path entered by the user
    printf("Please enter the full path of the directory to calculate total size:\n");
    scanf("%s",directory_path);

    //We will use the "ls" command to get a list of files and directories in the given directory
    char ls_command[200];
    sprintf(ls_command,"ls %s",directory_path); //Constructing the command with the given directory path
    FILE *ls_output = popen(ls_command,"r"); //Opening a pipe to read the output of the command
    if(ls_output==NULL){
        printf("Error executing the 'ls' command.\n");
        return -1;
    }
    char file_name[100];
    long int total_size=0; //Stores the total size of all files in the directory
    while(fscanf(ls_output,"%s",file_name)!=EOF){
        char file_path[200]; //Stores the full path of the file
        sprintf(file_path,"%s/%s",directory_path,file_name); //Constructing the full path of the file
        FILE *file = fopen(file_path,"r"); //Opening a file descriptor to read file contents
        if(file==NULL){
            printf("Error opening file %s\n",file_path);
            continue; //Ignore this file and move on to next file
        }
        //Get the size of the file and add it to the total size
        fseek(file,0L,SEEK_END);
        long int file_size = ftell(file);
        total_size += file_size;
        fclose(file);
    }
    printf("Total size of all files in directory %s: %ld bytes\n",directory_path,total_size);
    pclose(ls_output);
    return 0;
}