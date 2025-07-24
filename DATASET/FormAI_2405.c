//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main() 
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("enp0s3", 65536, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening adapter: %s", errbuf);
        return 1;
    }
    printf("Packet capture started on adapter: enp0s3. Capturing packets...\n");

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured. Length: %d\n", header->len);
    // Do something with the packet data
    // ...
}