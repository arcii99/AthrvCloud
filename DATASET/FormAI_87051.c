//FormAI DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024

// Function to clean up input string
void cleanup(char* input) {
    char* p = strchr(input, '\n');
    if (p != NULL) *p = '\0';
}

// Function to check spelling of a word
void spell_check(char* word) {
    char* command = "/usr/bin/aspell -a -x";
    char input[BUFSIZE];
    char output[BUFSIZE];

    // Create pipes to communicate with child process 
    int fdin[2], fdout[2];
    if (pipe(fdin) < 0 || pipe(fdout) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork child process 
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process: setup pipes, execute command, and read output
        close(fdin[1]);
        close(fdout[0]);
        dup2(fdin[0], STDIN_FILENO);
        dup2(fdout[1], STDOUT_FILENO);
        execl("/bin/sh", "sh", "-c", command, NULL);
        exit(EXIT_FAILURE);
    }
    else {
        // Parent process: write input to child process, read output, and wait for child process to exit
        close(fdin[0]);
        close(fdout[1]);
        write(fdin[1], word, strlen(word));
        write(fdin[1], "\n", sizeof(char));
        close(fdin[1]);
        read(fdout[0], output, BUFSIZE);
        wait(NULL);
    }

    // Parse output and print suggestions or confirmation of correct spelling
    sscanf(output, "%*[^\n]\n%[^\n]", input);
    if (strcmp(input, "*")) {
        sscanf(output, "%*s %*s %255s", input);
        printf("Did you mean \"%s\"?\n", input);
    }
    else {
        printf("The word \"%s\" is spelled correctly.\n", word);
    }
}

int main() {
    char input[BUFSIZE];
    while (1) {
        printf("Enter a word to check spelling (or type \"quit\" to exit): ");
        fgets(input, BUFSIZE, stdin);
        cleanup(input);
        if (!strcmp(input, "quit")) break;
        spell_check(input);
    }
    return 0;
}