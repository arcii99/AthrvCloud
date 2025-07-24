//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

#define MAX_SIZE 128

struct message {
    long int message_type;
    char buffer[MAX_SIZE];
};

int main()
{
    pid_t pid;
    int key;
    int message_id;
    struct message message;
    char* quit_command = "/quit";

    pid = fork();

    if (pid == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // child process
        key = ftok("child_process", 65);
        message_id = msgget(key, 0666 | IPC_CREAT);
        while (1) {
            msgrcv(message_id, &message, sizeof(message), 1, 0);
            printf("Child process received message: %s\n", message.buffer);
            if (strcmp(message.buffer, quit_command)==0) {
                printf("Child process will quit now...\n");
                break;
            }
        }
        msgctl(message_id, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);

    } else {
        // parent process
        key = ftok("child_process", 65);
        message_id = msgget(key, 0666 | IPC_CREAT);
        while (1) {
            printf("Enter message to send or type '/quit' to exit: ");
            fgets(message.buffer, MAX_SIZE, stdin);
            message.message_type = 1;
            msgsnd(message_id, &message, sizeof(message), 0);
            if (strcmp(message.buffer, quit_command)==0) {
                printf("Parent process will quit now...\n");
                break;
            }
        }
        wait(NULL);
        msgctl(message_id, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);
    }
}