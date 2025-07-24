//FormAI DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define MSG_SIZE 256

struct message_buffer {
  long message_type;
  char message[MSG_SIZE];
} msg;

int main()
{
  // Generate the message queue key
  key_t key = ftok("msg_queue_prog", 65);

  // Get the message queue ID
  int msgqid = msgget(key, 0666 | IPC_CREAT);

  // Check for error in obtaining the message queue ID
  if (msgqid == -1) {
    perror("msgget");
    exit(1);
  }

  // Get input from the user and send it to the message queue
  printf("Enter a message to send to the receiver: ");
  fgets(msg.message, MSG_SIZE, stdin);

  // Set the message type to 1
  msg.message_type = 1;

  // Send message to the message queue
  if (msgsnd(msgqid, &msg, sizeof(msg), 0) == -1) {
    perror("msgsnd");
    exit(1);
  }

  printf("Sent message to the receiver\n");

  // Wait for the receiver to receive the message
  sleep(2);

  // Receive message from the message queue
  if (msgrcv(msgqid, &msg, sizeof(msg), 2, 0) == -1) {
    perror("msgrcv");
    exit(1);
  }

  printf("Received message from the receiver: %s\n", msg.message);

  // Remove the message queue
  if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(1);
  }

  return 0;
}