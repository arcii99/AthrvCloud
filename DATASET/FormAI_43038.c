//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

//Function to find total size of directory
long int find_total_size(char* directory_path){
    pid_t pid;
    int pipefd[2];
    long int total_size = 0;

    if(pipe(pipefd) == -1){ //Creating pipe to send and receive data
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork(); //Creating child process to execute the command

    if(pid == -1){ 
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        close(pipefd[0]); //Close the read end of pipe

        if(dup2(pipefd[1], STDOUT_FILENO) == -1){ //Redirect child process output to pipe
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        char* args[] = {"du", "-sb", directory_path, NULL}; //Command to find size of directory in bytes
        if(execvp(args[0], args) == -1){ //Executing the command
            perror("exec");
            exit(EXIT_FAILURE);
        }

    } else {
        close(pipefd[1]); //Close the write end of pipe

        char buffer[1024]; //Buffer to read data from pipe
        ssize_t size_read;

        while((size_read = read(pipefd[0], buffer, sizeof(buffer))) != 0){ //Reading size of directory from pipe
            if(size_read == -1){
                perror("read");
            }
            total_size += strtol(buffer, NULL, 10); //Converting the string to long int and adding to total size
        }

        wait(NULL); //Waiting for child process to complete
    }

    return total_size;
}

//Function to list all the directories and files in the given directory
void list_directory_contents(char* directory_path){
    pid_t pid;
    int pipefd[2];

    if(pipe(pipefd) == -1){ //Creating pipe to send and receive data
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork(); //Creating child process to execute the command

    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        close(pipefd[0]); //Close the read end of pipe

        if(dup2(pipefd[1], STDOUT_FILENO) == -1){ //Redirect child process output to pipe
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        char* args[] = {"ls", "-lR", directory_path, NULL}; //Command to list the directories and files recursively
        if(execvp(args[0], args) == -1){ //Executing the command
            perror("exec");
            exit(EXIT_FAILURE);
        }

    } else {
        close(pipefd[1]); //Close the write end of pipe

        char buffer[1024]; //Buffer to read data from pipe
        ssize_t size_read;

        while((size_read = read(pipefd[0], buffer, sizeof(buffer))) != 0){ //Reading directories and files from pipe
            if(size_read == -1){
                perror("read");
            }
            printf("%.*s", (int) size_read, buffer); //Printing the directories and files
        }

        wait(NULL); //Waiting for child process to complete
    }
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]); //Error message for invalid number of arguments
        exit(EXIT_FAILURE);
    }

    char* directory_path = argv[1];

    printf("Total disk space used by %s: %ld bytes\n", directory_path, find_total_size(directory_path)); //Finding total size of directory and printing the result
    printf("List of directories and files in %s:\n", directory_path); //Printing the list of directories and files
    list_directory_contents(directory_path);

    return 0;
}