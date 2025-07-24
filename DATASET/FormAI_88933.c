//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

void capturer_callback(u_char *args, const struct pcap_pkthdr* pkthdr, const u_char* packet){
    static int count = 0;
    const struct ether_header* ethernet_header;
    const struct iphdr* ip_header;
    const struct tcphdr* tcp_header;
    const struct udphdr* udp_header;
    const u_char* payload;

    int size_ethernet = sizeof(struct ether_header);
    ethernet_header = (struct ether_header*) packet;
    if(ntohs(ethernet_header->ether_type) == ETHERTYPE_IP){
        ip_header = (struct iphdr*) (packet + size_ethernet);
        if(ip_header->protocol == IPPROTO_TCP){
            tcp_header = (struct tcphdr*) (packet + size_ethernet + sizeof(struct iphdr));
            payload = (u_char*) (packet + size_ethernet + sizeof(struct iphdr) + sizeof(struct tcphdr));
            printf("Packet number %d:\n", ++count);
            printf("\tSource MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    ethernet_header->ether_shost[0], ethernet_header->ether_shost[1],
                    ethernet_header->ether_shost[2], ethernet_header->ether_shost[3],
                    ethernet_header->ether_shost[4], ethernet_header->ether_shost[5]);
            printf("\tDestination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    ethernet_header->ether_dhost[0], ethernet_header->ether_dhost[1],
                    ethernet_header->ether_dhost[2], ethernet_header->ether_dhost[3],
                    ethernet_header->ether_dhost[4], ethernet_header->ether_dhost[5]);
            printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr*) &ip_header->saddr));
            printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr*) &ip_header->daddr));
            printf("\tSource port: %d\n", ntohs(tcp_header->source));
            printf("\tDestination port: %d\n", ntohs(tcp_header->dest));
            printf("\tPayload:\n");
            printf("\t\t");
            int payload_size = ntohs(ip_header->tot_len) - (size_ethernet + sizeof(struct iphdr) + sizeof(struct tcphdr));
            for(int i = 0; i < payload_size; i++){
                if(i % 16 == 0 && i != 0){
                    printf("\n\t\t");
                }
                printf("%02x ", payload[i]);
            }
            printf("\n\n");
        }
        else if(ip_header->protocol == IPPROTO_UDP){
            udp_header = (struct udphdr*) (packet + size_ethernet + sizeof(struct iphdr));
            payload = (u_char*) (packet + size_ethernet + sizeof(struct iphdr) + sizeof(struct udphdr));
            printf("Packet number %d:\n", ++count);
            printf("\tSource MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    ethernet_header->ether_shost[0], ethernet_header->ether_shost[1],
                    ethernet_header->ether_shost[2], ethernet_header->ether_shost[3],
                    ethernet_header->ether_shost[4], ethernet_header->ether_shost[5]);
            printf("\tDestination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    ethernet_header->ether_dhost[0], ethernet_header->ether_dhost[1],
                    ethernet_header->ether_dhost[2], ethernet_header->ether_dhost[3],
                    ethernet_header->ether_dhost[4], ethernet_header->ether_dhost[5]);
            printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr*) &ip_header->saddr));
            printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr*) &ip_header->daddr));
            printf("\tSource port: %d\n", ntohs(udp_header->source));
            printf("\tDestination port: %d\n", ntohs(udp_header->dest));
            printf("\tPayload:\n");
            printf("\t\t");
            int payload_size = ntohs(ip_header->tot_len) - (size_ethernet + sizeof(struct iphdr) + sizeof(struct udphdr));
            for(int i = 0; i < payload_size; i++){
                if(i % 16 == 0 && i != 0){
                    printf("\n\t\t");
                }
                printf("%02x ", payload[i]);
            }
            printf("\n\n");
        }
    }
}

int main(){
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp or udp";
    bpf_u_int32 subnet_mask, ip_address;

    if(pcap_lookupnet("eth0", &ip_address, &subnet_mask, errbuf) == -1){
        printf("Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL){
        printf("Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if(pcap_compile(handle, &fp, filter_exp, 0, ip_address) == -1){
        printf("Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if(pcap_setfilter(handle, &fp) == -1){
        printf("Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, capturer_callback, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0; 
}