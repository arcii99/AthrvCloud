//FormAI DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27
#define SHMKEY 8675309

int main() {
  char c;
  int shmid;
  key_t key;
  char *shm, *s;

  // Set up shared memory
  key = SHMKEY;
  if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }
  
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // Write a message to shared memory
  s = shm;
  for (char c = 'a'; c <= 'z'; c++) {
    *s++ = c;
  }
  *s = '\0';

  
  // Read the message from shared memory
  for (s = shm; *s != '\0'; s++) {
    putchar(*s);
  }
  putchar('\n');

  // Detach from shared memory and delete
  shmdt(shm);
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}