//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <stdio.h>
#include <pcap.h>

void errorCallback(u_char *userData, const struct pcap_pkthdr *pktHeader, const u_char *pktData) {
    printf("Error occurred during packet capture.\n");
}

void regularCallback(u_char *userData, const struct pcap_pkthdr *pktHeader, const u_char *pktData) {
    printf("Received packet with length %d.\n", pktHeader->len);
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if(argc < 2) {
        printf("Usage: %s <interface name>\n", argv[0]);
        return 1;
    }

    handle = pcap_create(argv[1], errbuf);
    if(handle == NULL) {
        printf("pcap_create failed with error: %s\n", errbuf);
        return 1;
    }

    pcap_set_snaplen(handle, 65535);
    pcap_set_promisc(handle, 1);

    int rv = pcap_activate(handle);
    if(rv != 0) {
        printf("pcap_activate failed with error: %s\n", pcap_geterr(handle));
        return 1;
    }

    rv = pcap_loop(handle, -1, regularCallback, NULL);
    if(rv < 0) {
        printf("pcap_loop failed with error: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);

    return 0;
}