//FormAI DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void spellCheck(char *filename) {
    // open file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // redirect stdin from file
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    // close file descriptor
    close(fd);

    // run aspell command asynchronously
    char *argv[] = {"aspell", "-a", NULL};
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // wait for child process to finish
    int status;
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    // output misspelled words
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, stdin) != NULL) {
        if (buf[0] == '&') { // skip suggestion or replacement line
            continue;
        }
        if (buf[0] == '*') { // mark misspelled word
            printf("Misspelled: %s\n", strtok(&buf[2], " \n"));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    spellCheck(argv[1]);

    return EXIT_SUCCESS;
}