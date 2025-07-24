//FormAI DATASET v1.0 Category: Interprocess communication ; Style: standalone
//Header files required for Interprocess communication
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Message structure defines the message in Interprocess communication
struct msgbuf{
    long mtype;
    char mtext[200];
};

//Main function for Interprocess communication
int main()
{
    key_t key;
    int msgid;
    struct msgbuf mesg;
    int len;
    
    //Creating a unique key for message queue
    if ((key = ftok("msgq.txt", 'B')) == -1)
    {
        perror("ftok");
        exit(1);
    }
    
    //Creating a new message queue with the created key
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }
    
    //Adding a message to the message queue
    printf("\nEnter text message: ");
    fgets(mesg.mtext, sizeof(mesg.mtext), stdin);
    mesg.mtype = 1;
    len = strlen(mesg.mtext);
    if (msgsnd(msgid, &mesg, len+1, 0) == -1)
        perror("msgsnd");
    else
        printf("\nMessage sent to the queue\n");
        
    //Receiving a message from the message queue
    printf("\nWaiting for a message...\n");
    if (msgrcv(msgid, &mesg, sizeof(mesg.mtext), 0, 0) == -1)
    {
        perror("msgrcv");
        exit(1);
    }
    printf("\nMessage received from the queue: %s\n", mesg.mtext);

    //Deleting the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}