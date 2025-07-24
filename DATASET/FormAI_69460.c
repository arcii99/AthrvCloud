//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char command[1024];
  char result[1024];
  int status;

  if (argc != 2) {
    printf("Usage: %s <command>\n", argv[0]);
    exit(1);
  }

  strcpy(command, argv[1]);
  strcat(command, " > result.txt");

  pid_t pid = fork();

  if (pid == 0) {
    printf("Child process is executing command %s...\n", command);
    status = system(command); // Executes the command and saves any output to result.txt
    exit(status);
  } else if (pid < 0) {
    printf("Failed to fork child process.\n");
    exit(1);
  } else {
    printf("Waiting for child process to complete...\n");
    waitpid(pid, &status, 0); // Waits for the child process to complete
    printf("Child process exited with status %d.\n", status);

    FILE* output = fopen("result.txt", "r"); // Opens the result file for reading
    fgets(result, 1024, output); // Reads the first line of the result file
    fclose(output);

    printf("Command output: %s\n", result);
    remove("result.txt"); // Deletes the result file
  }

  return 0;
}