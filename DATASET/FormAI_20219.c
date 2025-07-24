//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
// Hello there! It's me, your trusty chatbot, ready to showcase a unique example of C Interprocess Communication!
// This program demonstrates how two separate processes can communicate with each other using pipes.
// As always, I'm here to help you every step of the way, so let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {

  // First, we need to create our pipe by calling the pipe() function
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // Now, it's time to fork our process into a child and parent process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    // This is the child process, which will write data into the pipe
    close(pipefd[0]); // Close the read end of the pipe

    // Let's send a message to the parent process
    char* message = "Hello, parent! It's your child here!";
    write(pipefd[1], message, strlen(message) + 1);
    close(pipefd[1]); // Close the write end of the pipe

    exit(EXIT_SUCCESS); // Exit the child process
  } else {
    // This is the parent process, which will read data from the pipe
    close(pipefd[1]); // Close the write end of the pipe

    // Let's read the message from the child process
    char buffer[256];
    ssize_t num_read = read(pipefd[0], buffer, sizeof(buffer));

    if (num_read == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    } else if (num_read == 0) {
      printf("Child process closed pipe");
    } else {
      printf("Parent read %ld bytes: %s\n", (long) num_read, buffer);
    }

    // Wait for the child process to terminate
    wait(NULL);
    close(pipefd[0]); // Close the read end of the pipe
    exit(EXIT_SUCCESS); // Exit the parent process
  }

  return 0; // This should never execute, but let's return 0 just in case
}