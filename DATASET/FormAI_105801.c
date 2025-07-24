//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// We will use message queue for IPC
// This program will be the receiver
int main() {
  printf("Wowzers! I can't believe it, I just received a message from another program!\n");
  
  // Create message queue
  key_t key = ftok("unique_key_file", 'a');
  int msgid = msgget(key, 0666 | IPC_CREAT);
  
  // Define message structure
  typedef struct messageBuffer {
    long msgType;
    char msgText[100];
  } message;
  
  message receivedMessage;
  
  // Receive message
  msgrcv(msgid, &receivedMessage, sizeof(receivedMessage), 1, 0);
  
  printf("Received message: %s\n", receivedMessage.msgText);
  
  return 0;
}