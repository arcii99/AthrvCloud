//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
// Woohoo, get ready for some Interprocess Communication magic in C!
// This program is going to blow your mind with its awesomeness!
// Hold on to your hats, folks!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSGSZ 128

// We need a struct to hold our message data
typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message_buf;

// This function sends a message over the queue
void send_message(int qid, char *msg_text, int msg_type) {
    message_buf msg;
    msg.mtype = msg_type;
    strncpy(msg.mtext, msg_text, MSGSZ);
    msgsnd(qid, &msg, strlen(msg.mtext)+1, 0);
    printf("Message sent: %s\n", msg.mtext);
}

// This function receives a message from the queue
void receive_message(int qid, int msg_type) {
    message_buf msg;
    msgrcv(qid, &msg, MSGSZ, msg_type, 0);
    printf("Message received: %s\n", msg.mtext);
}

int main() {

    // First, let's create our message queue
    key_t key = ftok("progfile", 65);
    int qid = msgget(key, 0666 | IPC_CREAT);
    printf("Message queue created with qid: %d\n", qid);
    
    // Now, let's send a message from this process to another process
    char* message_text_outgoing = "Hello, other process! How are you doing today?";
    int message_type_outgoing = 1;
    send_message(qid, message_text_outgoing, message_type_outgoing);

    // Let's sleep for a few seconds to give the other process a chance to receive our message
    sleep(2);

    // Now, let's receive a message from the other process
    int message_type_incoming = 2;
    printf("Waiting for message...\n");
    receive_message(qid, message_type_incoming);

    // Finally, let's clean up our message queue and say goodbye
    printf("Cleaning up message queue...\n");
    msgctl(qid, IPC_RMID, NULL);
    printf("Goodbye!\n");

    return 0;
}