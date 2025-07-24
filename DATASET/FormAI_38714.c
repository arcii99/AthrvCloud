//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

// structure for message queue
struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

// function for Thread 1
void *thread1_func(void *args) {
    int msgq_id;
    key_t key;
    struct message msg;

    // create a key
    key = ftok("msgq.txt", 'A');

    // create a message queue
    msgq_id = msgget(key, IPC_CREAT | 0666);

    if (msgq_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // send a message to Thread 2
    msg.msg_type = 1;
    sprintf(msg.msg_text, "Hello Thread 2");
    if (msgsnd(msgq_id, &msg, sizeof(msg), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Thread 1 sent a message to Thread 2\n");

    pthread_exit(NULL);
}

// function for Thread 2
void *thread2_func(void *args) {
    int msgq_id;
    key_t key;
    struct message msg;

    // create a key
    key = ftok("msgq.txt", 'A');

    // connect to the message queue
    msgq_id = msgget(key, 0666);

    if (msgq_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // receive the message from Thread 1
    if (msgrcv(msgq_id, &msg, sizeof(msg), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Thread 2 received a message from Thread 1: %s\n", msg.msg_text);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // create Thread 1
    if (pthread_create(&thread1, NULL, thread1_func, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // create Thread 2
    if (pthread_create(&thread2, NULL, thread2_func, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // wait for Thread 1 to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    // wait for Thread 2 to finish
    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Main thread exiting\n");

    return 0;
}