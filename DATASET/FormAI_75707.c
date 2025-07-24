//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct packet
{
    int id;
    int size;
    char data[50];
};

void *receive_packet(void *args);
void *intrusion_detection(void *args);

int main()
{
    pthread_t thread_receive, thread_detection;

    // create packet
    struct packet p;
    p.id = 123;
    p.size = 10;
    strncpy(p.data, "Hello", sizeof(p.data));

    // start receive thread
    pthread_create(&thread_receive, NULL, receive_packet, (void *)&p);

    // start intrusion detection thread
    pthread_create(&thread_detection, NULL, intrusion_detection, (void *)&p);

    // wait for threads to finish
    pthread_join(thread_receive, NULL);
    pthread_join(thread_detection, NULL);

    return 0;
}

void *receive_packet(void *args)
{
    struct packet *p = (struct packet *)args;

    // simulate receiving packet
    printf("Received packet %d with size %d and data %s\n", p->id, p->size, p->data);

    pthread_exit(NULL);
}

void *intrusion_detection(void *args)
{
    struct packet *p = (struct packet *)args;

    // simulate intrusion detection by checking if packet data contains "attack"
    if (strcasestr(p->data, "attack") != NULL)
    {
        printf("Intrusion detected in packet %d\n", p->id);
    }
    else
    {
        printf("No intrusion detected in packet %d\n", p->id);
    }

    pthread_exit(NULL);
}