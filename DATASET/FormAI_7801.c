//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define MAX_MSG_LEN 1024

typedef struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_LEN];
} msgbuf;

void handle_sigint(int sig)
{
    printf("Exiting...\n");
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, handle_sigint);
    srand(time(NULL));

    key_t key = ftok("cyberpunk_ipc", 1);
    int msgid = msgget(key, 0644 | IPC_CREAT);

    if(msgid == -1)
    {
        perror("msgget");
        exit(1);
    }

    printf("Welcome to the Cyberpunk chatroom!\n");

    char username[MAX_MSG_LEN];
    printf("Enter your username: ");
    fgets(username, MAX_MSG_LEN, stdin);
    strtok(username, "\n");

    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) // child process reads messages
    {
        while(1)
        {
            msgbuf msg;

            if(msgrcv(msgid, &msg, sizeof(msgbuf) - sizeof(long), 1, MSG_NOERROR) == -1)
            {
                perror("msgrcv");
                exit(1);
            }

            printf("%s\n", msg.mtext);
        }
    }
    else // parent process sends messages
    {
        while(1)
        {
            char message[MAX_MSG_LEN];
            printf("> ");
            fgets(message, MAX_MSG_LEN, stdin);
            strtok(message, "\n");

            msgbuf msg;
            msg.mtype = 1;
            sprintf(msg.mtext, "%s: %s", username, message);

            if(msgsnd(msgid, &msg, sizeof(msgbuf) - sizeof(long), 0) == -1)
            {
                perror("msgsnd");
                exit(1);
            }

            sleep(rand() % 3); // add some latency to simulate network traffic
        }
    }

    return 0;
}