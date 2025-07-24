//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
// This program demonstrates interprocess communication using shared memory between two processes
// A producer process writes a series of numbers to shared memory and a consumer process reads them
// Both processes synchronize using semaphores

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHARED_MEM_NAME "/shared_mem_example"
#define SEM_PRODUCER_NAME "/producer_semaphore"
#define SEM_CONSUMER_NAME "/consumer_semaphore"

int main() {
    sem_t* producer_semaphore;
    sem_t* consumer_semaphore;
    int shared_mem_fd;
    int* shared_mem_ptr;
    pid_t pid;

    // Create shared memory object
    shared_mem_fd = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    if (shared_mem_fd == -1) {
        perror("Unable to create shared memory object");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(shared_mem_fd, sizeof(int)) == -1) {
        perror("Unable to allocate shared memory");
        exit(EXIT_FAILURE);
    }

    // Map shared memory object
    shared_mem_ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, 0);
    if (shared_mem_ptr == MAP_FAILED) {
        perror("Unable to map shared memory");
        exit(EXIT_FAILURE);
    }

    // Create semaphores
    producer_semaphore = sem_open(SEM_PRODUCER_NAME, O_CREAT | O_EXCL, 0666, 1);
    if (producer_semaphore == SEM_FAILED) {
        perror("Unable to create producer semaphore");
        exit(EXIT_FAILURE);
    }
    consumer_semaphore = sem_open(SEM_CONSUMER_NAME, O_CREAT | O_EXCL, 0666, 0);
    if (consumer_semaphore == SEM_FAILED) {
        perror("Unable to create consumer semaphore");
        exit(EXIT_FAILURE);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("Unable to create process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process (consumer)
        int i;
        for (i = 0; i < 10; i++) {
            sem_wait(consumer_semaphore);
            printf("Consumer received: %d\n", *shared_mem_ptr);
            sem_post(producer_semaphore);
        }
    } else {
        // Parent process (producer)
        int i;
        for (i = 0; i < 10; i++) {
            sem_wait(producer_semaphore);
            *shared_mem_ptr = i;
            printf("Producer sent: %d\n", *shared_mem_ptr);
            sem_post(consumer_semaphore);
        }
    }

    // Cleanup
    sem_close(producer_semaphore);
    sem_close(consumer_semaphore);
    sem_unlink(SEM_PRODUCER_NAME);
    sem_unlink(SEM_CONSUMER_NAME);
    munmap(shared_mem_ptr, sizeof(int));
    shm_unlink(SHARED_MEM_NAME);

    return 0;
}