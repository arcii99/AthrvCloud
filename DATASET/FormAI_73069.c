//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define MESSAGE "Hello, this is a message from process 1!"

int main() {
  // Create a named pipe
  char *pipe_name = "/tmp/ipc_pipe";
  mkfifo(pipe_name, 0666);

  // Open the pipe for writing
  int fd = open(pipe_name, O_WRONLY);

  // Send a message to process 2
  write(fd, MESSAGE, strlen(MESSAGE) + 1);
  printf("Process 1 sent message: %s\n", MESSAGE);

  // Close the pipe
  close(fd);

  return EXIT_SUCCESS;
}