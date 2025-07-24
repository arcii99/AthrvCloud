//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("surrealist", 'c');
    int shmid = shmget(key, sizeof(char), 0666|IPC_CREAT);
    char *msg = (char*) shmat(shmid, 0, 0);

    if (fork() == 0) {
        sleep(1);
        printf("I am the child process. I am a banana.\n");
        strncpy(msg, "banana", sizeof("banana"));

    } else {
        printf("I am the parent process. I am a giraffe.\n");
        printf("The child process is a %s.\n", msg);
        shmdt(msg);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}