//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

// define message structure
struct msg_buf {
   long mtype;
   char mtext[100];
} message;

// main function
int main() {

   key_t key;
   int msgid;

   // create unique key
   key = ftok("progfile", 65);

   // create message queue
   msgid = msgget(key, 0666 | IPC_CREAT);

   // send message
   message.mtype = 1;
   printf("Enter message : ");
   fgets(message.mtext, 100, stdin);

   // send message
   msgsnd(msgid, &message, sizeof(message), 0);

   // receive message
   msgrcv(msgid, &message, sizeof(message), 2, 0);

   // display the message
   printf("Data Received : %s \n", message.mtext);

   // destroy message queue
   msgctl(msgid, IPC_RMID, NULL);

   return 0;
}