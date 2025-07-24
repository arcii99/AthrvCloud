//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>
#include <stdint.h>

#define PACKET_LENGTH 512

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int packet_count = 0;

    // Display packet information
    printf("Packet %d:\n", ++packet_count);

    // Display packet length
    printf("Packet Length: %d\n", header->len);

    // Display the packet payload
    for (int i = 0; i < header->len; ++i) {
        printf("%02x ", packet[i]);

        // Print new line after every 16 bytes
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(int argc, const char *argv[])
{
    char *device_name = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;

    // Choose the device to capture the packets from
    device_name = pcap_lookupdev(error_buffer);

    if (device_name == NULL) {
        perror("pcap_lookupdev() failed");
        return 1;
    }

    printf("Using device: %s\n\n", device_name);

    // Open the device for sniffing
    handle = pcap_open_live(device_name, PACKET_LENGTH, 0, -1, error_buffer);

    if (handle == NULL) {
        perror("pcap_open_live() failed");
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);

    return 0;
}