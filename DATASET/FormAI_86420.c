//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data) {
    struct ether_header *ethernet_hdr;
    struct iphdr *ip_hdr;
    struct tcphdr *tcp_hdr;
    struct udphdr *udp_hdr;
    const u_char *payload;
    int ip_hdr_len, tcp_hdr_len, udp_hdr_len, payload_len;

    // Get Ethernet header
    ethernet_hdr = (struct ether_header*)pkt_data;

    // Check if IP packet
    if (ntohs(ethernet_hdr->ether_type) == ETHERTYPE_IP) {
        // Get IP header
        ip_hdr = (struct iphdr*)(pkt_data + sizeof(struct ether_header));
        ip_hdr_len = ip_hdr->ihl * 4;

        // Check if TCP or UDP packet
        if (ip_hdr->protocol == IPPROTO_TCP) {
            // Get TCP header
            tcp_hdr = (struct tcphdr*)(pkt_data + sizeof(struct ether_header) + ip_hdr_len);
            tcp_hdr_len = tcp_hdr->doff * 4;

            // Get packet payload
            payload = pkt_data + sizeof(struct ether_header) + ip_hdr_len + tcp_hdr_len;
            payload_len = ntohs(ip_hdr->tot_len) - ip_hdr_len - tcp_hdr_len;

            // Print packet info
            printf("TCP packet: %s:%d -> %s:%d\n",
                    inet_ntoa(*(struct in_addr*)&ip_hdr->saddr), ntohs(tcp_hdr->source),
                    inet_ntoa(*(struct in_addr*)&ip_hdr->daddr), ntohs(tcp_hdr->dest));
            printf("Payload: ");
            for (int i = 0; i < payload_len; i++) {
                printf("%c", payload[i]);
            }
            printf("\n");
        } else if (ip_hdr->protocol == IPPROTO_UDP) {
            // Get UDP header
            udp_hdr = (struct udphdr*)(pkt_data + sizeof(struct ether_header) + ip_hdr_len);
            udp_hdr_len = sizeof(struct udphdr);

            // Get packet payload
            payload = pkt_data + sizeof(struct ether_header) + ip_hdr_len + udp_hdr_len;
            payload_len = ntohs(ip_hdr->tot_len) - ip_hdr_len - udp_hdr_len;

            // Print packet info
            printf("UDP packet: %s:%d -> %s:%d\n",
                    inet_ntoa(*(struct in_addr*)&ip_hdr->saddr), ntohs(udp_hdr->source),
                    inet_ntoa(*(struct in_addr*)&ip_hdr->daddr), ntohs(udp_hdr->dest));
            printf("Payload: ");
            for (int i = 0; i < payload_len; i++) {
                printf("%c", payload[i]);
            }
            printf("\n");
        }
    }
}

int main(int argc, char const *argv[]) {
    pcap_t *handle;
    struct bpf_program fp;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "ip";
    bpf_u_int32 net, mask;

    // Get network device and mask
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "ERROR finding device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "ERROR getting mask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open network device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "ERROR opening device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and apply packet filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "ERROR compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "ERROR applying filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start capturing packets
    printf("Capturing packets on device %s...\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up and close network device
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}