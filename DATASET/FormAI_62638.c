//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;

    handle = pcap_open_live("enp0s3", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: couldn't open device enp0s3\n");
        return(2);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error: couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_close(handle);
    return(0);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_count = 1;

    const struct ether_header *ethernet;
    const struct ip *ip;
    const struct tcphdr *tcp;
    const struct udphdr *udp;
    const char *payload;

    int size_ethernet = sizeof(struct ether_header);
    int size_ip;
    int size_tcp;
    int size_udp;
    int size_payload;

    ethernet = (struct ether_header*)(packet);
    if (ntohs(ethernet->ether_type) == ETHERTYPE_IP) {
        ip = (struct ip*)(packet + size_ethernet);
        size_ip = ip->ip_hl * 4;
        if (size_ip < 20) {
            printf("Error: Invalid IP header length: %u bytes\n", size_ip);
            return;
        }

        if (ip->ip_p == IPPROTO_TCP) {
            tcp = (struct tcphdr*)(packet + size_ethernet + size_ip);
            size_tcp = tcp->th_off * 4;
            if (size_tcp < 20) {
                printf("Error: Invalid TCP header length: %u bytes\n", size_tcp);
                return;
            }

            payload = (u_char *)(packet + size_ethernet + size_ip + size_tcp);
            size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);

            printf("\nPacket %d:\n", packet_count);
            packet_count++;

            printf("Source MAC: ");
            for (int i = 0; i < 6; i++) {
                printf("%02x", ethernet->ether_shost[i]);
                if (i < 5) {
                    printf(":");
                }
            }
            printf("\n");

            printf("Destination MAC: ");
            for (int i = 0; i < 6; i++) {
                printf("%02x", ethernet->ether_dhost[i]);
                if (i < 5) {
                    printf(":");
                }
            }
            printf("\n");

            printf("Source IP: %s\n", inet_ntoa(ip->ip_src));
            printf("Destination IP: %s\n", inet_ntoa(ip->ip_dst));

            printf("Source Port: %d\n", ntohs(tcp->th_sport));
            printf("Destination Port: %d\n", ntohs(tcp->th_dport));

            printf("Payload (%d bytes):\n", size_payload);
            for (int i = 0; i < size_payload; i++) {
                if (isprint(payload[i])) {
                    printf("%c", payload[i]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        } else if (ip->ip_p == IPPROTO_UDP) {
            udp = (struct udphdr*)(packet + size_ethernet + size_ip);
            size_udp = 8;

            payload = (u_char *)(packet + size_ethernet + size_ip + size_udp);
            size_payload = ntohs(udp->uh_ulen) - size_udp;

            printf("\nPacket %d:\n", packet_count);
            packet_count++;

            printf("Source MAC: ");
            for (int i = 0; i < 6; i++) {
                printf("%02x", ethernet->ether_shost[i]);
                if (i < 5) {
                    printf(":");
                }
            }
            printf("\n");

            printf("Destination MAC: ");
            for (int i = 0; i < 6; i++) {
                printf("%02x", ethernet->ether_dhost[i]);
                if (i < 5) {
                    printf(":");
                }
            }
            printf("\n");

            printf("Source IP: %s\n", inet_ntoa(ip->ip_src));
            printf("Destination IP: %s\n", inet_ntoa(ip->ip_dst));

            printf("Source Port: %d\n", ntohs(udp->uh_sport));
            printf("Destination Port: %d\n", ntohs(udp->uh_dport));

            printf("Payload (%d bytes):\n", size_payload);
            for (int i = 0; i < size_payload; i++) {
                if (isprint(payload[i])) {
                    printf("%c", payload[i]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}