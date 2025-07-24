//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> //Include the pcap library
 
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Got a packet! It's %d bytes long\n", header->len);
}
 
int main(int argc, char const *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip proto icmp"; //filter expression
    bpf_u_int32 net;
 
    //Open live pcap session on NIC
    handle = pcap_open_live("enp0s3", BUFSIZ, 1, 1000, errbuf);
 
    // Compile and apply filter
    pcap_compile(handle, &fp, filter_exp, 0, net);
    pcap_setfilter(handle, &fp);

    //Looping through packets
    pcap_loop(handle, -1, got_packet, NULL);
 
    pcap_close(handle); //Close the handle
    return 0;
}