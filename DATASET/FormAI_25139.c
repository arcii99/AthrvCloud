//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long mtype; // message type
    char text[100]; // message text
};

int main() {
    int msgid; // message queue id
    key_t key; // message queue key
    struct message msg; // message object

    // generate unique key for message queue
    key = ftok("prog", 'a');

    // create message queue with read/write access for user
    if ((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message queue created with id %d and key %d\n", msgid, key);

    // fork process to create child process
    pid_t pid = fork();

    // child process
    if (pid == 0) {
        printf("Child process\n");

        // receive message from parent
        msgrcv(msgid, &msg, sizeof(msg), 1, 0);

        printf("Message received from parent:\n%s\n", msg.text);

        // send message back to parent
        sprintf(msg.text, "Hello parent, I am your child with pid %d", getpid());
        msg.mtype = 2; // message type 2 for child to parent
        msgsnd(msgid, &msg, sizeof(msg), 0);
    }
    // parent process
    else if (pid > 0) {
        printf("Parent process with child pid %d\n", pid);

        // send message to child
        sprintf(msg.text, "Hello child, I am your parent with pid %d", getpid());
        msg.mtype = 1; // message type 1 for parent to child
        msgsnd(msgid, &msg, sizeof(msg), 0);

        // receive message from child
        msgrcv(msgid, &msg, sizeof(msg), 2, 0);

        printf("Message received from child:\n%s\n", msg.text);
    }
    // failed to fork process
    else {
        perror("fork");
        exit(1);
    }

    // delete message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}