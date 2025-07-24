//FormAI DATASET v1.0 Category: Interprocess communication ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

typedef struct {
    char message[100];
    int sender_pid;
} Message;

int main() {
    Message* shared_memory_ptr;
    int shared_memory_id;
    int sender_pid;
    int receiver_pid;
    sem_t* semaphore_ptr;

    // Creating shared memory
    shared_memory_id = shmget((key_t)1234, sizeof(Message), IPC_CREAT | 0666);
    if (shared_memory_id < 0) {
        printf("Error in creating shared memory\n");
        exit(1);
    }

    // Attaching to shared memory
    shared_memory_ptr = (Message*) shmat(shared_memory_id, NULL, 0);
    if (shared_memory_ptr == (void*)-1) {
        printf("Error in attaching shared memory\n");
        exit(1);
    }

    // Creating semaphore
    semaphore_ptr = sem_open("my_sem", O_CREAT, S_IRUSR | S_IWUSR, 1);
    if (semaphore_ptr == SEM_FAILED) {
        printf("Error in creating semaphore\n");
        exit(1);
    }

    // Forking process
    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sender_pid = getpid();
        receiver_pid = getppid();

        sleep(2);
        sem_wait(semaphore_ptr);

        // Writing message to shared memory
        strcpy(shared_memory_ptr->message, "Hello parent, this is your child.");
        shared_memory_ptr->sender_pid = sender_pid;

        sem_post(semaphore_ptr);

        printf("Child process %d has sent message.\n", sender_pid);
    } else {
        // Parent process
        sender_pid = getpid();
        receiver_pid = pid;

        sem_wait(semaphore_ptr);

        // Reading message from shared memory
        Message received_message;
        memcpy(&received_message, shared_memory_ptr, sizeof(Message));

        sem_post(semaphore_ptr);

        printf("Parent process %d has received message: \"%s\" from child process %d.\n", receiver_pid, received_message.message, received_message.sender_pid);

        // Detaching from shared memory
        if (shmdt(shared_memory_ptr) == -1) {
            printf("Error in detaching shared memory");
            exit(1);
        }

        // Removing shared memory
        if (shmctl(shared_memory_id, IPC_RMID, 0) == -1) {
            printf("Error in removing shared memory");
            exit(1);
        }

        // Closing semaphore
        if (sem_close(semaphore_ptr) == -1) {
            printf("Error in closing semaphore");
            exit(1);
        }

        // Unlinking semaphore
        if (sem_unlink("my_sem") == -1) {
            printf("Error in unlinking semaphore");
            exit(1);
        }
    }

    return 0;
}