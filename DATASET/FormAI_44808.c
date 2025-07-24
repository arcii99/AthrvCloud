//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Cyberpunk
#include <pcap.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *device = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return 2;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *ethh = (struct ether_header *) packet;
    if (ntohs(ethh->ether_type) == ETHERTYPE_IP) {
        struct iphdr *iph = (struct iphdr *)(packet + sizeof(struct ether_header));
        if (iph->protocol == IPPROTO_TCP) {
            struct tcphdr *tcph = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
            printf("Dest IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
        }
    }
}