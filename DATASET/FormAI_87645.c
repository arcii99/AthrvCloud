//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define SHMSZ 27

int main()
{
  sem_t *sem; // create semaphore
  int shmid;
  char *shm, *s;

  // create semaphore
  sem = sem_open("mysem", O_CREAT, 0644, 1);
  if(sem == SEM_FAILED) {
    perror("sem_open");
    exit(EXIT_FAILURE);
  }

  // create shared memory
  shmid = shm_open("/myshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if(shmid == -1) {
    perror("shm_open");
    exit(EXIT_FAILURE);
  }

  // give shared memory size
  if(ftruncate(shmid, SHMSZ) == -1) {
    perror("ftruncate");
    exit(EXIT_FAILURE);
  }

  // map shared memory
  shm = mmap(NULL, SHMSZ, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
  if(shm == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // write to shared memory
  s = shm;
  for(char c = 'a'; c <= 'z'; c++) {
    sem_wait(sem); // wait semaphore
    *s++ = c;
    sem_post(sem); // signal semaphore
  }
  sem_wait(sem);
  *s = '\0';
  sem_post(sem); // signal semaphore

  // create child process
  pid_t pid = fork();

  if(pid < 0) { // fork error
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0) { // child process
    char *cshm, *cs;

    // map shared memory
    cshm = mmap(NULL, SHMSZ, PROT_READ, MAP_SHARED, shmid, 0);
    if(cshm == MAP_FAILED) {
      perror("mmap");
      exit(EXIT_FAILURE);
    }

    // read from shared memory
    cs = cshm;
    while(*cs != '\0') {
      putchar(*cs++);
      usleep(10000); // add delay to simulate slower reading speed
    }
    putchar('\n');

    // cleanup
    if(munmap(cshm, SHMSZ) == -1) {
      perror("munmap");
      exit(EXIT_FAILURE);
    }
    if(shm_unlink("/myshm") == -1) {
      perror("shm_unlink");
      exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
  }

  // wait for child process
  if(wait(NULL) == -1) {
    perror("wait");
    exit(EXIT_FAILURE);
  }

  // cleanup
  if(munmap(shm, SHMSZ) == -1) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }
  if(sem_close(sem) == -1) {
    perror("sem_close");
    exit(EXIT_FAILURE);
  }
  if(sem_unlink("mysem") == -1) {
    perror("sem_unlink");
    exit(EXIT_FAILURE);
  }
  if(close(shmid) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}