//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <stdio.h>
#include <pcap/pcap.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

pcap_t *handle;
char errbuf[PCAP_ERRBUF_SIZE];
int stop_signal = 0;

void sig_handler(int signum) {
    printf("\nStopping capture...\n");
    stop_signal = 1;
    pcap_breakloop(handle);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;
    struct ether_header *ethernet_header = (struct ether_header*) packet;
    printf("%d. Ethernet Type: %d\n", count++, ntohs(ethernet_header->ether_type));
    fflush(stdout);
}

void capture_packets() {
    if (handle == NULL) {
        printf("Error opening device for capture: %s\n", errbuf);
        return;
    }
    if (pcap_setnonblock(handle, 1, errbuf) == -1) {
        printf("Error setting device to non-block mode: %s\n", errbuf);
        return;
    }
    signal(SIGINT, sig_handler);
    printf("Packet capture started...\n");
    while (!stop_signal) {
        pcap_dispatch(handle, 1, process_packet, NULL);
        usleep(50);
    }
    pcap_close(handle);
}

int main(int argc, char **argv) {
    char *device = NULL;
    char *filter = NULL;
    if (argc >= 2) {
        device = argv[1];
    } else {
        device = pcap_lookupdev(errbuf);
    }
    if (device == NULL) {
        printf("Error finding default device : %s\n", errbuf);
        return -1;
    }
    printf("Device: %s\n", device);
    handle = pcap_open_live(device, 4096, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device for capture: %s\n", errbuf);
        return -1;
    }
    capture_packets();
    return 0;
}