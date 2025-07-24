//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open a live device for packet capture
    pcap_t *handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("pcap_open_live: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Start packet capture loop
    pcap_loop(handle, -1, process_packet, NULL);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf(".  .   *  *\n");
    printf("                 %%%%    __|__\n");
    printf("                      \\  /\\__\\/\n");
    printf("         *    `        \\/  _  \\\n");
    printf("     @     +      @    (  (_)  )       @\n");
    printf("    /                  \\     /         `\n");
    printf("                        `---'  hjw");
    printf("\n");
    printf("Packet Captured:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}