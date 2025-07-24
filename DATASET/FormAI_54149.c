//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <pcap.h>
#include <stdio.h>

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
}

int main(int argc, char **argv)
{
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    int count = 0;
    int returnValue;

    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }

    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error getting network information: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("Error opening device %s: %s\n", dev, errbuf);
        return 1;
    }

    if(pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    returnValue = pcap_loop(handle, 0, processPacket, NULL);
    if(returnValue == -1) {
        printf("Error in pcap loop: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);

    return 0;
}