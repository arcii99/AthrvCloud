//FormAI DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFFER_SIZE 16000

void packet_handler(unsigned char* param, const struct pcap_pkthdr* header, const unsigned char* data)
{

    // Do some packet handling here

}

int main(int argc, char** argv)
{

    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "src host 192.168.1.2";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Open live pcap session
    handle = pcap_open_live("eth0", BUFFER_SIZE, 0, 1000, errbuf);
    if (handle == NULL) 
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", "eth0", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) 
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Set filter
    if (pcap_setfilter(handle, &fp) == -1) 
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);

    return 0;
}