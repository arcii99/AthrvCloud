//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv)
{
    pcap_t *pcap_handle;    // Session handle
    char *device;           // Name of the device to sniff
    char error_buffer[PCAP_ERRBUF_SIZE];    // Buffer to hold error messages
    int timeout_limit = 10000;  // In milliseconds

    // Get the name of the first device suitable for capture
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error finding device: %s\n", error_buffer);
        return 1;
    }

    // Open the session for capturing packets
    pcap_handle = pcap_open_live(device, BUFSIZ, 0, timeout_limit, error_buffer);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening pcap session: %s\n", error_buffer);
        return 1;
    }

    // Start the capture loop
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    // Close the session
    pcap_close(pcap_handle);
    return 0;
}

// Callback function to handle incoming packets
void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Process the packet here
    printf("Packet captured! Length: %d\n", header->len);
}