//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <pcap.h> //importing pcap library

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE]; //declaring buffer to store error message
    pcap_t *handle; //declaring variable for pcap_t structure
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf); //capturing packets from eth0 interface
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf); //printing error message if any
        return(2);
    }
    fprintf(stdout, "Packet capturer is up and running!\n"); // printing cheerful message if everything is okay
    
    struct pcap_pkthdr header; //declaring pcap_pkthdr structure
    const u_char *packet; //pointer to store packet data
    packet = pcap_next(handle, &header); //fetching next packet using pcap_next
    fprintf(stdout, "Successfully captured the packet! :)\n"); // printing cheerful message if packet is captured
    
    pcap_close(handle); //closing the pcap handle
    return(0); //exiting the program
}