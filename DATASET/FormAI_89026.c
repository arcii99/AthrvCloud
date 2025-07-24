//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <pcap.h>

int main() {
    printf("Welcome to the Packet Capturer!\n");
    printf("Warning: This program may cause extreme boredom and confusion.\n");
    printf("Running this program without knowledge of network packets may result in headaches, dizziness, and nausea. Proceed with caution.\n");

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }
    printf("Packet capture initialized. Prepare for information overload!\n");

    while(1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        }
        else if (res == -1 || res == -2) {
            printf("Error: %s\n", pcap_geterr(handle));
            break;
        }
        printf("Packet captured! Size: %d bytes.\n", header->len);
    }

    printf("Packet capture finished. Don't forget to blink!\n");
    pcap_close(handle);
    return 0;
}