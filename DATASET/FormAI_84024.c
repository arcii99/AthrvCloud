//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <pcap.h>

void packet_capture_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Captured a packet with length of %d\n", header->len);
    // More functionality here
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE]; // Buffer to store error messages
    pcap_t* packet_capture_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

    if (packet_capture_handle == NULL) {
        printf("Error opening packet capture handle: %s\n", error_buffer);
        return 1;
    }

    int ret = pcap_loop(packet_capture_handle, 0, packet_capture_handler, NULL);

    if (ret == -1) {
        printf("Error capturing packets: %s\n", pcap_geterr(packet_capture_handle));
        return 1;
    }

    pcap_close(packet_capture_handle); // Close the capture handle
    return 0; // Exit program
}