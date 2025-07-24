//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* Message Queue structure */
struct msg_buffer {
    long msg_type;
    char message[100];
} message;

/* Define message keys */
#define KEY1 1000
#define KEY2 2000

/* Declare message queue variables */
int msg_id1, msg_id2;
pthread_t t1, t2;

/* Thread 1 function */
void* send_message(void* arg) {
    char* msg = (char*) arg;
    message.msg_type = 1;
    strncpy(message.message, msg, sizeof(message.message));
    if (msgsnd(msg_id1, &message, sizeof(message), 0) == -1) {
        perror("msgsnd failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread 1: Sent message '%s' to Thread 2\n", message.message);
    pthread_exit(NULL);
}

/* Thread 2 function */
void* receive_message(void* arg) {
    while (1) {
        if (msgrcv(msg_id2, &message, sizeof(message), 0, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread 2: Received message '%s' from Thread 1\n", message.message);
    }
    pthread_exit(NULL);
}

int main() {
    // Create message queues
    msg_id1 = msgget(KEY1, IPC_CREAT | 0666);
    msg_id2 = msgget(KEY2, IPC_CREAT | 0666);
    if (msg_id1 == -1 || msg_id2 == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // Create thread 1
    char* msg1 = "Hello from Thread 1";
    if (pthread_create(&t1, NULL, &send_message, (void*) msg1) != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    // Create thread 2
    if (pthread_create(&t2, NULL, &receive_message, NULL) != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to join
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    // Remove message queues
    msgctl(msg_id1, IPC_RMID, NULL);
    msgctl(msg_id2, IPC_RMID, NULL);

    return 0;
}