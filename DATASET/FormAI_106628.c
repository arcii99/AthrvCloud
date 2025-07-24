//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h> 
#include <string.h> 
#include <pthread.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 

// thread function for sender 
void sender(void* arg) 
{ 
    key_t key; 
    int msgid; 
    int i=0;
    
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
    
    // msgget creates a message queue and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mesg_type = 1; 
    
    // loop to send message with incrementing i value
    while(i<10) {
        sprintf(message.mesg_text, "Sender message: %d", i); 
        
        // msgsnd to send message 
        msgsnd(msgid, &message, sizeof(message), 0); 

        printf("Sender sent: %s\n",message.mesg_text); 
        i++;
    }

} 

// thread function for receiver
void receiver(void* arg) 
{ 
    key_t key; 
    int msgid; 
    
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
    
    // msgget creates a message queue and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    
    // loop to receive message and print it
    while(1) {
        // msgrcv to receive message 
        msgrcv(msgid, &message, sizeof(message), 1, 0); 

        // display the message 
        printf("Receiver received: %s\n", message.mesg_text); 
    }
} 

int main() 
{ 
    pthread_t sender_thread, receiver_thread;
    
    // create sender and receiver threads
    pthread_create(&sender_thread, NULL, sender, NULL);
    pthread_create(&receiver_thread, NULL, receiver, NULL);

    // wait for threads to finish 
    pthread_join(sender_thread, NULL); 
    pthread_join(receiver_thread, NULL); 

    // remove message queue 
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666);
    msgctl(msgid, IPC_RMID, NULL); 
    
    return 0; 
}