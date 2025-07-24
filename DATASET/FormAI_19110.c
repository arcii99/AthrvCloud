//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
 
void main(int argc, char **argv)
{
    char *dev_name, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 subnet_mask, ip;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
 
    // Get the name of the first device suitable for capture
    dev_name = pcap_lookupdev(errbuf);
    if (dev_name == NULL) 
    {
        printf("error finding the device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    printf("Capturing on device %s\n", dev_name);
 
    // Open the capture file
    handle = pcap_open_live(dev_name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) 
    {
        printf("Error opening the device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
 
    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) 
    {
        printf("Error compiling the filter\n");
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) 
    {
        printf("Error applying the filter\n");
        exit(EXIT_FAILURE);
    }
 
    // Loop through packets and call `packet_handler()` for each packet
    pcap_loop(handle, 0, packet_handler, NULL);
 
    // Close the handle and cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
 
    printf("Capture complete.\n");
}
 
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;                   
    printf("Packet %d:\n", count++);
 
    // Print the timestamp and length of the packet
    printf("    Timestamp:      %s", ctime((const time_t*)&(header->ts.tv_sec)));
    printf("    Length:         %d bytes\n", header->len);
 
    // Print the packet's contents
    for (int i=0; i<header->len; i++) 
    {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0) 
            printf("\n");
    }
 
    printf("\n\n");
}