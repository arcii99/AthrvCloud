//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    printf("Ho ho ho! A packet has been captured!\n");
    fflush(stdout);
}

int main(int argc, char** argv) {
    printf("Welcome to the Network Packet Monitoring Workshop!\n");
    printf("In this program, we'll be monitoring incoming network packets and printing out a message to spread some cheer!\n");

    // Set up the network interface for capturing packets
    char* device = pcap_lookupdev(NULL);
    if (device == NULL) {
        printf("Oops! Something went wrong while looking up the network device. Please check your network configuration.\n");
        exit(1);
    }
    printf("We'll be monitoring packets on device %s. Let's get started!\n", device);

    // Open a packet capture session
    pcap_t* session = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (session == NULL) {
        printf("Oops! Something went wrong while starting the packet capture session. Please check your network configuration.\n");
        exit(1);
    }

    // Start capturing packets and pass them to our packet handler
    while (1) {
        int result = pcap_dispatch(session, 0, packetHandler, NULL);
        if (result == -1) {
            printf("Oops! Something went wrong while capturing packets. Please check your network configuration.\n");
            exit(1);
        }
    }

    // Close the packet capture session
    pcap_close(session);

    return 0;
}