//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
// Hey! Are you ready for something unusual? :)
// Let's create a program that sends messages between processes in a circular way!
// It might sound complex, but trust me, it's a fun and unique way of understanding interprocess communication.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_TXT_SIZE 50

typedef struct msgbuf {
    long mtype;
    char mtext[MSG_TXT_SIZE];
} message;

int main(int argc, char const *argv[]) {

    // Creating the message queue
    key_t key;
    int msgid;
    message msg;

    if ((key = ftok(".", 'a')) == -1) { // Generating a unique key
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) { // Creating the message queue
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("MESSAGE QUEUE CREATED WITH ID #%d\n", msgid);

    // Creating the child processes
    pid_t pid;
    int num_processes = 3;

    for (int i = 1; i <= num_processes; i++) {
        pid = fork(); // Creating a child process

        if (pid == -1) { // Handling fork errors
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            while (1) {
                if (msgrcv(msgid, &msg, sizeof(message) - sizeof(long), i, 0) == -1) { // Receiving a message from the previous process
                    perror("msgrcv");
                    exit(EXIT_FAILURE);
                }

                printf("PROCESS %d RECEIVED MESSAGE: \"%s\"\n", i, msg.mtext);

                // Updating the message and sending it to the next process
                msg.mtype = (i % num_processes) + 1;
                strcat(msg.mtext, " - Process ");
                strcat(msg.mtext, (char *) (i + '0'));
                printf("PROCESS %d SENT MESSAGE: \"%s\"\n", i, msg.mtext);

                if (msgsnd(msgid, &msg, sizeof(message) - sizeof(long), 0) == -1) { // Sending a message to the next process
                    perror("msgsnd");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    // Parent process
    // Sending the first message to kick off the circular communication
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from the parent!");
    printf("PARENT SENT MESSAGE: \"%s\"\n", msg.mtext);

    if (msgsnd(msgid, &msg, sizeof(message) - sizeof(long), 0) == -1) { // Sending the first message to the first process
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Cleaning up
    for (int i = 1; i <= num_processes + 1; i++) {
        wait(NULL);
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) { // Removing the message queue
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("MESSAGE QUEUE REMOVED WITH ID #%d\n", msgid);

    return 0;
}