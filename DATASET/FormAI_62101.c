//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
/* This C program demonstrates an Interprocess communication
 * between a parent and child process using shared memory and
 * semaphores in a introspective style.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHM_SIZE 1024 /* shared memory size */
#define SEM_NAME "/my_semaphore" /* semaphore name */

int main(void) {
  int shm_fd, pid;
  char *shm_ptr;

  /* Open shared memory object */
  if ((shm_fd = shm_open("/my_shared_mem", O_CREAT | O_RDWR, 0666)) == -1) {
    perror("shm_open");
    exit(1);
  }

  /* Configure size of shared memory object */
  if (ftruncate(shm_fd, SHM_SIZE) == -1) {
    perror("ftruncate");
    exit(1);
  }

  /* Map shared memory object in address space of process */
  if ((shm_ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0)) == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  /* Create a semaphore */
  sem_t *semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
  if (semaphore == SEM_FAILED) {
    perror("sem_open");
    exit(1);
  }

  if ((pid = fork())) {
    /* PARENT PROCESS */
    printf("Parent process created with PID %d\n", getpid());
    sem_wait(semaphore); /* wait for semaphore to be available */
    sprintf(shm_ptr, "Hello from Parent process with PID %d", getpid());
    sem_post(semaphore); /* indicate semaphore is available */
    wait(NULL);
  } else {
    /* CHILD PROCESS */
    printf("Child process created with PID %d\n", getpid());
    sem_wait(semaphore); /* wait for semaphore to be available */
    printf("Message: %s\n", shm_ptr);
    sem_post(semaphore); /* indicate semaphore is available */
    exit(0);
  }

  /* Unmap shared memory object from memory */
  if (munmap(shm_ptr, SHM_SIZE) == -1) {
    perror("munmap");
    exit(1);
  }

  /* Close shared memory object */
  if (close(shm_fd) == -1) {
    perror("close");
    exit(1);
  }

  /* Close and unlink semaphore */
  if (sem_close(semaphore) == -1) {
    perror("sem_close");
    exit(1);
  }

  if (sem_unlink(SEM_NAME) == -1) {
    perror("sem_unlink");
    exit(1);
  }

  return 0;
}