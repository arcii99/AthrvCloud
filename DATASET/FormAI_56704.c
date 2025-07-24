//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 50

typedef struct msgbuf {
  long mtype;
  char mtext[MSG_SIZE];
} message;

int main() {

  int msqid;
  key_t key;
  message msg;

  if((key = ftok("progfile.txt", 'A')) == -1) {
    perror("ftok");
    exit(1);
  }

  if((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }

  printf("Enter a message: ");
  fgets(msg.mtext, MSG_SIZE, stdin);

  msg.mtype = 1;

  if(msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
    perror("msgsnd");
  }

  printf("Message Sent: %s", msg.mtext);

  memset(msg.mtext, 0, MSG_SIZE);

  if(msgrcv(msqid, &msg, sizeof(msg.mtext), 0, 0) == -1) {
    perror("msgrcv");
    exit(1);
  }

  printf("Message Received: %s", msg.mtext);

  if(msgctl(msqid, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(1);
  }

  return 0;
}