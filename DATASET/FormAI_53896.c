//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 65536

int main(int argc, char const *argv[]) {

    //Create a raw socket to read incoming packets
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock_raw == -1){
        printf("Error creating socket\n");
        return 1;
    }

    //Buffer to hold incoming packets
    unsigned char buffer[BUFFER_SIZE];

    //Loop to continuously read incoming packets
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);

        int data_size = recv(sock_raw, buffer, BUFFER_SIZE, 0);
        if(data_size == -1){
            printf("Error receiving data\n");
            continue;
        }

        //Extract the IP header
        struct iphdr* iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));

        //If the packet is not an IP packet, continue to the next packet
        if(iph->version != 4){
            continue;
        }

        //Extract the transport protocol header
        struct tcphdr* tcph = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));

        //If the protocol is not TCP, continue to the next packet
        if(tcph->th_flags != TH_SYN){
            continue;
        }

        //Extract the source and destination IP addresses
        struct sockaddr_in source, dest;
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = iph->saddr;
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = iph->daddr;

        //Print information about the incoming packet
        printf("Packet received from %s:%d to %s:%d\n", inet_ntoa(source.sin_addr), ntohs(tcph->source), inet_ntoa(dest.sin_addr), ntohs(tcph->dest));
    }

    return 0;
}