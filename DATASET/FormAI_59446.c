//FormAI DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    if (argc != 2) { // checks for correct number of args
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* path = argv[1]; // path to directory
    struct stat st = {0};

    if (stat(path, &st) == -1) { // creates directory if it doesn't exist
        mkdir(path, 0700);
        printf("Directory has been created: %s\n", path);
    } else {
        printf("Directory already exists: %s\n", path);
    }

    int script_pid = fork(); // forks process to execute script

    if (script_pid == 0) { // child process
        char* const script[] = {"/bin/sh", "script.sh", path, NULL}; // command to execute script
        execvp(script[0], script);
        exit(EXIT_SUCCESS);
    }

    int status;
    waitpid(script_pid, &status, 0); // waits for child process to finish

    if (WIFEXITED(status)) { // checks if child process returned normally
        printf("Script exited normally with code %d\n", WEXITSTATUS(status));
    } else {
        printf("Script did not exit normally.\n");
    }

    return 0;
}