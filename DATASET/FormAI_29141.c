//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define KEY 12345
#define GREEN_LIGHT 0
#define YELLOW_LIGHT 1
#define RED_LIGHT 2

struct message_queue
{
    long int type;
    int data;
};

typedef struct message_queue message;

int main()
{
    // Create message queue
    int msg_queue_id = msgget(KEY, IPC_CREAT | 0666);
    if (msg_queue_id == -1)
    {
        fprintf(stderr, "Failed to create message queue\n");
        exit(1);
    }

    // Initialize traffic light states
    int light_green = 1;
    int light_yellow = 0;
    int light_red = 0;

    // Start traffic light controller loop
    while(1)
    {
        // Change traffic light states
        if (light_green == 1)
        {
            printf("Green light is on\n");
            sleep(10);
            printf("Green light turned off\n");
            light_green = 0;
            light_yellow = 1;
            // Send message to pedestrian controller
            message msg = {1, GREEN_LIGHT};
            msgsnd(msg_queue_id, &msg, sizeof(msg), 0);
        }
        else if (light_yellow == 1)
        {
            printf("Yellow light is on\n");
            sleep(5);
            printf("Yellow light turned off\n");
            light_yellow = 0;
            light_red = 1;
            // Send message to pedestrian controller
            message msg = {1, YELLOW_LIGHT};
            msgsnd(msg_queue_id, &msg, sizeof(msg), 0);
        }
        else if (light_red == 1)
        {
            printf("Red light is on\n");
            sleep(10);
            printf("Red light turned off\n");
            light_red = 0;
            light_green = 1;
            // Send message to pedestrian controller
            message msg = {1, RED_LIGHT};
            msgsnd(msg_queue_id, &msg, sizeof(msg), 0);
        }
    }
    return 0;
}