//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: high level of detail
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet){
    printf("Packet Captured\n");
}

int main(int argc, char** argv){
    char* device = argv[1];
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    if (pcap_lookupnet(device, &ip, &subnet_mask, errbuf) == -1) {
        printf("Error: %s\n", errbuf);
        ip = 0;
        subnet_mask = 0;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, packetHandler, NULL);

    pcap_close(handle);
    return 0;
}