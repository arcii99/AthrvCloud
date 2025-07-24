//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int packet_count = 0; // counter for packets captured

void packet_handler(u_char *user_args, const struct pcap_pkthdr *packet_header, const u_char *packet_data)
{
    printf("Packet number %d:\n", ++packet_count);
    printf("Packet size: %d bytes\n", packet_header->len);
    printf("Captured at: %s\n", ctime((const time_t *)&packet_header->ts.tv_sec)); // prints the date/time of the packet capture
    printf("--------------------------\n");
}

int main(int argc, char *argv[])
{
    char *device = NULL; // pointer to hold device name
    char error_buffer[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *handle; // packet capture handle

    device = pcap_lookupdev(error_buffer); // get default device
    if(device == NULL)
    {
        fprintf(stderr, "Failed to find default device: %s\n", error_buffer);
        return 1;
    }
    printf("Capturing on device: %s\n", device);

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer); // start capturing packets on the device
    if(handle == NULL)
    {
        fprintf(stderr, "Failed to open device %s: %s\n", device, error_buffer);
        return 1;
    }

    printf("Packet capturing started...\n");

    pcap_loop(handle, -1, packet_handler, NULL); // loop to capture packets continuously

    pcap_close(handle); // close the capture handle

    printf("Packet capturing stopped.\n");
    return 0;
}