//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <pcap.h>
#include <stdio.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int packetCount = 0;

    printf("Packet Count: %d\n", ++packetCount);
    printf("Packet size: %d bytes\n", pkthdr->len);

    // Process the packet data
    // ...

    return;
}

int main()
{
    char* dev = "eth0"; // The network interface
    char errbuf[PCAP_ERRBUF_SIZE]; // Error string
    pcap_t* handle; // Session handle
    int timeout = 1000; // Timeout in milliseconds

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, timeout, errbuf);
    if (handle == NULL)
    {
        printf("Could not open device %s\n", dev);
        return 1;
    }

    // Set the filter
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        printf("Could not parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Could not install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    pcap_loop(handle, -1, packetHandler, NULL);

    // Close the handle and return
    pcap_close(handle);
    return 0;
}