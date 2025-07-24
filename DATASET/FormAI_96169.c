//FormAI DATASET v1.0 Category: Interprocess communication ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGSZ 128

typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} msg_buf;

int main() {
    int msqid, msqid2;
    key_t key, key2;
    msg_buf buf, buf2;
    size_t buflen;
    pid_t pid;
    
    // Generate two unique keys for message queues
    if ((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    if ((key2 = ftok(".", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    // Create two message queues for communication
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }
    
    if ((msqid2 = msgget(key2, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }
    
    pid = fork();
    
    if (pid > 0) { // Parent process
        while(1) {
            printf("Enter a message to send to child: ");
            fgets(buf.mtext, MSGSZ, stdin);
            buf.mtype = 1; // Set message type to 1
            
            buflen = strlen(buf.mtext) + 1;
            
            // Send the message to the child process
            if (msgsnd(msqid, &buf, buflen, IPC_NOWAIT) == -1) {
                perror("msgsnd");
                exit(1);
            }
            
            // Wait for a response from the child process
            if (msgrcv(msqid2, &buf2, MSGSZ, 2, 0) == -1) {
                perror("msgrcv");
                exit(1);
            }
            
            printf("Received message from child: %s\n", buf2.mtext);
        }
    } else if (pid == 0) { // Child process
        while(1) {
            // Wait for a message from the parent process
            if (msgrcv(msqid, &buf, MSGSZ, 1, 0) == -1) {
                perror("msgrcv");
                exit(1);
            }
            
            printf("Received message from parent: %s\n", buf.mtext);
            
            // Process the message and create a response
            char response[MSGSZ];
            sprintf(response, "Processed message: %s", buf.mtext);
            
            buf2.mtype = 2; // Set message type to 2
            strcpy(buf2.mtext, response);
            buflen = strlen(buf2.mtext) + 1;
            
            // Send the response to the parent process
            if (msgsnd(msqid2, &buf2, buflen, IPC_NOWAIT) == -1) {
                perror("msgsnd");
                exit(1);
            }
        }
    } else { // Error creating child process
        perror("fork");
        exit(1);
    }
    
    // Remove the message queues
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    
    if (msgctl(msqid2, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    
    return 0;
}