//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

void hash(char* message, unsigned char* output) {
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, (unsigned char*) message, strlen(message));
    SHA256_Final(output, &context);
}

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[0]); // Close unused read end

        char message[256];
        unsigned char output[SHA256_DIGEST_LENGTH];
        printf("Enter a message to hash: ");
        fgets(message, 256, stdin);

        hash(message, output);

        if (write(pipefd[1], output, SHA256_DIGEST_LENGTH) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); // Close write end
        printf("Child process exiting\n");
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[1]); // Close unused write end

        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int fd;
            unsigned char output[SHA256_DIGEST_LENGTH];
            printf("Parent process waiting for child to complete\n");

            if (read(pipefd[0], output, SHA256_DIGEST_LENGTH) == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            printf("Hashed message: ");

            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                printf("%02x", output[i]);
            }

            printf("\n");

            close(pipefd[0]); // Close read end
        } else {
            printf("Child process terminated abnormally\n");
        }

        printf("Parent process exiting\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}