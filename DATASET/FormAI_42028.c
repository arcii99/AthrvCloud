//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_SIZE 1024

/* Structure for the detective questions and suspect answers */
struct msg_buffer {
    long msg_type;
    char msg_text[MAX_SIZE];
} message;

int main()
{
    int msgid;
    char* detective_questions[] = {
        "Where were you on the night of the murder?",
        "Did you know the victim?",
        "Do you have an alibi?",
        "Where did you go after the incident?",
        "Why should I believe your story?"
    };

    /* Create a message queue */
    key_t key = ftok("sherlock_holmes", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    /* Fork a child process to simulate the suspect side */
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork\n");
        return 1;
    }

    /* Detective process */
    if (pid > 0) {
        printf("The detective is ready to start questioning...\n");

        /* Loop through the detective questions and send them to the suspect */
        for (int i = 0; i < 5; i++) {
            /* Construct the message */
            message.msg_type = 1;
            strcpy(message.msg_text, detective_questions[i]);

            /* Send the message to the suspect */
            msgsnd(msgid, &message, sizeof(message), 0);

            /* Receive the suspect's answer */
            msgrcv(msgid, &message, sizeof(message), 2, 0);

            printf("Suspect: %s\n", message.msg_text);
        }

        /* Remove the message queue */
        msgctl(msgid, IPC_RMID, NULL);

        printf("The questioning is over\n");
    } 
    
    /* Suspect process */
    else {
        printf("The suspect is waiting for questioning...\n");

        /* Loop through the detective questions and receive them */
        for (int i = 0; i < 5; i++) {
            /* Receive the message from the detective */
            msgrcv(msgid, &message, sizeof(message), 1, 0);

            printf("Detective: %s\n", message.msg_text);

            /* Get the suspect's answer */
            printf("Suspect: ");
            fgets(message.msg_text, MAX_SIZE, stdin);

            /* Construct the message and send it to the detective */
            message.msg_type = 2;
            msgsnd(msgid, &message, sizeof(message), 0);
        }
    }

    return 0;
}