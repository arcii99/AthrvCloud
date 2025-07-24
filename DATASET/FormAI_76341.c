//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SEM_NAME "/file_sync_semaphore"

int main(int argc, char** argv) {
    int fd;
    sem_t* sem;

    // Open the file for synchronization
    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Create the semaphore for synchronization
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("Failed to create semaphore");
        exit(EXIT_FAILURE);
    }

    // Acquire the semaphore
    if (sem_wait(sem) == -1) {
        perror("Failed to acquire semaphore");
        exit(EXIT_FAILURE);
    }

    // Perform some operation on the shared file
    lseek(fd, 0, SEEK_SET);
    write(fd, "Hello world!", 12);

    // Release the semaphore
    if (sem_post(sem) == -1) {
        perror("Failed to release semaphore");
        exit(EXIT_FAILURE);
    }

    // Close the file and semaphore
    close(fd);
    sem_close(sem);
    sem_unlink(SEM_NAME);

    return 0;
}