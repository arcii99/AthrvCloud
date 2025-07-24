//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/sem.h> 
#include <sys/shm.h>

#define SEM_ACCESS 0
#define SEM_MUTEX 1
#define SHM_MAX_SIZE 1024
#define SHM_KEY 12345
#define NUM_OF_CHILDREN 2

void sem_wait(int sem_id, int sem_num) {
    struct sembuf op;
    op.sem_num = sem_num;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(sem_id, &op, 1);
}

void sem_signal(int sem_id, int sem_num) {
    struct sembuf op;
    op.sem_num = sem_num;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(sem_id, &op, 1);
}

int create_semaphore() {
    int sem_id = semget(IPC_PRIVATE, 2, 0666);
    semctl(sem_id, SEM_ACCESS, SETVAL, 0);
    semctl(sem_id, SEM_MUTEX, SETVAL, 1);
    return sem_id;
}

int create_shared_memory() {
    int shm_id = shmget(SHM_KEY, SHM_MAX_SIZE, IPC_CREAT | 0666);
    return shm_id;
}

char* attach_shared_memory(int shm_id) {
    return shmat(shm_id, 0, 0);
}

int detach_shared_memory(char* shm_ptr) {
    return shmdt(shm_ptr);
}

void remove_shared_memory(int shm_id) {
    shmctl(shm_id, IPC_RMID, NULL);
}

void remove_semaphore(int sem_id) {
    semctl(sem_id, SEM_ACCESS, IPC_RMID, 0);
    semctl(sem_id, SEM_MUTEX, IPC_RMID, 0);
}

void writer_process(int sem_id, char* shm_ptr) {
    sem_wait(sem_id, SEM_MUTEX);
    sprintf(shm_ptr, "Hello from Writer process");
    sem_signal(sem_id, SEM_ACCESS);
    sem_signal(sem_id, SEM_MUTEX);
}

void reader_process(int sem_id, char* shm_ptr) {
    sem_wait(sem_id, SEM_ACCESS);
    printf("Message received: %s\n", shm_ptr);
    sem_signal(sem_id, SEM_MUTEX);
}

int main() {
    int sem_id = create_semaphore();
    int shm_id = create_shared_memory();
    char* shm_ptr = attach_shared_memory(shm_id);
    pid_t pid;
    int i;

    for (i = 0; i < NUM_OF_CHILDREN; i++) {
        pid = fork();

        if (pid == 0)
            break;
    }

    if (pid == 0) {
        // Child process
        if (i == 0) {
            // Writer process
            writer_process(sem_id, shm_ptr);
        } else {
            // Reader process
            reader_process(sem_id, shm_ptr);
        }
    } else {
        // Parent process
        wait(NULL);
        detach_shared_memory(shm_ptr);
        remove_shared_memory(shm_id);
        remove_semaphore(sem_id);
    }

    return 0;
}