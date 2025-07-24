//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
  long msg_type;
  char message[50];
};

int main() {
  printf("Welcome to the Interprocess Communication example program!\n");
  printf("In this program, we will see how two processes can communicate with each other.\n");
  printf("We will use Message Queues for this purpose.\n");
  printf("Let's get started!\n");

  // Create a key
  key_t key = ftok("msgq_example", 65); // The key can be any unique number
  
  // Create a message queue
  int msgqid = msgget(key, 0666 | IPC_CREAT);
  
  struct msg_buffer message;
  printf("Enter a message: ");
  fgets(message.message, 50, stdin);
  message.msg_type = 1;
  
  // Send the message
  msgsnd(msgqid, &message, sizeof(message), 0);
  printf("Message sent: %s", message.message);

  // Receive the message
  msgrcv(msgqid, &message, sizeof(message), 1, 0);
  printf("Message received: %s", message.message);

  // Delete the message queue
  printf("Deleting the message queue...\n");
  msgctl(msgqid, IPC_RMID, NULL);
  printf("Message queue deleted.\n");

  printf("Program completed successfully!\n");
  return 0;
}