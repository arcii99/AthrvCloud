//FormAI DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_RULES 10

struct rule {
    char src_ip[16]; // Source IP address
    char dst_ip[16]; // Destination IP address
    int src_port;    // Source port
    int dst_port;    // Destination port
    char protocol[10]; // Protocol type (TCP/UDP/ICMP)
    int action;      // 1-Allow | 0-Deny
};

// Initialize firewall rules
struct rule firewall[MAX_RULES];

int main() {
    int sock_raw, udp_socket, saddr_size , data_size;
    struct sockaddr_in saddr, daddr;
    char buffer[MAX_BUFFER_SIZE];
    unsigned char *packet;
    int i;

    // Initialize the firewall rules
    for(i=0;i<MAX_RULES;i++) {
        strcpy(firewall[i].src_ip, "0.0.0.0");
        strcpy(firewall[i].dst_ip, "0.0.0.0");
        firewall[i].src_port = 0;
        firewall[i].dst_port = 0;
        strcpy(firewall[i].protocol, "ALL");
        firewall[i].action = 0;
    }

    // Add firewall rules
    strcpy(firewall[0].dst_ip, "10.0.0.2");
    strcpy(firewall[0].protocol, "UDP");
    firewall[0].dst_port = 53;
    firewall[0].action = 1;

    strcpy(firewall[1].dst_ip, "10.0.0.2");
    strcpy(firewall[1].protocol, "TCP");
    firewall[1].dst_port = 22;
    firewall[1].action = 1;

    // Create a raw socket to receive packets
    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_UDP);

    // Create a UDP socket for sending packets
    udp_socket = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);

    if(sock_raw < 0) {
        printf("Socket Error\n");
        return 1;
    }

    if (setsockopt(sock_raw, SOL_SOCKET, SO_BINDTODEVICE, "eth0", sizeof("eth0")) == -1) {
        printf("Socket Bind Error\n");
        return 1;
    }

    saddr_size = sizeof(saddr);

    while(1) {
        memset(buffer,0,MAX_BUFFER_SIZE);
        data_size = recvfrom(sock_raw , buffer , MAX_BUFFER_SIZE , 0 , (struct sockaddr *)&saddr , &saddr_size);

        // Parse the IP and transport layer headers
        unsigned char *ip_head = buffer;
        unsigned char *trans_head = buffer + (ip_head[0] & 0xf) * 4;
        char src_ip[16], dst_ip[16];
        struct in_addr src_in_addr, dst_in_addr;
        src_in_addr.s_addr = *((unsigned int*)(ip_head + 12));
        dst_in_addr.s_addr = *((unsigned int*)(ip_head + 16));
        strcpy(src_ip, inet_ntoa(src_in_addr));
        strcpy(dst_ip, inet_ntoa(dst_in_addr));
        int protocol = ip_head[9];
        int src_port = 0, dst_port = 0;
        if(protocol == IPPROTO_UDP) {
            src_port = ntohs(*((unsigned short *)(trans_head)));
            dst_port = ntohs(*((unsigned short *)(trans_head+2)));
        }
        else if(protocol == IPPROTO_TCP) {
            src_port = ntohs(*((unsigned short *)(trans_head)));
            dst_port = ntohs(*((unsigned short *)(trans_head+2)));
        }
        else if(protocol == IPPROTO_ICMP) {
            // TODO: Handle ICMP packets
        }

        // Determine if the packet should be allowed or denied
        int action = 0;
        for(i=0;i<MAX_RULES;i++) {
            if(strcmp(firewall[i].protocol, "ALL") == 0 || strcmp(firewall[i].protocol, protocol == IPPROTO_TCP ? "TCP" : protocol == IPPROTO_UDP ? "UDP" : "ICMP") == 0) {
                if(strcmp(firewall[i].src_ip, "0.0.0.0") == 0 || strcmp(firewall[i].src_ip, src_ip) == 0) {
                    if(strcmp(firewall[i].dst_ip, "0.0.0.0") == 0 || strcmp(firewall[i].dst_ip, dst_ip) == 0) {
                        if(firewall[i].src_port == 0 || firewall[i].src_port == src_port) {
                            if(firewall[i].dst_port == 0 || firewall[i].dst_port == dst_port) {
                                action = firewall[i].action;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if(action == 1) {
            // Packet is allowed
            if(protocol == IPPROTO_UDP) {
                // Forward the UDP packet to the destination
                udp_socket = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);
                daddr.sin_family = AF_INET;
                daddr.sin_addr.s_addr = inet_addr(dst_ip);
                daddr.sin_port = htons(dst_port);
                sendto(udp_socket, buffer, data_size, 0, (struct sockaddr *)&daddr, sizeof(daddr));
                close(udp_socket);
            }
            else if(protocol == IPPROTO_TCP) {
                // TODO: Handle TCP packets
            }
            else if(protocol == IPPROTO_ICMP) {
                // TODO: Handle ICMP packets
            }
        }
        else {
            // Packet is blocked
            printf("Packet blocked from %s to %s (%s)\n", src_ip, dst_ip, protocol == IPPROTO_TCP ? "TCP" : protocol == IPPROTO_UDP ? "UDP" : "ICMP");
        }
    }

    return 0;
}