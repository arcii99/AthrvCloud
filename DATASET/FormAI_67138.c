//FormAI DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 8888

typedef struct {
    long type;
    char text[50];
} message;

int msgid;
message buf;

void error_exit(const char* error) {
    perror(error);
    exit(EXIT_FAILURE);
}

void receiver() {
    while(1) {
        if(msgrcv(msgid, &buf, sizeof(buf.text), 1, 0) == -1) {
            error_exit("Error receiving message");
        }
        printf("Received message: %s\n", buf.text);
        if(strcmp(buf.text, "exit") == 0) {
            break;
        }
    }
}

void sender() {
    char input[50];
    while(1) {
        printf("Enter a message to send: ");
        fgets(input, 50, stdin);
        if(strcmp(input, "exit\n") == 0) {
            strcpy(buf.text, "exit");
            buf.type = 1;
            if(msgsnd(msgid, &buf, strlen(buf.text), 0) == -1) {
                error_exit("Error sending message");
            }
            break;
        }
        strcpy(buf.text, input);
        buf.type = 1;
        if(msgsnd(msgid, &buf, strlen(buf.text), 0) == -1) {
            error_exit("Error sending message");
        }
    }
}

int main() {
    // create message queue
    msgid = msgget(MSGKEY, 0666 | IPC_CREAT);
    if(msgid == -1) {
        error_exit("Error creating message queue");
    }
    
    // fork to create child process
    pid_t pid = fork();
    if(pid == -1) {
        error_exit("Error forking process");
    }
    else if(pid == 0) {
        receiver();
    }
    else {
        sender();
    }
    
    // delete message queue
    if(msgctl(msgid, IPC_RMID, NULL) == -1) {
        error_exit("Error deleting message queue");
    }
    
    return 0;
}