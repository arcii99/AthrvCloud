//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Yay! Packet captured!\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Oops! Could not open device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Monitoring network packets...\n");

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return EXIT_SUCCESS;
}