//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    printf("Are you ready for some C Interprocess Communication magic?!\n");

    int shared_memory_id;
    key_t key = ftok(".", 'a');

    // Let's create a shared memory segment
    if ((shared_memory_id = shmget(key, 1024, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    printf("Shared memory segment created!\n");

    char *shared_memory_data;

    // Now let's attach the shared memory
    if ((shared_memory_data = shmat(shared_memory_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Shared memory attached!\n");

    // Let's write some data to the shared memory
    sprintf(shared_memory_data, "Hello from Process 1!");

    printf("Data written to shared memory!\n");

    // Let's detach the shared memory segment
    if (shmdt(shared_memory_data) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Shared memory detached!\n");

    // Let's pause for a bit to allow Process 2 to attach the shared memory
    sleep(5);

    // Let's attach the shared memory again to read data written by Process 2
    if ((shared_memory_data = shmat(shared_memory_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Shared memory attached again!\n");

    printf("Data read from shared memory: %s\n", shared_memory_data);

    // Let's detach shared memory again
    if (shmdt(shared_memory_data) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Shared memory detached again!\n");

    // Let's now delete the shared memory segment
    if (shmctl(shared_memory_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory segment deleted!\n");

    printf("Interprocess Communication complete! Thanks for using the program!\n");

    return 0;
}