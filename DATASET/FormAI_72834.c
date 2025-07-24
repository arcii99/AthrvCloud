//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cryptic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1; // keep track of packet count
    printf("Packet #%d:\n", count);
    printf("Timestamp: %s", ctime(&header->ts.tv_sec)); // print the timestamp
    printf("Length: %d\n", header->len);
    printf("Captured Length: %d\n", header->caplen);
    printf("\n");
    count++;
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE]; // buffer for error messages
    pcap_t *handle; // handle for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer); // open the capture device
    if (handle == NULL)
    {
        printf("Error opening device: %s", error_buffer);
        return 1;
    }
    pcap_loop(handle, -1, packet_handler, NULL); // start the packet capture loop
    pcap_close(handle); // close the capture device
    return 0;
}