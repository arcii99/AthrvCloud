//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: ultraprecise
#include <pcap.h> // Packet capture library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer){
    printf("Packet capture length is: %d bytes\n", header->caplen);
    printf("Packet total length is: %d bytes\n", header->len);

    int i = 0;
    for(i = 0; i < header->caplen; i++){
        printf("%.2x ", buffer[i]);
        if((i+1)%16 == 0) printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char *argv[]){
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "udp port 53 or icmp";
    bpf_u_int32 net, mask;

    // Step 1: Find a capture device
    char *dev = pcap_lookupdev(errbuf);
    if(dev == NULL){
        fprintf(stderr, "Couldn't find default capture device: %s\n", errbuf);
        return 2;
    }

    // Step 2: Open the device for capture
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL){
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Step 3: Compile and apply the filter
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1){
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if(pcap_setfilter(handle, &fp) == -1){
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Step 4: Capture packets
    printf("Listening on %s...\n", dev);
    pcap_loop(handle, -1, process_packet, NULL);

    // Step 5: Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}