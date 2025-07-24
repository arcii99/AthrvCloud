//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_PACKET_SIZE 2048
#define MAX_PACKETS 1000

void *packet_generator(void *arg);
void *packet_consumer(void *arg);

typedef struct {
    int id;
    int size;
    int priority;
    time_t arrival;
} packet;

int main()
{
    pthread_t threads[MAX_THREADS];
    int rc;
    long t;
    
    time_t start = time(NULL);

    printf("Creating producer-consumer threads...\n");
    for (t = 0; t < MAX_THREADS; t++) {
        if (t % 2 == 0) {
            rc = pthread_create(&threads[t], NULL, packet_generator, (void *) t);
        } else {
            rc = pthread_create(&threads[t], NULL, packet_consumer, (void *) t);
        }
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    printf("Threads created successfully\n");

    for (t = 0; t < MAX_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    time_t end = time(NULL);
    double elapsed = difftime(end, start);
    printf("Total runtime: %.2fs\n", elapsed);

    return 0;
}

// Generate packets and add them to queue
void *packet_generator(void *arg)
{
    long id = (long) arg;
    packet packets[MAX_PACKETS];
    int i, j;

    for (i = 0; i < MAX_PACKETS; i++) {
        packet p;
        p.id = i;
        p.size = rand() % MAX_PACKET_SIZE + 1;
        p.priority = rand() % 3 + 1;
        p.arrival = time(NULL);
        packets[i] = p;
    }

    for (j = 0; j < MAX_PACKETS; j++) {
        usleep(rand() % 1000); // simulate packet processing time
        // Add packet to queue
        printf("Thread %ld generated packet %d of size %d and priority %d at %d\n",
               id, packets[j].id, packets[j].size, packets[j].priority, packets[j].arrival);
    }

    pthread_exit(NULL);
}

// Consume packets from queue and monitor quality of service (QoS)
void *packet_consumer(void *arg)
{
    long id = (long) arg;
    packet packets[MAX_PACKETS];
    int i, j;
    int total_packets = 0;
    int total_bytes = 0;
    int high_priority_count = 0;
    time_t last_packet_arrival = time(NULL);

    for (i = 0; i < MAX_PACKETS * MAX_THREADS / 2; i++) {
        usleep(rand() % 1000); // simulate packet processing time
        // Consume packet from queue
        packet p;
        p.id = i;
        p.size = rand() % MAX_PACKET_SIZE + 1;
        p.priority = rand() % 3 + 1;
        p.arrival = time(NULL);
        packets[i] = p;

        total_packets++;
        total_bytes += p.size;

        if (p.priority == 3) {
            high_priority_count++;
        }

        double elapsed_since_last_packet = difftime(p.arrival, last_packet_arrival);
        if (elapsed_since_last_packet > 1) {
            printf("Thread %ld: %.2f packets/s, %.2f bytes/s, %.2f%% high priority packets\n",
                   id, total_packets / elapsed_since_last_packet,
                   total_bytes / elapsed_since_last_packet,
                   (double) high_priority_count / total_packets * 100);
            last_packet_arrival = p.arrival;
        }
    }

    pthread_exit(NULL);
}