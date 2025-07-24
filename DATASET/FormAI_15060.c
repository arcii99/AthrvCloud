//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define SERVER_QUEUE_NAME "/test_server"
#define CLIENT_QUEUE_NAME "/test_client"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

static volatile sig_atomic_t sig_int = 0;

void sigint_handler(int sig_no) {
    sig_int = 1;
}

int main(void) {
    mqd_t qd_server, qd_client;
    char client_queue_name[64];
    char msg_buffer[MSG_BUFFER_SIZE];
    struct mq_attr attr;
    struct sigaction action;
    ssize_t bytes_read;

    umask(0);

    // Register the SIGINT handler
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = sigint_handler;
    sigaction(SIGINT, &action, NULL);

    // Set up the queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    // Create the server queue
    if ((qd_server = mq_open(SERVER_QUEUE_NAME, O_RDWR | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror("Error: mq_open server");
        exit(1);
    }

    while (!sig_int) {
        // Block until a client sends a message
        if ((bytes_read = mq_receive(qd_server, msg_buffer, MSG_BUFFER_SIZE, NULL)) == -1) {
            perror("Error: mq_receive");
            continue;
        }

        // Open the client queue
        sprintf(client_queue_name, "%s_%d", CLIENT_QUEUE_NAME, getpid());
        if ((qd_client = mq_open(client_queue_name, O_RDWR, QUEUE_PERMISSIONS, &attr)) == -1) {
            perror("Error: mq_open client");
            continue;
        }

        // Send a response to the client queue
        if (mq_send(qd_client, msg_buffer, bytes_read, 0) == -1) {
            perror("Error: mq_send");
            mq_close(qd_client);
            mq_unlink(client_queue_name);
            continue;
        }

        mq_close(qd_client);

        // Remove the client queue
        mq_unlink(client_queue_name);
    }

    // Close and unlink the server queue
    mq_close(qd_server);
    mq_unlink(SERVER_QUEUE_NAME);

    return 0;
}