//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st {
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main() {
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    char buffer[BUFSIZ];

    // generate a key to access the message queue
    key_t key = ftok("prog", 'A');
    
    // create a message queue and get the id
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "Error creating message queue\n");
        exit(EXIT_FAILURE);
    }

    // fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // child process
        while(running) {
            // receive message from the queue
            if (msgrcv(msgid, (void *)&some_data, MAX_TEXT, 1, 0) == -1) {
                fprintf(stderr, "Message receive failed\n");
                exit(EXIT_FAILURE);
            }
            printf("\nMessage received from the parent: %s", some_data.some_text);
            fflush(stdout);

            // check if message is to stop the communication
            if (strcmp(some_data.some_text, "end") == 0) {
                running = 0;
                break;
            }

            // reply to the message
            sprintf(buffer, "Hello parent, this is child %d", getpid());
            strcpy(some_data.some_text, buffer);
            some_data.my_msg_type = 2;
            if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) {
                fprintf(stderr, "Message send failed\n");
                exit(EXIT_FAILURE);
            }
            printf("\nMessage sent to the parent: %s", some_data.some_text);
            fflush(stdout);
        }

        exit(EXIT_SUCCESS);
    } 

    else {
        // parent process
        while(running) {
            printf("\nEnter message to send to child, or 'end' to exit: ");
            fgets(buffer, BUFSIZ, stdin);
            
            // send message to the queue
            strcpy(some_data.some_text, buffer);
            some_data.my_msg_type = 1;
            if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) {
                fprintf(stderr, "Message send failed\n");
                exit(EXIT_FAILURE);
            }
            printf("Message sent to child: %s", some_data.some_text);

            // check if message is to stop the communication
            if (strcmp(buffer, "end\n") == 0) {
                running = 0;
                break;
            }

            // receive reply from the queue
            if (msgrcv(msgid, (void *)&some_data, MAX_TEXT, 2, 0) == -1) {
                fprintf(stderr, "Message receive failed\n");
                exit(EXIT_FAILURE);
            }
            printf("\nMessage received from the child: %s", some_data.some_text);
            fflush(stdout);
        }

        // wait for the child process to terminate
        waitpid(pid, NULL, 0);

        // remove message queue
        if (msgctl(msgid, IPC_RMID, 0) == -1) {
            fprintf(stderr, "Message queue removal failed\n");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    return 0;
}