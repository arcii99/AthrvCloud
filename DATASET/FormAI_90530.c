//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFSIZE 256

struct msgbuf {
    long mtype;
    char mtext[BUFSIZE];
};

int main() {
    int pid1, pid2, id1, id2;
    key_t key1, key2;
    struct msgbuf msg1, msg2;

    // create unique IPC keys
    key1 = ftok(".", 'A');
    key2 = ftok(".", 'B');

    printf("IPC key1: %d\n", key1);
    printf("IPC key2: %d\n", key2);

    // create message queue 1
    if ((id1 = msgget(key1, IPC_CREAT | 0666)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("Message queue 1 created with id: %d\n", id1);

    // create message queue 2
    if ((id2 = msgget(key2, IPC_CREAT | 0666)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("Message queue 2 created with id: %d\n", id2);

    // fork process 1
    if ((pid1 = fork()) == -1) {
        perror("fork error");
        exit(1);
    }

    if (pid1 == 0) {  // child process 1
        printf("Child process 1 started with pid: %d\n", getpid());

        // send message from queue 1 to queue 2
        msg1.mtype = 1;
        sprintf(msg1.mtext, "Hello from process 1");
        msgsnd(id2, &msg1, sizeof(msg1), IPC_NOWAIT);

        printf("Message sent from process 1 to process 2\n");

        // receive message from queue 2
        msgrcv(id1, &msg2, sizeof(msg2), 1, 0);

        printf("Message received from process 2 in process 1: %s\n", msg2.mtext);

        exit(0);
    }

    // fork process 2
    if ((pid2 = fork()) == -1) {
        perror("fork error");
        exit(1);
    }

    if (pid2 == 0) {  // child process 2
        printf("Child process 2 started with pid: %d\n", getpid());

        // receive message from queue 2
        msgrcv(id2, &msg2, sizeof(msg2), 1, 0);

        printf("Message received from process 1 in process 2: %s\n", msg2.mtext);

        // send message from queue 2 to queue 1
        msg1.mtype = 1;
        sprintf(msg1.mtext, "Hello from process 2");
        msgsnd(id1, &msg1, sizeof(msg1), IPC_NOWAIT);

        printf("Message sent from process 2 to process 1\n");

        exit(0);
    }

    // wait for child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // remove message queue 1
    if (msgctl(id1, IPC_RMID, NULL) == -1) {
        perror("msgctl error");
        exit(1);
    }

    printf("Message queue 1 removed\n");

    // remove message queue 2
    if (msgctl(id2, IPC_RMID, NULL) == -1) {
        perror("msgctl error");
        exit(1);
    }

    printf("Message queue 2 removed\n");

    return 0;
}