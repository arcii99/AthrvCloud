//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_QUEUE_SIZE 100

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int priority;
    int size;
} Packet;

void init_queue(Queue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int is_empty(Queue *q) {
    return (q->size == 0);
}

int is_full(Queue *q) {
    return (q->size == MAX_QUEUE_SIZE);
}

void enqueue(Queue *q, int item) {
    if (is_full(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = item;
        q->size++;
    }
}

int dequeue(Queue *q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->queue[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->size--;
    }
    return item;
}

void generate_packet(Packet *p) {
    p->size = rand() % MAX_PACKET_SIZE;
    p->priority = (rand() % 10) + 1;
}

int main() {
    srand(time(NULL));
    Queue q1, q2, q3;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);
    Packet p;
    int total_packets = 0, dropped_packets = 0;
    double packet_drop_ratio;

    while (1) {
        generate_packet(&p);
        total_packets++;

        if (p.priority >= 8) {
            if (is_full(&q1)) {
                printf("Packet dropped\n");
                dropped_packets++;
            } else {
                printf("Packet added to queue 1\n");
                enqueue(&q1, p.size);
            }
        } else if (p.priority >= 4) {
            if (is_full(&q2)) {
                printf("Packet dropped\n");
                dropped_packets++;
            } else {
                printf("Packet added to queue 2\n");
                enqueue(&q2, p.size);
            }
        } else {
            if (is_full(&q3)) {
                printf("Packet dropped\n");
                dropped_packets++;
            } else {
                printf("Packet added to queue 3\n");
                enqueue(&q3, p.size);
            }
        }

        if (total_packets % 10 == 0) {
            printf("\nQueue 1 size: %d\n", q1.size);
            while (!is_empty(&q1)) {
                dequeue(&q1);
            }
            printf("Queue 2 size: %d\n", q2.size);
            while (!is_empty(&q2)) {
                dequeue(&q2);
            }
            printf("Queue 3 size: %d\n", q3.size);
            while (!is_empty(&q3)) {
                dequeue(&q3);
            }
            packet_drop_ratio = (double)dropped_packets / total_packets;
            printf("Packet drop ratio: %.2f%%\n", packet_drop_ratio * 100);
            printf("------------------------------\n");
        }

        sleep(1);
    }

    return 0;
}