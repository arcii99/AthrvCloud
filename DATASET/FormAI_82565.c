//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKETS 100
#define MAX_THREADS 10

struct Packet {
    int id;
    int size;
    int time_received;
    int time_processed;
    int is_intrusion;
};

typedef struct Packet Packet;

int main() {
    srand(time(NULL));

    Packet packets[MAX_PACKETS];
    int num_packets = rand() % MAX_PACKETS + 1;
    printf("Number of packets to process : %d\n", num_packets);

    for(int i=0;i<num_packets;i++) {
        Packet p;
        p.id = i+1;
        p.size = rand() % 1000 + 1;
        p.time_received = rand() % 60 + 1;
        p.time_processed = -1;
        p.is_intrusion = 0;
        packets[i] = p;
    }

    printf("Packet details - \n");
    for(int i=0;i<num_packets;i++) {
        printf("Packet %d : Size=%d, Time Received=%d\n", packets[i].id, packets[i].size, packets[i].time_received);
    }

    int num_threads = rand() % MAX_THREADS + 1;
    printf("Number of processing threads : %d\n", num_threads);

    int time_elapsed = 0;
    int packets_processed = 0;

    while(packets_processed < num_packets) {
        int packets_in_queue = 0;
        int total_packet_size = 0;

        for(int i=0;i<num_packets;i++) {
            if(packets[i].time_processed == -1) {
                packets_in_queue++;
                total_packet_size += packets[i].size;
                packets[i].time_processed = time_elapsed;
                if(rand() % 100 < 10) {
                    packets[i].is_intrusion = 1;
                }
                packets_processed++;
            }
        }

        float average_packet_size = (float)total_packet_size/packets_in_queue;

        printf("\nTime Elapsed : %ds | ", time_elapsed);
        for(int i=0;i<num_threads;i++) {
            printf("Thread %d : Processing %d packets | ", i+1, packets_in_queue/num_threads);
        }

        printf("\nAverage Packet Size : %.2f | ", average_packet_size);
        for(int i=0;i<num_threads;i++) {
            printf("Thread %d : Speed = %.2f pkt/s | ", i+1, (float)packets_in_queue/num_threads/packets_in_queue);
        }

        printf("\n");
        for(int i=0;i<num_packets;i++) {
            if(packets[i].time_processed == time_elapsed) {
                printf("Packet %d : Time Processed = %d, Intrusion Detected = %d\n", packets[i].id, packets[i].time_processed, packets[i].is_intrusion);
            }
        }

        time_elapsed++;
    }

    return 0;
}