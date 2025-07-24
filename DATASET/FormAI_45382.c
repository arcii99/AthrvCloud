//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
/* I am a network packet monitoring program that uses C programming language to capture and analyze network packets in real-time. My code is designed to work on Linux operating systems using the libpcap library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h> // include libpcap library
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet); // declare the packet handler function

int main(int argc, char** argv) {
    pcap_t* handle; // pcap_t handle to initiate packet capture
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer to store pcap_open_live errors
    char* device = "eth0"; // set default interface to "eth0"
    int timeout = 1000; // read timeout for pcap_next_ex function in milliseconds

    if (argc > 1) {
        device = argv[1]; // command-line argument to set interface
    }

    handle = pcap_open_live(device, BUFSIZ, 1, timeout, errbuf); // initiate packet capture on specified interface

    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return -1;
    }

    pcap_loop(handle, -1, packetHandler, NULL); // start packet capture on specified interface
    pcap_close(handle); // close pcap_t handle
    printf("Packet capture complete.\n"); // print completion message

    return 0;
}

void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // packet handler function to analyze network packets

    struct ether_header* ethernetHeader;
    struct iphdr* ipHeader;
    struct tcphdr* tcpHeader;
    struct udphdr* udpHeader;
    u_int16_t etherType;
    u_int ipHeaderLength;

    // extract ethernet header information
    ethernetHeader = (struct ether_header*) packet;
    etherType = ntohs(ethernetHeader->ether_type);

    // only analyze IP packets (skip non-IP packets such as ARP)
    if (etherType == ETHERTYPE_IP) {

        // extract IP header information
        ipHeader = (struct iphdr*) (packet + sizeof(struct ether_header));
        ipHeaderLength = ipHeader->ihl * 4;

        // analyze TCP packets
        if (ipHeader->protocol == IPPROTO_TCP) {
            tcpHeader = (struct tcphdr*) (packet + sizeof(struct ether_header) + ipHeaderLength);

            // print source and destination MAC addresses, source and destination IP addresses, source and destination ports, and TCP flags
            printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X -> %02X:%02X:%02X:%02X:%02X:%02X\n", 
                    ethernetHeader->ether_shost[0], ethernetHeader->ether_shost[1], ethernetHeader->ether_shost[2], 
                    ethernetHeader->ether_shost[3], ethernetHeader->ether_shost[4], ethernetHeader->ether_shost[5],
                    ethernetHeader->ether_dhost[0], ethernetHeader->ether_dhost[1], ethernetHeader->ether_dhost[2], 
                    ethernetHeader->ether_dhost[3], ethernetHeader->ether_dhost[4], ethernetHeader->ether_dhost[5]);

            printf("IP: %s -> %s, ", inet_ntoa(*(struct in_addr*)&ipHeader->saddr), inet_ntoa(*(struct in_addr*)&ipHeader->daddr));
            printf("Port: %u -> %u, ", ntohs(tcpHeader->source), ntohs(tcpHeader->dest));
            printf("Flags: ");

            if (tcpHeader->syn) {
                printf("SYN ");
            }

            if (tcpHeader->fin) {
                printf("FIN ");
            }

            if (tcpHeader->ack) {
                printf("ACK ");
            }

            printf("\n");
        }

        // analyze UDP packets
        else if (ipHeader->protocol == IPPROTO_UDP) {
            udpHeader = (struct udphdr*) (packet + sizeof(struct ether_header) + ipHeaderLength);

            // print source and destination MAC addresses, source and destination IP addresses, source and destination ports
            printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X -> %02X:%02X:%02X:%02X:%02X:%02X\n", 
                    ethernetHeader->ether_shost[0], ethernetHeader->ether_shost[1], ethernetHeader->ether_shost[2], 
                    ethernetHeader->ether_shost[3], ethernetHeader->ether_shost[4], ethernetHeader->ether_shost[5],
                    ethernetHeader->ether_dhost[0], ethernetHeader->ether_dhost[1], ethernetHeader->ether_dhost[2], 
                    ethernetHeader->ether_dhost[3], ethernetHeader->ether_dhost[4], ethernetHeader->ether_dhost[5]);

            printf("IP: %s -> %s, ", inet_ntoa(*(struct in_addr*)&ipHeader->saddr), inet_ntoa(*(struct in_addr*)&ipHeader->daddr));
            printf("Port: %u -> %u\n", ntohs(udpHeader->source), ntohs(udpHeader->dest));
        }
    }
}