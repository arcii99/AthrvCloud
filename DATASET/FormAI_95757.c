//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main(void) {
  pid_t pid;
  key_t key;
  int shmid;
  char *data;
  int status;

  /* set up shared memory */
  key = 5678;
  if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }
  if ((data = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  /* fork child process */
  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    /* child process */
    printf("Child process writing to shared memory.\n");
    sprintf(data, "Hello, parent process!\n");
    _exit(0);
  } else {
    /* parent process */
    wait(&status);
    printf("Parent process reading from shared memory.\n");
    printf("%s", data);
  }

  /* detach and remove shared memory */
  shmdt(data);
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}