//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 64

typedef struct message {
    long int msg_type;
    char msg[MSG_SIZE];
} message_t;

void recursive_send(int msq_id, long int type) {
    message_t msg;
    printf("Enter message: ");
    fgets(msg.msg, MSG_SIZE, stdin);
    msg.msg_type = type;
    int send_ret = msgsnd(msq_id, &msg, MSG_SIZE, 0);
    if (send_ret >= 0) {
        printf("Message sent to receiver with message type %ld\n", type);
        recursive_send(msq_id, type+1); //recursive call
    } else {
        perror("Error in sending message.");
    }
}

void receive(int msq_id) {
    message_t msg;
    int receive_ret = msgrcv(msq_id, &msg, MSG_SIZE, 0, 0);
    if (receive_ret >= 0) {
        printf("Received message: %s\n", msg.msg);
        receive(msq_id); //recursive call
    } else {
        perror("Error in receiving message.");
    }
}

int main() {
    key_t key = ftok(".", 'a');
    int msq_id = msgget(key, 0666 | IPC_CREAT);
    if (msq_id < 0) {
        perror("Error in creating message queue.");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Error in forking process.");
        exit(1);
    }

    if (pid == 0) {
        //child process
        printf("Receiver started.\n");
        receive(msq_id);
    } else {
        //parent process
        printf("Sender started.\n");
        recursive_send(msq_id, 1); //start recursive sending
    }

    msgctl(msq_id, IPC_RMID, NULL); //remove message queue
    return 0;
}