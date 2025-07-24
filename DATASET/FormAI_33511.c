//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv) {
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeoutLimit = 10000;
    int packetCountLimit = 0;

    /* Get default network device */
    device = pcap_lookupdev(errorBuffer);
    if (!device) {
        printf("Error finding device: %s\n", errorBuffer);
        exit(1);
    }
    printf("Sniffing on device: %s\n", device);

    /* Open device and start packet capture */
    handle = pcap_open_live(device, BUFSIZ, 0, timeoutLimit, errorBuffer);
    if (!handle) {
        printf("Error opening device: %s\n", errorBuffer);
        exit(1);
    }

    /* Set packet capture filter */
    struct bpf_program filter;
    char filterString[] = "tcp and port 80";
    if (pcap_compile(handle, &filter, filterString, 0, 0) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    /* Start packet capture loop */
    pcap_loop(handle, packetCountLimit, packetHandler, NULL);

    /* Clean up */
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    struct ether_header *ethHeader;
    struct ip *ipHeader;
    struct tcphdr *tcpHeader;
    unsigned short etherType;

    /* Parse Ethernet header */
    ethHeader = (struct ether_header*) packet;
    etherType = ntohs(ethHeader->ether_type);

    /* If IP packets */
    if (etherType == ETHERTYPE_IP) {

        /* Parse IP header */
        ipHeader = (struct ip*) (packet + sizeof(struct ether_header));

        /* If TCP packets */
        if (ipHeader->ip_p == IPPROTO_TCP) {

            /* Parse TCP header */
            tcpHeader = (struct tcphdr*) (packet + sizeof(struct ether_header) + sizeof(struct ip));
            unsigned short sourcePort = ntohs(tcpHeader->th_sport);
            unsigned short destinationPort = ntohs(tcpHeader->th_dport);

            /* If port 80 */
            if (sourcePort == 80 || destinationPort == 80) {
                printf("\n\n\n************************************************\n");
                printf("Packet captured at %ld.%ld\n", pkthdr->ts.tv_sec, pkthdr->ts.tv_usec);
                printf("Ethernet Address: %s -> %s\n",
                       ether_ntoa((struct ether_addr*) ethHeader->ether_shost),
                       ether_ntoa((struct ether_addr*) ethHeader->ether_dhost));
                printf("IP Address: %s -> %s\n",
                       inet_ntoa(ipHeader->ip_src),
                       inet_ntoa(ipHeader->ip_dst));
                printf("Source/Destination Port: %d -> %d\n", sourcePort, destinationPort);
                printf("************************************************\n\n\n");
            }
        }
    }
}