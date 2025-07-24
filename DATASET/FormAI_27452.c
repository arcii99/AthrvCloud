//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main(){
  int shmid;
  key_t key;
  char *shm,*s;

  // create a shared memory segment
  key = ftok("shmfile", 65);
  shmid = shmget(key, 1024, 0666|IPC_CREAT);

  //attach shared memory segment to the process
  shm = (char*) shmat(shmid, (void*)0, 0);

  //Write data to the shared memory segment
   sprintf(shm, "Hello from process with pid %d", getpid());

  //Print data written in the shared memeory segment
  printf("Process %d wrote %s\n", getpid(), shm);

  //Switching to child process to read from shared memory segment
  pid_t pid=fork();
  if (pid == 0)
  {
    printf("This is child process (%d).\n", getpid());
    printf("Reading from shared memory : %s\n", shm);
    exit(0);
  }
  else
  {
    //Parent process waits for the child to complete
    wait(NULL);
  }

  //Detaching shared memory segment
  shmdt(shm);

  //Deleting shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}