//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h> 
#include <sys/types.h>
#include <sys/wait.h> 
#include <fcntl.h>
#include <semaphore.h>

#define SHMEM_SIZE 4096
#define SEM_NAME "/mysemaphore"

int main() {
    int fd_shm, pid; 
    char *shared_memory;
    sem_t *semaphore;

    // create a shared memory
    fd_shm = shm_open("/mymemory", O_CREAT | O_RDWR, 0666);
    if (fd_shm < 0) {
        perror("shm_open");
        exit(1);
    }

    // set the memory size
    ftruncate(fd_shm, SHMEM_SIZE);

    // map the shared memory to the process' address space
    shared_memory = mmap(NULL, SHMEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // create semaphore
    semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        
        sem_wait(semaphore); // wait for semaphore

        // Write a message to the shared memory
        sprintf(shared_memory, "Hello from the child!");

        sem_post(semaphore); // release semaphore
        exit(0);
    } else {
        // Parent process

        sem_wait(semaphore); // wait for semaphore

        // Read the message from the shared memory
        char message[SHMEM_SIZE];
        strcpy(message, shared_memory);

        sem_post(semaphore); // release semaphore

        printf("Message from child process: %s\n", message);
        wait(NULL);

        // Close and unlink semaphore
        sem_close(semaphore);
        sem_unlink(SEM_NAME);

        // Unmap and unlink shared memory
        munmap(shared_memory, SHMEM_SIZE);
        shm_unlink("/mymemory");
    }

    return 0;
}