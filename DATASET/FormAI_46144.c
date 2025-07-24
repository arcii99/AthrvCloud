//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 1024
#define SERVER_QUEUE_NAME "/cyberserver"

typedef struct msg_buffer {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} msg_buffer_t;

int main() {
    int server_queue_id, client_queue_id;
    key_t server_key, client_key;
    pid_t pid;
    char client_queue_name[20];
    msg_buffer_t msg_buffer;

    // Create server queue
    server_key = ftok(".", 's');
    server_queue_id = msgget(server_key, IPC_CREAT|0666);

    if (server_queue_id == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    printf("CyberServer is up!\n");

    while (1) {
        // Receive client's message
        if (msgrcv(server_queue_id, &msg_buffer, sizeof(msg_buffer_t), 0, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        }

        // Fork a new process for each client
        pid = fork();

        if (pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // We are in the child process
            client_key = ftok(".", msg_buffer.mtype);
            client_queue_id = msgget(client_key, 0);

            if (client_queue_id == -1) {
                perror("msgget failed");
                exit(EXIT_FAILURE);
            }

            sprintf(client_queue_name, "/cyberclient%d", getpid());

            if (mkfifo(client_queue_name, 0666) == -1) {
                perror("mkfifo failed");
                exit(EXIT_FAILURE);
            }

            int client_file_fd = open(client_queue_name, O_RDWR);
            char client_message[MAX_MSG_SIZE];
            memset(client_message, 0, MAX_MSG_SIZE);

            // Read client's message from named pipe file
            if (read(client_file_fd, client_message, MAX_MSG_SIZE) == -1) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }

            // Print received message
            printf("Received from client %ld: %s\n", msg_buffer.mtype, client_message);

            msg_buffer.mtype = getpid();

            // Send message to client
            if (msgsnd(client_queue_id, &msg_buffer, sizeof(msg_buffer_t), 0) == -1) {
                perror("msgsnd failed");
                exit(EXIT_FAILURE);
            }

            // Delete named pipe file
            unlink(client_queue_name);
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}