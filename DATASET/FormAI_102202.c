//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const int BUFFER_SIZE = 1024;

void parent_process(int read_fd, int write_fd) {
    char message[BUFFER_SIZE];
    while (1) {
        printf("Enter message for child process: ");
        fgets(message, BUFFER_SIZE, stdin);
        write(write_fd, message, BUFFER_SIZE);
        if (strcmp(message, "exit\n") == 0) {
            break;
        }
        read(read_fd, message, BUFFER_SIZE);
        printf("Received message from child process: %s", message);
    }
    
    close(read_fd);
    close(write_fd);
    printf("Parent Process ending.. \n");
    exit(EXIT_SUCCESS);
}

void child_process(int read_fd, int write_fd) {
    char message[BUFFER_SIZE];
    while (1) {
        read(read_fd, message, BUFFER_SIZE);
        if (strcmp(message, "exit\n") == 0) {
            break;
        }
        printf("Received message from parent process: %s", message);
        printf("Enter message for parent process: ");
        fgets(message, BUFFER_SIZE, stdin);
        write(write_fd, message, BUFFER_SIZE);
    }
    
    close(read_fd);
    close(write_fd);
    printf("Child Process ending.. \n");
    exit(EXIT_SUCCESS);
}

int main() {
    int parent_to_child[2];
    int child_to_parent[2];
    if (pipe(parent_to_child) < 0) {
        perror("Error creating parent-to-child pipe\n");
        exit(EXIT_FAILURE);
    }
    if (pipe(child_to_parent) < 0) {
        perror("Error creating child-to-parent pipe\n");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error creating child process\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Starting child process.. \n");
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        child_process(parent_to_child[0], child_to_parent[1]);
    }
    else {
        printf("Starting parent process.. \n");
        close(parent_to_child[0]);
        close(child_to_parent[1]);
        parent_process(child_to_parent[0], parent_to_child[1]);
        waitpid(pid, NULL, 0);
    }
    
    return 0;
}