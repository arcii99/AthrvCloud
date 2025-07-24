//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 1024

int main() {
  int pid;
  int shmid;
  key_t key;
  char *shmaddr;
  
  /* create a shared memory segment */
  key = ftok(".", 'x');
  shmid = shmget(key, SHMSIZE, IPC_CREAT | IPC_EXCL | 0666);
  
  /* fork a child process */
  pid = fork();
  if (pid < 0) {
    perror("fork failed");
    exit(1);
  } else if (pid == 0) { /* child process */
    /* attach to the shared memory segment */
    shmaddr = shmat(shmid, 0, 0);
    
    /* write a message to the shared memory segment */
    sprintf(shmaddr, "Hello, this is the child process!");
    
    /* detach from the shared memory segment */
    shmdt(shmaddr);
  } else { /* parent process */
    /* wait for the child process to finish */
    wait(NULL);
    
    /* attach to the shared memory segment */
    shmaddr = shmat(shmid, 0, 0);
    
    /* print the message written by the child process */
    printf("Parent received message: %s\n", shmaddr);
    
    /* detach from the shared memory segment */
    shmdt(shmaddr);
    
    /* delete the shared memory segment */
    shmctl(shmid, IPC_RMID, 0);
  }
  
  return 0;
}