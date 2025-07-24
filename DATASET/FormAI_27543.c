//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main() {
  // declare variables
  char command[BUFFER_SIZE];
  char output[BUFFER_SIZE];
  FILE *fp;

  // get user input
  printf("Enter a command: ");
  fgets(command, BUFFER_SIZE, stdin);
  strtok(command, "\n"); // remove trailing newline

  // fork process to execute command
  pid_t pid = fork();

  if (pid == -1) { // error case
    printf("Error: fork failed.\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { // child process
    int status = system(command);
    exit(status);
  } else { // parent process
    wait(NULL); // wait for child process to finish
    printf("Output of command:\n");

    // read output from file
    fp = fopen("output.txt", "r");

    while (fgets(output, BUFFER_SIZE, fp) != NULL) {
      printf("%s", output);
    }

    fclose(fp);
    remove("output.txt"); // delete output file
  }

  return 0;
}