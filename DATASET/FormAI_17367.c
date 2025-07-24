//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

// This function is called by the parent process
void read_from_pipe(int fd) {
  char buffer[BUFSIZ + 1];
  int bytes_read = read(fd, buffer, BUFSIZ);
  buffer[bytes_read] = '\0';
  printf("[PARENT] %d bytes read from pipe: %s\n", bytes_read, buffer);
}

// This function is called by the child process
void write_to_pipe(int fd, char* message) {
  int bytes_written = write(fd, message, strlen(message));
  printf("[CHILD] %d bytes written to pipe: %s\n", bytes_written, message);
}

int main(int argc, char *argv[]) {
  int pipefd[2];
  pid_t pid;

  // Create the pipe
  if (pipe(pipefd) == -1) {
    perror("pipe failed");
    exit(EXIT_FAILURE);
  }

  // Fork the process
  pid = fork();

  if (pid == -1) {
    perror("fork failed");
    exit(EXIT_FAILURE);
  }

  else if (pid == 0) {
    // This is the child process

    // Close the read end of the pipe
    close(pipefd[0]);

    // Write a message to the pipe
    write_to_pipe(pipefd[1], "Hello from the child process!");

    // Close the write end of the pipe
    close(pipefd[1]);
  }

  else {
    // This is the parent process

    // Close the write end of the pipe
    close(pipefd[1]);

    // Read the message from the pipe
    read_from_pipe(pipefd[0]);

    // Close the read end of the pipe
    close(pipefd[0]);

    // Wait for the child process to finish
    wait(NULL);

    printf("[PARENT] Child process finished.\n");
  }

  return EXIT_SUCCESS;
}