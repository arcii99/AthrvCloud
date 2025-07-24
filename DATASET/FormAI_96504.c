//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <stdio.h>
#include <pcap.h>
#include <pthread.h>

#define SNAP_LEN 1518 // maximum length of packet to capture
#define PROMISC_MODE 1 // set promiscuous mode
#define TIMEOUT_MS 1000 // set timeout in milliseconds

void *packet_handler(void *);
pcap_t *handle; // packet capture handle 

int main(int argc, char *argv[]) {
    char *dev; // device name
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    bpf_u_int32 net; // ip address of device
    bpf_u_int32 mask; // subnet mask of device
    struct pcap_pkthdr header; // packet header
    const u_char *packet; // captured packet

    // Determine device to sniff
    if(argc == 2) {
        dev = argv[1];
    }
    else {
        dev = pcap_lookupdev(errbuf);
        if(dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return 2;
        }
    }

    // Get network address and subnet mask of device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for sniffing
    handle = pcap_open_live(dev, SNAP_LEN, PROMISC_MODE, TIMEOUT_MS, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Create a seperate thread to capture packets
    pthread_t thread;
    int *ret_val = NULL;
    if(pthread_create(&thread, NULL, packet_handler, NULL) != 0) {
        fprintf(stderr, "Error creating packet capture thread\n");
        return 2;
    }

    // Main thread loop
    while(1) {
        printf("Waiting for packets...\n");
        int res = pcap_next_ex(handle, &header, &packet);
        if(res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } 
        else if(res == 0) {
            continue;
        }
        printf("Packet captured!\n\n");
    }

    // Cleanup
    pcap_close(handle);
    return 0;
}

// Packet capture callback function
void *packet_handler(void *args) {
    struct pcap_pkthdr header;
    const u_char *packet;
    while(1){
        int res = pcap_next_ex(handle, &header, &packet);
        if(res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        }
        else if(res == 0) {
            continue;
        }
        printf("Packet captured asynchronously!\n\n");
    }
    return NULL;
}