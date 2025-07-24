//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX 100

int main()
{
  // generating unique key for shared memory segment
  key_t key = ftok("shared_memory", 'a');
  if (key == -1) {
    perror("ftok failed");
    exit(1);
  }

  // creating shared memory segment
  int shmid = shmget(key, MAX, 0666|IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  // attaching shared memory segment to process space
  char* ptr = (char*) shmat(shmid, (void*) 0, 0);
  if (ptr == (void*) -1) {
    perror("shmat failed");
    exit(1);
  }

  // writing data to shared memory segment
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  sprintf(ptr, "Current time is: %s", asctime(timeinfo));

  // forking child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork failed");
    exit(1);
  }
  else if (pid == 0) { // child process
    // attaching shared memory segment to child process space
    char* ptr_child = (char*) shmat(shmid, (void*) 0, 0);
    if (ptr_child == (void*) -1) {
      perror("shmat failed for child process");
      exit(1);
    }

    // reading data from shared memory segment
    printf("Message from parent process: %s\n", ptr_child);

    // detaching shared memory segment from child process space
    if (shmdt(ptr_child) == -1) {
      perror("shmdt failed for child process");
      exit(1);
    }

    exit(0);
  }
  else { // parent process
    // waiting for child process to finish
    int status;
    if (waitpid(pid, &status, 0) == -1) {
      perror("waitpid failed");
      exit(1);
    }

    // detaching shared memory segment from parent process space
    if (shmdt(ptr) == -1) {
      perror("shmdt failed for parent process");
      exit(1);
    }

    // releasing shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
      perror("shmctl failed");
      exit(1);
    }
  }

  return 0;
}