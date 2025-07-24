//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int parent_to_child[2], child_to_parent[2];
    pid_t pid;

    if ((pipe(parent_to_child) == -1) || (pipe(child_to_parent) == -1)) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(parent_to_child[1]); // Close the write end of the parent_to_child pipe
        close(child_to_parent[0]); // Close the read end of the child_to_parent pipe

        char buffer[BUFFER_SIZE];
        while (1) {
            ssize_t num_bytes_read = read(parent_to_child[0], buffer, BUFFER_SIZE);
            if (num_bytes_read == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            if (num_bytes_read == 0) {
                break;
            }
            buffer[num_bytes_read] = '\0';
            printf("Child received message: %s", buffer);

            // Reverse the message
            int length = strlen(buffer);
            for (int i = 0; i < length / 2; i++) {
                char temp = buffer[i];
                buffer[i] = buffer[length - i - 1];
                buffer[length - i - 1] = temp;
            }

            if (write(child_to_parent[1], buffer, num_bytes_read) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Clean up
        close(parent_to_child[0]);
        close(child_to_parent[1]);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(parent_to_child[0]); // Close the read end of the parent_to_child pipe
        close(child_to_parent[1]); // Close the write end of the child_to_parent pipe

        char buffer[BUFFER_SIZE];
        while (1) {
            printf("Enter a message: ");
            if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
                break;
            }
            ssize_t num_bytes_written = write(parent_to_child[1], buffer, strlen(buffer));
            if (num_bytes_written == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            num_bytes_written = read(child_to_parent[0], buffer, BUFFER_SIZE);
            if (num_bytes_written == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            } else {
                printf("Parent received message: %s", buffer);
            }
        }

        // Clean up
        close(parent_to_child[1]);
        close(child_to_parent[0]);
        wait(NULL); // Wait for the child process to terminate
        exit(EXIT_SUCCESS);
    }

    return 0;
}