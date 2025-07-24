//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void got_packet(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {

    // Get the IP header
    struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ethhdr));

    // Check if it's TCP protocol
    if (ip->protocol == IPPROTO_TCP) {
        printf("\n\n*****Packet Captured*****\n");
        printf("Protocol: TCP\n");

        // Get the TCP header
        struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(struct ethhdr) + sizeof(struct iphdr));

        // Print source and destination IP and Port numbers
        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ip->saddr), src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip->daddr), dst_ip, INET_ADDRSTRLEN);
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dst_ip);
        printf("Source Port: %u\n", ntohs(tcp->source));
        printf("Destination Port: %u\n", ntohs(tcp->dest));

        // Print the TCP payload data
        const u_char *payload = packet + sizeof(struct ethhdr) + sizeof(struct iphdr) + sizeof(struct tcphdr);
        int payload_size = ntohs(ip->tot_len) - sizeof(struct iphdr) - sizeof(struct tcphdr);
        if (payload_size > 0) {
            printf("\nData:\n");
            printf("%.*s\n\n", payload_size, payload);
        }
    }
    // Check if it's UDP protocol
    else if (ip->protocol == IPPROTO_UDP) {
        printf("\n\n*****Packet Captured*****\n");
        printf("Protocol: UDP\n");

        // Get the UDP header
        struct udphdr *udp = (struct udphdr *)(packet + sizeof(struct ethhdr) + sizeof(struct iphdr));

        // Print source and destination IP and Port numbers
        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ip->saddr), src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip->daddr), dst_ip, INET_ADDRSTRLEN);
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dst_ip);
        printf("Source Port: %u\n", ntohs(udp->source));
        printf("Destination Port: %u\n", ntohs(udp->dest));

        // Print the UDP payload data
        const u_char *payload = packet + sizeof(struct ethhdr) + sizeof(struct iphdr) + sizeof(struct udphdr);
        int payload_size = ntohs(ip->tot_len) - sizeof(struct iphdr) - sizeof(struct udphdr);
        if (payload_size > 0) {
            printf("\nData:\n");
            printf("%.*s\n\n", payload_size, payload);
        }
    }
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;

    // Open pcap session for live capture
    pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error opening pcap session: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    // Compile and apply packet filter to capture TCP and UDP packets only
    char filter_exp[] = "ip and (tcp or udp)";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling packet filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting packet filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Start capturing packets
    printf("Packet capture started...\n");
    pcap_loop(handle, -1, got_packet, NULL);

    // Close pcap session
    pcap_close(handle);
    return EXIT_SUCCESS;
}