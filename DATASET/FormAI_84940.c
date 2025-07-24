//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_MSG_LENGTH 256

int main(int argc, char* argv[]) {
  // Define variables for process communication
  int pipefd[2];
  pid_t cpid;
  char msg[MAX_MSG_LENGTH];
  char other_msg[MAX_MSG_LENGTH];

  // Create the pipe
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // Fork a child process
  cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {  // Child process
    close(pipefd[1]);  // Close unused write end of the pipe
    
    // Read data from pipe
    if (read(pipefd[0], other_msg, MAX_MSG_LENGTH) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    
    printf("Child process received message: %s\n", other_msg);
    
    close(pipefd[0]); // Close read end of pipe
    exit(EXIT_SUCCESS);

  } else {  // Parent process
    close(pipefd[0]);  // Close unused read end of the pipe
    
    printf("Please enter a message: ");
    if (fgets(msg, MAX_MSG_LENGTH, stdin) == NULL) {
      perror("fgets");
      exit(EXIT_FAILURE);
    }
    
    // Write data to pipe
    if (write(pipefd[1], msg, strlen(msg)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }
    
    close(pipefd[1]);  // Close write end of pipe

    printf("Parent process sent message: %s\n", msg);
    
    // Wait for child process to finish
    wait(NULL);
    exit(EXIT_SUCCESS);
  }
}