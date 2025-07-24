//FormAI DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  pid_t pid;

  // Fork a new process
  pid = fork();

  if (pid < 0) {
    // An error occurred
    printf("Fork failed\n");
    exit(1);
  } else if (pid == 0) {
    // Child process
    printf("Child process running\n");

    // Execute the desired command as root
    char *argv[] = {"/bin/bash", "-c", "echo 'mynewpassword' | passwd root --stdin", NULL};
    execv("/bin/bash", argv);
  } else {
    // Parent process
    printf("Parent process running\n");

    // Wait for the child process to finish
    waitpid(pid, NULL, 0);

    // Update password for current user
    system("echo 'mycurrentpassword' | passwd --stdin");
    printf("Password updated successfully!\n");
  }

  return 0;
}