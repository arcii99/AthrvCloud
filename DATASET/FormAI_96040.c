//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured\n");
    // Do something with the captured packet
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct bpf_program fp;

    // Open the network interface for capturing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL)
    {
        fprintf(stderr, "Could not open network interface: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if(pcap_compile(handle, &fp, "tcp port 80", 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        fprintf(stderr, "Could not compile filter expression\n");
        return 2;
    }

    // Apply the filter expression to the network interface
    if(pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Could not apply filter expression\n");
        return 3;
    }

    // Capture packets indefinitely
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the network interface
    pcap_close(handle);

    return 0;
}