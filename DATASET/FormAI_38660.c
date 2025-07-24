//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>

// Constants
#define SHM_NAME "/paranoid_shm_example"
#define SEM_NAME "/paranoid_sem_example"
#define MAX_MSG_SIZE 100

// Structure for shared memory
typedef struct {
    char msg[MAX_MSG_SIZE];
} shared_mem;

// Global variables
shared_mem *shared_mem_ptr;
sem_t *sem_ptr;

// Function to write to shared memory
void write_to_shared_mem(char *msg) {
    if (sem_wait(sem_ptr) == -1) {
        perror("Error in semaphore wait");
        exit(EXIT_FAILURE);
    }

    snprintf(shared_mem_ptr->msg, MAX_MSG_SIZE, "%s", msg);

    if(sem_post(sem_ptr) == -1) {
        perror("Error in semaphore post");
        exit(EXIT_FAILURE);
    }
}

// Function to read from shared memory
void read_from_shared_mem() {
    if (sem_wait(sem_ptr) == -1) {
        perror("Error in semaphore wait");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s\n", shared_mem_ptr->msg);

    if(sem_post(sem_ptr) == -1) {
        perror("Error in semaphore post");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Initialize shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if(shm_fd == -1){
        perror("Error in creating shared memory");
        exit(EXIT_FAILURE);
    }

    if(ftruncate(shm_fd, sizeof(shared_mem)) == -1) {
        perror("Error in truncating shared memory");
        exit(EXIT_FAILURE);
    }

    shared_mem_ptr = mmap(NULL, sizeof(shared_mem), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(shared_mem_ptr == MAP_FAILED){
        perror("Error while mapping shared memory");
        exit(EXIT_FAILURE);
    }

    // Initialize semaphore
    sem_ptr = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
    if(sem_ptr == SEM_FAILED){
        perror("Error in creating semaphore");
        exit(EXIT_FAILURE);
    }

    // Generate sample message
    char sample_msg[MAX_MSG_SIZE] = "This message should not be intercepted!";

    // Write message to shared memory
    write_to_shared_mem(sample_msg);

    // Read message from shared memory
    read_from_shared_mem();

    // Remove semaphore
    if(sem_unlink(SEM_NAME) == -1){
        perror("Error in removing semaphore");
        exit(EXIT_FAILURE);
    }

    // Remove shared memory
    if(shm_unlink(SHM_NAME) == -1){
        perror("Error in removing shared memory");
        exit(EXIT_FAILURE);
    }

    return 0;
}