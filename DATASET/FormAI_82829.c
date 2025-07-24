//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: medieval
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s", argv[1], errbuf);
        return 1;
    }
    printf("Starting the Packet Capturer...\n");
    printf("Press CTRL+C to stop the capture...\n\n");

    struct pcap_pkthdr header; //struct to hold packet header
    const u_char *packet; //u_char array to store packet
    while (1) {
        packet = pcap_next(handle, &header); //Get packet
        printf("\n------------------------\n");
        printf("New packet: %d bytes\n", header.len);
        printf("------------------------\n\n");
        int i;
        for (i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0) printf("\n"); //16 bytes per line
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}