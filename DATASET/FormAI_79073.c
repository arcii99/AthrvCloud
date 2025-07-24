//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct message_data {
   long message_type;
   char message_text[100];
};

int main() {
   key_t key;
   int message_id;
   struct message_data message;
   int pid;

   key = ftok("message_queue", 65); // Generate a unique key using ftok()

   // Create a message queue
   message_id = msgget(key, 0666 | IPC_CREAT);
   message.message_type = 1;

   // Get process ID
   pid = getpid();

   printf("Process %d sending a message...\n", pid);

   // Write message
   printf("Enter message: ");
   fgets(message.message_text, sizeof(message.message_text), stdin);

   // Send message
   msgsnd(message_id, &message, sizeof(message), 0);
   printf("Message sent: %s\n", message.message_text);

   // Wait for reply
   msgrcv(message_id, &message, sizeof(message), 2, 0);
   printf("Process %d received a reply: %s\n", pid, message.message_text);

   // Delete message queue
   msgctl(message_id, IPC_RMID, NULL);

   return 0;
}