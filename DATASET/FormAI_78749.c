//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

struct message {
    long type;
    char text[MAX];
};

int main() {
    int msgqid;
    pid_t pid;
    struct message msg;
    
    // Create message queue
    msgqid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    
    if(msgqid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }
    
    // Fork process
    pid = fork();
    
    if(pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if(pid == 0) {
        // Child process
        msg.type = 1;
        sprintf(msg.text, "Hello from child!");
        
        // Send message to parent
        if(msgsnd(msgqid, &msg, sizeof(msg.text), 0) == -1) {
            perror("msgsnd failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        if(msgrcv(msgqid, &msg, sizeof(msg.text), 1, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Received message from child: %s\n", msg.text);
        
        // Remove message queue
        if(msgctl(msgqid, IPC_RMID, NULL) == -1) {
            perror("msgctl failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}