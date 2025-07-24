//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
/*
Romeo and Juliet IPC example program

This program demonstrates interprocess communication using pipes and fork.
The parent process represents Romeo and the child process represents Juliet.
They communicate by exchanging messages using the pipes.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

int romeo_love_juliet(int *love_pipe);
int juliet_love_romeo(int *love_pipe);

int main() {
    int love_pipe[2];
    pid_t pid;

    if (pipe(love_pipe) == -1) {
        fprintf(stderr, "Failed to create love pipe!\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process, Juliet
        return juliet_love_romeo(love_pipe);
    } else {
        // Parent process, Romeo
        return romeo_love_juliet(love_pipe);
    }
}

int romeo_love_juliet(int *love_pipe) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Romeo: Ah, my dear Juliet, I long to express my love to you!\n");
    printf("Romeo: Let me write you a love letter...\n");
    strcpy(buffer, "My dearest Juliet,\n\n");
    strcat(buffer, "I cannot imagine living without you. Your beauty and grace light up my world. ");
    strcat(buffer, "Please, will you do me the honour of being my everlasting love?\n\n");
    strcat(buffer, "Forever yours,\nRomeo");
    close(love_pipe[0]);
    write(love_pipe[1], buffer, strlen(buffer)+1);
    printf("Romeo: My love letter is on its way to you, Juliet!\n");

    close(love_pipe[1]);
    bytes_read = read(love_pipe[0], buffer, BUFFER_SIZE);
    printf("Romeo: Ah, a letter from Juliet!\n");
    printf("Romeo: %s\n", buffer);

    return EXIT_SUCCESS;
}

int juliet_love_romeo(int *love_pipe) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = read(love_pipe[0], buffer, BUFFER_SIZE);
    printf("Juliet: Oh, a letter from Romeo!\n");
    printf("Juliet: %s\n", buffer);

    printf("Juliet: Let me write a reply...\n");
    strcpy(buffer, "My sweet Romeo,\n\n");
    strcat(buffer, "Your words fill my heart with joy and love. Yes, I will be your forever love, ");
    strcat(buffer, "together we will conquer the world. \n\n");
    strcat(buffer, "Yours always,\nJuliet");
    close(love_pipe[0]);
    write(love_pipe[1], buffer, strlen(buffer)+1);
    printf("Juliet: My reply is on its way to you, Romeo!\n");

    close(love_pipe[1]);
    return EXIT_SUCCESS;
}