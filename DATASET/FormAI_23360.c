//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/* 
 * Interprocess Communication Example Program 
 * Claude Shannon Style: "The number of possible communication pathways between two processes is a function of their complements and not their similarities."
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define MSG_TYPE_1 1
#define MSG_TYPE_2 2

// function to handle errors
void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// structure for message queue
struct message {
    long mtype;
    char mtext[MAX_MSG_LEN];
};

int main() {
    pid_t pid; // process id
    key_t key; // message queue key
    int msqid; // message queue id
    struct message msg; // message buffer
    
    // create message queue key
    if ((key = ftok(".", 'A')) == -1)
        handle_error("ftok");
    
    // create message queue
    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1)
        handle_error("msgget");
    
    // fork a new process
    if ((pid = fork()) == -1)
        handle_error("fork");
    
    if (pid == 0) { // child process
        // receive message from parent
        if (msgrcv(msqid, &msg, MAX_MSG_LEN, MSG_TYPE_1, 0) == -1)
            handle_error("msgrcv-1");
        
        printf("Child received message: %s\n", msg.mtext);
        
        // send message to parent
        strcpy(msg.mtext, "Hello from child");
        msg.mtype = MSG_TYPE_2;
        if (msgsnd(msqid, &msg, strlen(msg.mtext)+1, 0) == -1)
            handle_error("msgsnd-1");
    } else { // parent process
        // send message to child
        strcpy(msg.mtext, "Hello from parent");
        msg.mtype = MSG_TYPE_1;
        if (msgsnd(msqid, &msg, strlen(msg.mtext)+1, 0) == -1)
            handle_error("msgsnd-2");
        
        // receive message from child
        if (msgrcv(msqid, &msg, MAX_MSG_LEN, MSG_TYPE_2, 0) == -1)
            handle_error("msgrcv-2");
        
        printf("Parent received message: %s\n", msg.mtext);
        
        // remove message queue
        if (msgctl(msqid, IPC_RMID, NULL) == -1)
            handle_error("msgctl");
    }

    return 0;
}