//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char *argv[]){
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr;
    const u_char *packet;
    struct pcap_pkthdr hdr;
    struct bpf_program fp;  
    char filter_exp[] = "icmp";
    bpf_u_int32 maskp;
    bpf_u_int32 netp;
    int ret;    

    // Get default device
    char *device = pcap_lookupdev(errbuf);
    if(device == NULL){
        printf(errbuf);
        exit(1);
    }

    // Open device for live capture
    descr = pcap_open_live(device, BUFSIZ, 0, -1, errbuf);
    if(descr == NULL){
        printf("pcap_open_live() failed due to [%s]\n", errbuf);
        exit(1);
    }

    // Compile filter expression
    if(pcap_lookupnet(device, &netp, &maskp, errbuf) == -1){
        printf("Error getting network mask for device [%s], Error: %s\n", device, errbuf);
        netp = 0;
        maskp = 0;
    }
    ret = pcap_compile(descr, &fp, filter_exp, 0, netp);
    if(ret == -1){
        printf("Error compiling filter expression: Error %s\n", pcap_geterr(descr));
        exit(1);
    }

    // Set filter
    ret = pcap_setfilter(descr, &fp);
    if(ret == -1){
        printf("Error setting filter: Error %s\n", pcap_geterr(descr));
        exit(1);
    }

    // Capture packets
    pcap_loop(descr, -1, packet_handler, NULL);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data){
    int i;
    static int count=0;

    // Print packet data
    printf("[%d] Packet Capture:\n", ++count);
    for(i=0; i < header->caplen; i++){
        printf("%02x ", *(pkt_data+i));
        if((i%16==15) || (i==header->caplen-1)) printf("\n");
    }

    printf("\n");
}