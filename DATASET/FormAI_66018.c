//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char* argv[])
{
    char* device = "eth0"; // set the device to monitor
    char errorBuffer[PCAP_ERRBUF_SIZE]; // buffer to store error messages
    
    // open the device for live capture
    pcap_t* handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer);
    
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errorBuffer);
        return 1;
    }
    
    printf("Listening on %s...\n", device);
    
    // start packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // close the capture device
    pcap_close(handle);
    
    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // print timestamp and packet length
    printf("%ld:%ld (%ld)\n", pkthdr->ts.tv_sec, pkthdr->ts.tv_usec, pkthdr->len);
    
    // print the packet in hexadecimal
    for (int i=0; i<pkthdr->len; i++)
    {
        printf("%02x ", packet[i]);
        if ((i+1)%16==0) printf("\n");
    }
    
    printf("\n\n");
}