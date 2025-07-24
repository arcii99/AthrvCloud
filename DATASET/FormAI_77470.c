//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surrealist
#include <pcap.h>
#include <stdio.h>

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    printf("Packet captured\n");
}

int main(int argc, char const *argv[]){
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    handle = pcap_open_live("eth0", 65536, 1, 1000, errbuf);
    if (handle == NULL){
        printf("Error: %s\n", errbuf);
        return 1;
    }

    pcap_loop(handle, -1, processPacket, NULL);

    pcap_close(handle);
    return 0;
}