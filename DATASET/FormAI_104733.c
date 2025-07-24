//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct message {
    long msg_type;
    char msg[MSG_SIZE];
};

void sender(int q_id) {
    struct message msg_buf;
    char data[MSG_SIZE] = "Hello receiver!";
    msg_buf.msg_type = 1;
    strcpy(msg_buf.msg, data);
    msgsnd(q_id, &msg_buf, strlen(msg_buf.msg) + 1, 0);
    printf("Sender: Message Sent -> %s\n", msg_buf.msg);
}

void receiver(int q_id) {
    struct message msg_buf;
    msgrcv(q_id, &msg_buf, MSG_SIZE, 1, 0);
    printf("Receiver: Message Received -> %s\n", msg_buf.msg);
}

int main() {
    key_t key = ftok("msgq_sender_receiver", 65); // creating unique key
    int q_id = msgget(key, 0666 | IPC_CREAT); // creating message queue
    if(q_id == -1) {
        perror("Error Creating Message Queue");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // creating child process
    if(pid == -1) {
        perror("Error Creating Child Process");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) { // this is child process
        receiver(q_id);
    }
    else { // this is parent process
        sender(q_id);
    }

    int status;
    wait(&status); // waiting for child to exit
    printf("Child Process Exited with status %d\n", WEXITSTATUS(status));
    msgctl(q_id, IPC_RMID, NULL); // destroying message queue
    return 0;
}