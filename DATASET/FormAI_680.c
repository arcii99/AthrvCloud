//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packetHandler(unsigned char *buffer, int size);
void printTCPHeader(unsigned char *buffer, int size);
void printUDPHeader(unsigned char *buffer, int size);

int main()
{
    int socketDescriptor, readSize;
    struct sockaddr_in serverAddress;
    unsigned char buffer[4096];

    // Create a socket
    socketDescriptor = socket(AF_INET, SOCK_RAW, IPPROTO_TCP); 
    if (socketDescriptor < 0)
    {
        perror("Socket could not be created.");
        return 1;
    }
    printf("Socket was successfully created\n");

    // Set server address
    serverAddress.sin_family = AF_INET;      
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
    serverAddress.sin_port = htons(10000);     

    // Bind socket to address and port
    if (bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Bind failed.");
        return 1;
    }
    printf("Bind was successful... Waiting for incoming packets\n");

    // Begin packet capturing loop
    while(1)
    {
        readSize = recvfrom(socketDescriptor, buffer, 4096, 0, NULL, NULL);
        if (readSize < 0)
        {
            perror("Receive failed.");
            return 1;
        }
        // Analyze and print packet information
        packetHandler(buffer, readSize);
    }

    // Close socket
    close(socketDescriptor);
    return 0;
}

void packetHandler(unsigned char *buffer, int size)
{
    struct iphdr *ipHeader;
    ipHeader = (struct iphdr*) buffer;
    
    switch(ipHeader->protocol) 
    {
        case IPPROTO_TCP:
            printTCPHeader(buffer, size);
            break;
         
        case IPPROTO_UDP:
            printUDPHeader(buffer, size);
            break;
             
        default:
            break;
    }
}

void printTCPHeader(unsigned char *buffer, int size) 
{
    unsigned short ipHeaderLength;
    struct iphdr *ipHeader;
    struct tcphdr *tcpHeader;
    
    ipHeader = (struct iphdr *) buffer;
    ipHeaderLength = ipHeader->ihl*4;
            
    tcpHeader = (struct tcphdr *)(buffer + ipHeaderLength);
    printf("\n***TCP Packet***\n");
    printf("Source Port: %u\n", ntohs(tcpHeader->source));
    printf("Destination Port: %u\n", ntohs(tcpHeader->dest));
    printf("Sequence Number: %u\n", ntohl(tcpHeader->seq));
    printf("Acknowledge Number: %u\n", ntohl(tcpHeader->ack_seq));
    printf("Header Length : %d\n", tcpHeader->doff*4);
    printf("Urgent Flag : %d\n", tcpHeader->urg);
    printf("Acknowledgement Flag : %d\n", tcpHeader->ack);
    printf("Push Flag : %d\n", tcpHeader->psh);
    printf("Reset Flag : %d\n", tcpHeader->rst);
    printf("Synchronise Flag : %d\n", tcpHeader->syn);
    printf("Finish Flag : %d\n", tcpHeader->fin);
    
}

void printUDPHeader(unsigned char *buffer, int size)
{
    unsigned short ipHeaderLength;
    struct iphdr *ipHeader;
    struct udphdr *udpHeader;
    
    ipHeader = (struct iphdr *) buffer;
    ipHeaderLength = ipHeader->ihl*4;
    
    udpHeader = (struct udphdr *)(buffer + ipHeaderLength);
    printf("\n***UDP Packet***\n");
    printf("Source Port: %u\n", ntohs(udpHeader->source));
    printf("Destination Port: %u\n", ntohs(udpHeader->dest));
    printf("Length: %d\n", ntohs(udpHeader->len));
}