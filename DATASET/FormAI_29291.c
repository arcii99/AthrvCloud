//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet Captured with length of %d\n", header->len);
}

int main(int argc, char **argv)
{
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *session_handle;
    int packet_count_limit = 1;
    int timeout_limit = 10000;

    // Get Device Name
    device = pcap_lookupdev(error_buffer);
    if(device == NULL)
    {
        printf("Error Finding Device: %s\n", error_buffer);
        return 1;
    }

    // Open Session
    session_handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if(session_handle == NULL)
    {
        printf("Error Opening Session: %s\n", error_buffer);
        return 1;
    }

    // Capture Packets
    pcap_loop(session_handle, packet_count_limit, packet_handler, NULL);

    // Close Session
    pcap_close(session_handle);

    printf("Packet Capture Complete.\n");

    return 0;
}