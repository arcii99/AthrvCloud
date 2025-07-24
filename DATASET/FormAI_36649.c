//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (access(argv[1], F_OK) != 0) {
        fprintf(stderr, "File does not exist\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork process\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        char *args[4];
        args[0] = "chmod";
        args[1] = "700";
        args[2] = filename;
        args[3] = NULL;
        execvp(args[0], args);
    } else { // Parent process
        wait(NULL);
        printf("File permissions updated successfully!\n");
    }

    return 0;
}