//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <pcap.h>
#include <stdio.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    printf("Packet length: %d\n", pkthdr->len);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("enp0s3", BUFSIZ, 1, 1000, errbuf);
    
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Error: Capture interface is not Ethernet.\n");
        return 1;
    }

    if (argc > 1) {
        if (pcap_setfilter(handle, argv[1]) == -1) {
            printf("Error: Unable to apply filter.\n");
            return 1;
        }
    }

    pcap_loop(handle, -1, packetHandler, NULL);
    pcap_close(handle);

    return 0;
}