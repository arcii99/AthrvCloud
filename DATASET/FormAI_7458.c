//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <pthread.h>

#define MAX_PACKETS_PER_THREAD 1000 // Maximum number of packets a thread can handle
#define NUM_THREADS 4 // Number of threads

struct thread_info {
    int thread_id;
    pcap_t *pcap_handle;
    char *filter_expression;
};

void *packet_handler(void *arg) {
    struct thread_info *t_info = (struct thread_info *) arg;
    pcap_t *pcap_handle = t_info->pcap_handle;
    char *filter_expression = t_info->filter_expression;
    int thread_id = t_info->thread_id;

    struct pcap_pkthdr header;
    const u_char *packet;

    pcap_setnonblock(pcap_handle, 1, NULL); // Set non-blocking mode

    // Compile and set filter
    struct bpf_program fp;
    if (pcap_compile(pcap_handle, &fp, filter_expression, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter for thread %d: %s\n", thread_id, pcap_geterr(pcap_handle));
        return NULL;
    }
    if (pcap_setfilter(pcap_handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter for thread %d: %s\n", thread_id, pcap_geterr(pcap_handle));
        return NULL;
    }

    // Start packet capture loop
    int packet_count = 0;
    while (packet_count < MAX_PACKETS_PER_THREAD) {
        packet = pcap_next(pcap_handle, &header);
        if (packet != NULL) {
            // Process and store packet
            printf("Thread %d captured packet of length %d\n", thread_id, header.len); // Example processing
            // ...
            packet_count++;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handles[NUM_THREADS];
    struct thread_info t_info[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    // Open pcap handles for each thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pcap_handles[i] = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf); // Example interface: argv[1]
        if (pcap_handles[i] == NULL) {
            fprintf(stderr, "Error opening interface for thread %d: %s\n", i, errbuf);
            return 1;
        }
    }

    // Start threads
    for (int i = 0; i < NUM_THREADS; i++) {
        char filter_expression[100];
        sprintf(filter_expression, "src host 192.168.1.%d", i+1); // Example filter expression
        t_info[i].thread_id = i;
        t_info[i].pcap_handle = pcap_handles[i];
        t_info[i].filter_expression = filter_expression;
        pthread_create(&threads[i], NULL, packet_handler, &t_info[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close pcap handles
    for (int i = 0; i < NUM_THREADS; i++) {
        pcap_close(pcap_handles[i]);
    }

    return 0;
}