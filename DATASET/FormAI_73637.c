//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    handle = pcap_open_live(argv[1], 65535, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }
    printf("Listening on %s...\n", argv[1]);
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet captured! Length: %d\n", header.len);
            const u_char *dataptr = packet;
            for (int i = 0; i < header.len; i++) {
                printf("%02x ", *dataptr++);
                if ((i - 15) % 16 == 0) {
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    pcap_close(handle);
    return 0;
}