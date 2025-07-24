//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

// define key for shared memory
#define SHMKEY 1234

// define size of shared memory segment
#define SHMSIZE 20

int main() {

  int shmid;
  int pid;
  char *shared_memory, *message;
  key_t key = SHMKEY;

  // create shared memory segment
  if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // attach shared memory segment
  if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // write message to shared memory
  message = "Hello, world!";
  sprintf(shared_memory, "%s", message);

  // fork a child process
  pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  // child process reads message from shared memory and prints it to stdout
  else if (pid == 0) {
    printf("Child process reading from shared memory: %s\n", shared_memory);
    exit(0);
  }

  // parent process waits for child process to finish
  else {
    wait(NULL);
    printf("Parent process finished\n");
  }

  // detach shared memory segment
  if (shmdt(shared_memory) == -1) {
    perror("shmdt");
    exit(1);
  }

  // remove shared memory segment
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}