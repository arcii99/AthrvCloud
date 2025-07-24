//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define SHARED_MEM_SIZE 128

int main() {
  int fd = shm_open("/my_shared_mem", O_CREAT | O_RDWR, 0666);
  if (fd < 0) {
    perror("shm_open failed");
    exit(1);
  }

  if (ftruncate(fd, SHARED_MEM_SIZE) == -1) {
    perror("ftruncate failed");
    exit(1);
  }

  char *shared_mem = mmap(NULL, SHARED_MEM_SIZE,
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED, fd, 0);
  if (shared_mem == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }

  pid_t pid1 = fork();
  if (pid1 < 0) {
    perror("fork failed");
    exit(1);
  } else if (pid1 == 0) {
    // child process

    printf("[child] writing to shared memory...\n");
    sprintf(shared_mem, "Hello from child process");

    exit(0);
  } else {
    // parent process

    wait(NULL);

    printf("[parent] read from shared memory: %s\n", shared_mem);
  }

  if (munmap(shared_mem, SHARED_MEM_SIZE) == -1) {
    perror("munmap failed");
    exit(1);
  }
  if (close(fd) == -1) {
    perror("close failed");
    exit(1);
  }
  if (shm_unlink("/my_shared_mem") == -1) {
    perror("shm_unlink failed");
    exit(1);
  }

  return 0;
}