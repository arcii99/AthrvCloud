//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

struct packet {
    int priority;
    char* data;
};

int main() {
    srand(time(0)); // Seed the random number generator

    // Initialize packets with random priority and data
    struct packet p1 = {rand() % 5, "Packet 1"};
    struct packet p2 = {rand() % 5, "Packet 2"};
    struct packet p3 = {rand() % 5, "Packet 3"};
    struct packet p4 = {rand() % 5, "Packet 4"};
    struct packet p5 = {rand() % 5, "Packet 5"};

    // Display initial packet information
    printf("Initial Packet Information:\n");
    printf("Packet 1 - Priority: %d, Data: %s\n", p1.priority, p1.data);
    printf("Packet 2 - Priority: %d, Data: %s\n", p2.priority, p2.data);
    printf("Packet 3 - Priority: %d, Data: %s\n", p3.priority, p3.data);
    printf("Packet 4 - Priority: %d, Data: %s\n", p4.priority, p4.data);
    printf("Packet 5 - Priority: %d, Data: %s\n\n", p5.priority, p5.data);

    // Simulate sending packets
    printf("Simulating packet send...\n\n");

    // Check QoS of each packet and adjust priority accordingly
    if (p1.priority == 0) {
        printf("Packet 1 dropped.\n");
        free(p1.data);
        p1.priority = -1;
    } else if (p1.priority == 1) {
        printf("Packet 1 delayed.\n");
        p1.priority = 2;
    } else if (p1.priority == 2) {
        printf("Packet 1 sent with normal priority.\n");
    } else if (p1.priority == 3) {
        printf("Packet 1 sent with high priority.\n");
    } else if (p1.priority == 4) {
        printf("Packet 1 sent with expedited priority.\n");
    }

    if (p2.priority == 0) {
        printf("Packet 2 dropped.\n");
        free(p2.data);
        p2.priority = -1;
    } else if (p2.priority == 1) {
        printf("Packet 2 delayed.\n");
        p2.priority = 2;
    } else if (p2.priority == 2) {
        printf("Packet 2 sent with normal priority.\n");
    } else if (p2.priority == 3) {
        printf("Packet 2 sent with high priority.\n");
    } else if (p2.priority == 4) {
        printf("Packet 2 sent with expedited priority.\n");
    }

    if (p3.priority == 0) {
        printf("Packet 3 dropped.\n");
        free(p3.data);
        p3.priority = -1;
    } else if (p3.priority == 1) {
        printf("Packet 3 delayed.\n");
        p3.priority = 2;
    } else if (p3.priority == 2) {
        printf("Packet 3 sent with normal priority.\n");
    } else if (p3.priority == 3) {
        printf("Packet 3 sent with high priority.\n");
    } else if (p3.priority == 4) {
        printf("Packet 3 sent with expedited priority.\n");
    }

    if (p4.priority == 0) {
        printf("Packet 4 dropped.\n");
        free(p4.data);
        p4.priority = -1;
    } else if (p4.priority == 1) {
        printf("Packet 4 delayed.\n");
        p4.priority = 2;
    } else if (p4.priority == 2) {
        printf("Packet 4 sent with normal priority.\n");
    } else if (p4.priority == 3) {
        printf("Packet 4 sent with high priority.\n");
    } else if (p4.priority == 4) {
        printf("Packet 4 sent with expedited priority.\n");
    }

    if (p5.priority == 0) {
        printf("Packet 5 dropped.\n");
        free(p5.data);
        p5.priority = -1;
    } else if (p5.priority == 1) {
        printf("Packet 5 delayed.\n");
        p5.priority = 2;
    } else if (p5.priority == 2) {
        printf("Packet 5 sent with normal priority.\n");
    } else if (p5.priority == 3) {
        printf("Packet 5 sent with high priority.\n");
    } else if (p5.priority == 4) {
        printf("Packet 5 sent with expedited priority.\n");
    }

    // Display final packet information
    printf("\nFinal Packet Information:\n");
    printf("Packet 1 - Priority: %d, Data: %s\n", p1.priority, p1.data);
    printf("Packet 2 - Priority: %d, Data: %s\n", p2.priority, p2.data);
    printf("Packet 3 - Priority: %d, Data: %s\n", p3.priority, p3.data);
    printf("Packet 4 - Priority: %d, Data: %s\n", p4.priority, p4.data);
    printf("Packet 5 - Priority: %d, Data: %s\n", p5.priority, p5.data);

    return 0;
}