//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap/pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer){
    printf("Packet Captured!\n");
}

int main(){
    char *dev = "eth0"; // Change this to your default interface
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL){
        printf("Error while opening device: %s\n", errbuf);
        return 1;
    }

    if(pcap_loop(handle, -1, process_packet, NULL) < 0){
        printf("Error while processing packets\n");
        return 1;
    }

    pcap_close(handle);
    return 0;
}