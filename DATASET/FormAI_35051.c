//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <pcap.h>

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    struct bpf_program filter;

    char *interface = "eth0";
    int snaplen = 65535; // same as MTU for the network interface
    int promiscuous = 0; // set to 1 for promiscuous mode

    pcap_handle = pcap_open_live(interface, snaplen, promiscuous, 1000, errbuf);
    if (!pcap_handle) {
        printf("Error while opening network device: %s\n", errbuf);
        return -1;
    }

    // compile a filter expression to capture packets with a certain pattern
    if (pcap_compile(pcap_handle, &filter, "tcp port 80", 1, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(pcap_handle));
        return -1;
    }

    // apply the compiled filter to the handle
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(pcap_handle));
        return -1;
    }

    // loop through received packets and print their content
    struct pcap_pkthdr header;
    const u_char *packet;
    while ((packet = pcap_next(pcap_handle, &header))) {
        printf("Packet captured! Length: %d\n", header.len);
        for (u_int i=0; i<header.len; i++)
            printf("%02x ", packet[i]); // print each byte in hexadecimal format
        printf("\n\n");
    }

    // cleanup
    pcap_close(pcap_handle);
    pcap_freecode(&filter);
    
    return 0;
}