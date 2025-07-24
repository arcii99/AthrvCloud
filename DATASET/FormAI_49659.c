//FormAI DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_LEN 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_LEN];
};

void sender(int queue_id){
    struct msg_buffer buffer;
    buffer.msg_type = 1;
    char message[MAX_MSG_LEN];
    while(1){
        printf("Enter message to send: ");
        fgets(message, MAX_MSG_LEN, stdin);
        strncpy(buffer.msg_text, message, MAX_MSG_LEN);
        msgsnd(queue_id, &buffer, sizeof(buffer.msg_text), 0);
        if(strncmp(message, "exit", 4) == 0){
            break;
        }
    }
}

void receiver(int queue_id){
    struct msg_buffer buffer;
    buffer.msg_type = 1;
    while(1){
        msgrcv(queue_id, &buffer, sizeof(buffer.msg_text), buffer.msg_type, 0);
        printf("Received: %s", buffer.msg_text);
        if(strncmp(buffer.msg_text, "exit", 4) == 0){
            break;
        }
    }
}

int main() {
    key_t key = ftok("progfile", 65);
    int queue_id = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        sender(queue_id);
    } else {
        receiver(queue_id);
    }

    msgctl(queue_id, IPC_RMID, NULL);
    
    return 0;
}