//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct {
    pcap_t* handle;
    volatile int* stop;
} monitor_context_t;

void* packet_monitor(void* context) {
    monitor_context_t* monitor_context = (monitor_context_t*) context;
    pcap_t* handle = monitor_context->handle;
    volatile int* stop = monitor_context->stop;

    struct pcap_pkthdr header;
    const unsigned char* packet;
    while (*stop == 0) {
        packet = pcap_next(handle, &header);
        if (packet != NULL)
            printf("Packet captured.\n");
    }

    pcap_close(handle);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    char* device = "eth0";
    int promiscuous = 1;
    int timeout_ms = 1000;
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t* handle = pcap_open_live(device, BUFSIZ, promiscuous, timeout_ms, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    volatile int stop = 0;

    monitor_context_t monitor_context = { handle, &stop };

    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, packet_monitor, &monitor_context)) {
        fprintf(stderr, "Error creating thread.\n");
        exit(1);
    }

    getchar();

    stop = 1;

    if (pthread_join(monitor_thread, NULL)) {
        fprintf(stderr, "Error joining thread.\n");
        exit(1);
    }

    return 0;
}