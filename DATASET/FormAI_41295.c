//FormAI DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>

int main() {
    pid_t pid;
    sem_t* sem;

    int fd = shm_open("example_shm", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error creating shared memory!");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, sizeof(int)) == -1) {
        perror("Error truncating shared memory!");
        exit(EXIT_FAILURE);
    }

    sem = sem_open("example_sem", O_CREAT, 0666, 0);
    if (sem == SEM_FAILED) {
        perror("Error creating semaphore!");
        exit(EXIT_FAILURE);
    }

    int* shared_data = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_data == MAP_FAILED) {
        perror("Error mapping shared memory!");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("Error forking!");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        printf("Child process waiting for semaphore...\n");
        sem_wait(sem);
        printf("Child process received semaphore!\n");
        printf("Child process reading shared data: %d\n", *shared_data);
        exit(EXIT_SUCCESS);
    } else { // parent process
        printf("Parent process writing to shared data...\n");
        *shared_data = 42;
        printf("Parent process signaling semaphore...\n");
        sem_post(sem);
        wait(NULL);
        sem_unlink("example_sem");
        munmap(shared_data, sizeof(int));
        close(fd);
        shm_unlink("example_shm");
        exit(EXIT_SUCCESS);
    }
}