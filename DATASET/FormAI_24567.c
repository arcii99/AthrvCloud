//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct message {
    long mtype;
    char mtext[MAX_TEXT];
};

int main(int argc, char *argv[])
{
    int running = 1;
    struct message msg;
    char buffer[MAX_TEXT];
    int msgid;
    
    key_t key = ftok("ipc_demo", 'M');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    
    while (running) {
        printf("Enter some text: ");
        fgets(buffer, MAX_TEXT, stdin);
        
        msg.mtype = 1;
        strncpy(msg.mtext, buffer, MAX_TEXT);
        
        if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        
        if (strncmp(buffer, "exit", 4) == 0) {
            running = 0;
        }
    }
    
    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        perror("msgctl");
        exit(1);
    }
    
    return 0;
}