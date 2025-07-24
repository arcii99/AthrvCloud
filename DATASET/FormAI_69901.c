//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    /* This is where we handle the captured packet. */
    printf("Packet captured!\n");
    
    // Print the packet data in hex format
    int i;
    for (i = 0; i < header->len; i++) {
        printf("%02x ", pkt_data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *capture_handle;
    const u_char *packet_data;
    struct pcap_pkthdr packet_header;
    
    // Open the capture device
    capture_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (capture_handle == NULL) {
        printf("pcap_open_live failed: %s\n", errbuf);
        return 1;
    }
    
    // Capture packets indefinitely
    int result = pcap_loop(capture_handle, -1, packet_handler, NULL);
    if (result == -1) {
        printf("pcap_loop failed: %s\n", pcap_geterr(capture_handle));
        return 1;
    }
    
    // Close the capture device
    pcap_close(capture_handle);
    
    return 0;
}