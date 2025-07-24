//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <pcap/pcap.h>

#define SNAP_LEN 65535

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    printf("Packet Captured\n");
}
 
int main()
{
    char device[] = "eth0"; // replace this with the name of your network interface

    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *packetCaptureHandle;
    struct bpf_program compiledFilter;
    bpf_u_int32 rawNetworkAddress, rawNetmask;
    char filter[] = ""; // put a filter expression here, or leave it empty to capture all packets
    
    if (pcap_lookupnet(device, &rawNetworkAddress, &rawNetmask, errorBuffer) == -1)
    {
        fprintf(stderr, "Error in pcap_lookupnet: %s\n", errorBuffer);
        return 1;
    }

    packetCaptureHandle = pcap_open_live(device, SNAP_LEN, 1, 0, errorBuffer);
    if (packetCaptureHandle == NULL)
    {
        fprintf(stderr, "Error in pcap_open_live: %s\n", errorBuffer);
        return 1;
    }

    if (filter[0] != '\0')
    {
        if (pcap_compile(packetCaptureHandle, &compiledFilter, filter, 0, rawNetworkAddress) == -1)
        {
            fprintf(stderr, "Error in pcap_compile: %s\n", pcap_geterr(packetCaptureHandle));
            return 1;
        }

        if (pcap_setfilter(packetCaptureHandle, &compiledFilter) == -1)
        {
            fprintf(stderr, "Error in pcap_setfilter: %s\n", pcap_geterr(packetCaptureHandle));
            return 1;
        }
    }

    pcap_loop(packetCaptureHandle, 0, packetHandler, NULL);

    pcap_close(packetCaptureHandle);

    return 0;
}