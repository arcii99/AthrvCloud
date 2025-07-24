//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "port 80";
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr header;
    const u_char *packet;
    int res;

    // Obtain network and mask info from the handle
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for eth0\n");
        net = 0;
        mask = 0;
    }

    // Open the session in non-promiscuous mode
    handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device eth0: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Loop through packets and print info
    while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (res == 0) continue;

        packet_handler((u_char*) NULL, &header, packet);
    }

    // Clean up and exit
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;                   // Packet counter
    printf("\nPacket number %d:\n", count);
    printf("  Length: %d bytes\n", pkthdr->len);
    printf("  Capture time: %s", ctime((const time_t*)&pkthdr->ts.tv_sec));

    count++;
}