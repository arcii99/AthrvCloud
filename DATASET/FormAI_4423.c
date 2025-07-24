//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/ether.h>

int main(int argc, char **argv) {
    char errbuff[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuff);

    if (handle == NULL) {
        printf("Could not open interface 'en0': %s\n", errbuff);
        return -1;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;

        if (res == -1 || res == -2) break;

        struct iphdr *ip = (struct iphdr*)(packet + sizeof(struct ether_header));
        char src_addr_str[INET_ADDRSTRLEN];
        char dst_addr_str[INET_ADDRSTRLEN];

        inet_ntop(AF_INET, &ip->saddr, src_addr_str, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &ip->daddr, dst_addr_str, INET_ADDRSTRLEN);

        printf("source address: %s\n", src_addr_str);
        printf("destination address: %s\n", dst_addr_str);

        int payload_size = ntohs(ip->tot_len) - sizeof(struct iphdr);
        const u_char *payload = packet + sizeof(struct ether_header) + sizeof(struct iphdr);
        printf("payload: ");
        for (int i = 0; i < payload_size; i++)
            printf("%02x ", payload[i]);
        printf("\n\n");

    }

    pcap_close(handle);

    return 0;
}