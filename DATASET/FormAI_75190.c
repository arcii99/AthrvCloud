//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MSG_SIZE 256

/* Message structure to send between processes */
struct message {
    long type;
    char text[MSG_SIZE];
};

/* Function to run in each thread */
void *thread_function(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d starting\n", id);
    
    /* Connect to message queue */
    key_t key = ftok("msgq.txt", 'A');
    int msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    
    /* Send message to all other threads */
    char buffer[MSG_SIZE];
    struct message msg;
    sprintf(buffer, "Thread %d says hello!", id);
    msg.type = 1;
    strcpy(msg.text, buffer);
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i != id) {
            if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
                perror("msgsnd");
            }
        }
    }
    
    /* Receive messages from other threads */
    int received = 0;
    while (received < NUM_THREADS - 1) {
        if (msgrcv(msgid, &msg, sizeof(msg.text), id + 1, 0) == -1) {
            perror("msgrcv");
        } else {
            printf("Thread %d received message: %s\n", id, msg.text);
            received++;
        }
    }
    
    printf("Thread %d exiting\n", id);
    pthread_exit(NULL);
}

/* Main function */
int main() {
    /* Create message queue */
    key_t key = ftok("msgq.txt", 'A');
    int msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    
    /* Create threads */
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &ids[i]);
    }
    
    /* Wait for threads to finish */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    /* Delete message queue */
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}