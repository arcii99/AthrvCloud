//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define QUEUE_SIZE 10
#define TRAFFIC_INTERVAL 2

typedef struct Packet {
    int id;
    int size;
} Packet;

typedef struct Queue {
    Packet packets[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

void enqueue(Queue* q, Packet packet) {
    if (q->count == QUEUE_SIZE) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->packets[q->rear] = packet;
    q->count++;
}

Packet dequeue(Queue* q) {
    if (q->count == 0) {
        printf("Error: Queue is empty\n");
        Packet empty_packet = { -1, 0 }; // default empty packet for error handling
        return empty_packet;
    }
    Packet packet = q->packets[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return packet;
}

void printQueue(Queue* q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % QUEUE_SIZE;
        printf("[%d:%d] ", q->packets[index].id, q->packets[index].size);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed random number generator

    Queue queue;
    initQueue(&queue);

    int total_packets = 0;
    int lost_packets = 0;

    printf("QoS monitor: Initializing...\n");

    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout); // flush output buffer
        sleep(1); // wait 1 second
    }

    printf("\nQoS monitor: Initialized\n\n");

    while (1) {
        int traffic = rand() % 100; // generate random number between 0 and 99
        if (traffic < 50) {
            int size = rand() % 100 + 1; // generate random packet size between 1 and 100
            Packet packet = { total_packets++, size };
            enqueue(&queue, packet);
            printf("QoS monitor: Packet [%d:%d] added to queue\n", packet.id, packet.size);
            printQueue(&queue);
        }
        if (queue.count > 0) {
            Packet packet = dequeue(&queue);
            printf("QoS monitor: Sending packet [%d:%d]\n", packet.id, packet.size);
            sleep(TRAFFIC_INTERVAL); // simulate network delay
            if (rand() % 100 < 20) {
                printf("QoS monitor: Packet [%d:%d] lost\n", packet.id, packet.size);
                lost_packets++;
            } else {
                printf("QoS monitor: Packet [%d:%d] received\n", packet.id, packet.size);
            }
        }
        printf("QoS monitor: Lost packets = %d\n", lost_packets);
        printf("\n");
        sleep(TRAFFIC_INTERVAL); // wait 2 seconds before checking again
    }

    return 0;
}