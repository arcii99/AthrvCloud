//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <pcap.h>
#include <arpa/inet.h>
 
#define BUFSIZE 1024
 
pthread_mutex_t mutex;
 
void *packet_capture(void *arg) {
    char errbuf[PCAP_ERRBUF_SIZE];   
    pcap_t *descr;
    struct pcap_pkthdr *header;
    const u_char *packet;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 10;
    int i;
 
    /* get network*/
    if(pcap_lookupnet(arg, &net, &mask, errbuf) == -1) {
        printf("Can't get netmask for device %s\n", arg);
        net = 0;
        mask = 0;
    }
 
    /* open device for sniffing */
    descr = pcap_open_live(arg, BUFSIZE, 1, 1000, errbuf);
    if(descr == NULL) {
        printf("Couldn't open device %s: %s\n", arg, errbuf);
        return NULL;
    }
 
    /* compile the filter expression */
    if(pcap_compile(descr, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(descr));
        return NULL;
    }
 
    /* apply the compiled filter */
    if(pcap_setfilter(descr, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(descr));
        return NULL;
    }
 
    /* loop through packets and collect TCP data */
    for(i = 0; i < num_packets; i++) {
        packet = pcap_next(descr, header);
        if(packet == NULL) {
            printf("Didn't capture packet within timeout\n");
            continue;
        }
        printf("Packet Capture #%d\n", i);
 
        /* lock mutex before accessing shared resource */
        pthread_mutex_lock(&mutex);
 
        /* TCP data found! parse it */
        printf("TCP data found!\n");
 
        /* unlock mutex after accessing shared resource */
        pthread_mutex_unlock(&mutex);
    }
 
    pcap_close(descr);
    return NULL;
}
 
int main(int argc, char **argv) {
    int num_threads = 4;
    int i;
    char *devices[] = {"eth0", "eth1", "wlan0", "wlan1"};
    pthread_t threads[num_threads];
 
    pthread_mutex_init(&mutex, NULL);
 
    /* create threads to capture packets on different devices */
    for(i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, packet_capture, devices[i]);
    }
 
    /* wait for threads to finish */
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
 
    pthread_mutex_destroy(&mutex);
 
    return 0;
}