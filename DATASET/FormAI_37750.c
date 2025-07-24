//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// callback function that processes packet captures
void packetCaptureProcessor(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    printf("Packet Captured!\n");
}

int main(int argc, char *argv[])
{
    // handle command line arguments
    if(argc < 2)
    {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open device for packet capture
    pcap_t* handle;
    char* dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(EXIT_FAILURE);
    }

    // start capture loop
    int packetCount = 0;
    pcap_loop(handle, -1, packetCaptureProcessor, (u_char*)&packetCount);

    // close capture device
    pcap_close(handle);

    return(EXIT_SUCCESS);
}