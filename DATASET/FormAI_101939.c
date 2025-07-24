//FormAI DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main() {

    // Set up variables for pipe
    int parent_to_child[2];
    int child_to_parent[2];

    // Create pipe
    if(pipe(parent_to_child) != 0) {
        perror("Error creating parent to child pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(child_to_parent) != 0) {
        perror("Error creating child to parent pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    // Error check for fork
    if(pid < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    }
    // Child process
    else if(pid == 0) {
        // Close unused ends of pipe
        close(parent_to_child[1]);
        close(child_to_parent[0]);

        // Read message from parent
        char message[100];
        if(read(parent_to_child[0], message, sizeof(message)) < 0) {
            perror("Error reading message from parent");
            exit(EXIT_FAILURE);
        }
        printf("Child process received message: %s\n", message);

        // Send message back to parent
        char reply[100] = "Message received by child";
        if(write(child_to_parent[1], reply, strlen(reply) + 1) < 0) {
            perror("Error writing message to parent");
            exit(EXIT_FAILURE);
        }

        // Close pipes and exit
        close(parent_to_child[0]);
        close(child_to_parent[1]);
        exit(EXIT_SUCCESS);
    }
    // Parent process
    else {
        // Close unused ends of pipe
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        // Send message to child
        char message[100] = "Hello from parent";
        if(write(parent_to_child[1], message, strlen(message) + 1) < 0) {
            perror("Error writing message to child");
            exit(EXIT_FAILURE);
        }

        // Wait for reply from child
        char reply[100];
        if(read(child_to_parent[0], reply, sizeof(reply)) < 0) {
            perror("Error reading reply from child");
            exit(EXIT_FAILURE);
        }
        printf("Parent process received reply: %s\n", reply);

        // Close pipes and wait for child to exit
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        wait(NULL);
    }

    return 0;
}