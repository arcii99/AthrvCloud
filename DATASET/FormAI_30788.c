//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_payload(const u_char *payload, int len);

int main(int argc, char *argv[]) {
    char *device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];

    printf("Starting packet monitoring on device: %s\n", device);

    pcap_t *captured_packets = pcap_open_live(device, 65536, 1, 0, error_buffer);

    if (captured_packets == NULL) {
        printf("Could not open device: %s, error message: %s\n", device, error_buffer);
        exit(1);
    }

    if (pcap_datalink(captured_packets) != DLT_EN10MB) {
        printf("Device %s does not provide Ethernet headers - not supported\n", device);
        exit(1);
    }

    pcap_loop(captured_packets, -1, packet_handler, NULL);

    pcap_close(captured_packets);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *ethernet_header = (struct ether_header *)packet;
    struct ip *ip_header = (struct ip*)(packet + sizeof(struct ether_header));
    struct tcphdr *tcp_header = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));    // TCP Layer
    struct udphdr *udp_header = (struct udphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));    // UDP Layer

    int size_IP = ip_header->ip_hl*4;    // Calculate IP header length
    int size_protocol;

    if (ip_header->ip_p == IPPROTO_TCP) {    // TCP Packet
        size_protocol = tcp_header->th_off*4;
        printf("TCP Packet Detected\n");
        printf("Source IP Address: %s\n", inet_ntoa(ip_header->ip_src));
        printf("Destination IP Address: %s\n", inet_ntoa(ip_header->ip_dst));
        printf("Source Port: %d\n", ntohs(tcp_header->th_sport));
        printf("Destination Port: %d\n", ntohs(tcp_header->th_dport));
        print_payload(packet + sizeof(struct ether_header) + size_IP + size_protocol, (header->len - sizeof(struct ether_header) - size_IP - size_protocol));
        printf("\n");
    } else if (ip_header->ip_p == IPPROTO_UDP) {    // UDP Packet
        size_protocol = sizeof(struct udphdr);
        printf("UDP Packet Detected\n");
        printf("Source IP Address: %s\n", inet_ntoa(ip_header->ip_src));
        printf("Destination IP Address: %s\n", inet_ntoa(ip_header->ip_dst));
        printf("Source Port: %d\n", ntohs(udp_header->uh_sport));
        printf("Destination Port: %d\n", ntohs(udp_header->uh_dport));
        print_payload(packet + sizeof(struct ether_header) + size_IP + size_protocol, (header->len - sizeof(struct ether_header) - size_IP - size_protocol));
        printf("\n");
    } else {    // Other Protocol Packet
        printf("Other Packet Detected\n");
        printf("Source IP Address: %s\n", inet_ntoa(ip_header->ip_src));
        printf("Destination IP Address: %s\n", inet_ntoa(ip_header->ip_dst));
        print_payload(packet + sizeof(struct ether_header) + size_IP, (header->len - sizeof(struct ether_header) - size_IP));
        printf("\n");
    }
}

void print_payload(const u_char *payload, int len) {
    int line_width = 16;
    int remaining_bytes = len;
    int i, j;
    const u_char * next_line;

    printf("Payload: \n");

    for (i = 0; i < len; i += line_width) {    // Print payload in multiple lines
        next_line = payload + i;    // Pointer to the first byte of the next line
        remaining_bytes -= line_width;

        if (remaining_bytes > 0) {
            // Continue if there are more bytes to print
            for (j = 0; j < line_width; j++) {
                printf("%02x ", *(next_line + j));
            }
        } else {
            // Print the last line
            for (j = 0; j < remaining_bytes + line_width; j++) {
                printf("%02x ", *(next_line + j));
            }
        }

        for (j = 0; j < line_width && j + i < len; j++) {
            if (*(next_line + j) >= 32 && *(next_line + j) <= 126) {
                printf("%c", *(next_line + j));
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}