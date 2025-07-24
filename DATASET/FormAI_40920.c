//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_PACKET_SIZE 65535

// Function to calculate checksum
unsigned short CalculateChecksum(unsigned short *ptr,int nbytes) 
{
    register long sum = 0;   // variable to store the sum

    // summing up 16 bits chunks of the data
    while (nbytes > 1) 
    {
        sum += *ptr++;     // adding the 16 bits value to sum
        nbytes -= 2;       // decrementing the size of data
    }

    // if we have odd number of bytes in data
    if (nbytes == 1) 
    {
        sum += *(unsigned char*)ptr;   // adding the final byte value
    }

    // the final calculation using carry-over
    sum = (sum >> 16) + (sum & 0xffff);  // adding the overflow to lower 16 bits
    sum += (sum >> 16);                  // adding any further carry-over
    return (unsigned short)(~sum);       // 1's complement of sum
}

// Structure for IP header
typedef struct IPHeader
{
    unsigned char      iph_ihl:4, // IP header length
                       iph_ver:4, // IP version
                       iph_tos;   // IP type of service
    unsigned short int iph_len;    // IP packet length (data+header)
    unsigned short int iph_ident;  // identification
    unsigned short int iph_flag:3, // fragmentation flags
                       iph_offset:13; // last fragment field
    unsigned char      iph_ttl;    // time to live
    unsigned char      iph_protocol; // datagram protocol type
    unsigned short int iph_chksum;   // IP header checksum
    struct  in_addr    iph_sourceip; // IP Address of Source
    struct  in_addr    iph_destip;   // IP Address of Destination
}IPHeader;

// Function to create a raw socket to read network packets
int CreateRawSocket(int protocol_to_sniff)
{
    int rawsock;
    if((rawsock = socket(AF_INET , SOCK_RAW , protocol_to_sniff)) == -1)  // creating a raw socket
    {
        perror("Error while creating socket");
        exit(EXIT_FAILURE);
    }
    return rawsock;
}

int main(int argc, char *argv[])
{
    if(argc == 1)  // if no argument is passed
    {
        printf("Please specify an IP Address.\n");
        exit(EXIT_FAILURE);
    }
    
    // Creating a raw socket to read networks packets
    int rawsocket = CreateRawSocket(IPPROTO_TCP);

    // setting the options for the socket
    int enable = 1;
    if (setsockopt(rawsocket, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable)) < 0) 
    {
        perror("Error in setsockopt()");
        exit(EXIT_FAILURE);
    }
    
    // Setting the IP Addresses for scanning
    struct in_addr dest_addr;
    if(inet_pton(AF_INET, argv[1], &dest_addr)<=0) 
    {
        perror("Invalid Destination IP Address.");
        exit(EXIT_FAILURE);
    }
    struct in_addr src_addr = {0};
    
    // Filling the IP Header
    IPHeader iphdr;
    memset(&iphdr, 0, sizeof(IPHeader));  // setting everything to zero
    iphdr.iph_ihl = 5;               // setting IP header length
    iphdr.iph_ver = 4;               // setting IP version
    iphdr.iph_ttl = 255;             // setting TTL to 255
    iphdr.iph_protocol = IPPROTO_TCP; // setting protocol type
    
    // filling the source and destination IP addresses
    iphdr.iph_sourceip = src_addr;
    iphdr.iph_destip = dest_addr;
    
    // Total data length = IP Header + Data
    iphdr.iph_len = htons(sizeof(IPHeader));
    
    // calculating checksum of IP Header
    iphdr.iph_chksum = CalculateChecksum((unsigned short *)&iphdr, sizeof(IPHeader));
    
    // Sending packets to detect open TCP Port
    int i;
    for(i=1; i<=65535; i++)
    {
        int sfd;
        if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)  // creating a TCP socket
        {
            perror("Error while creating Socket!");
            exit(EXIT_FAILURE);
        }

        // setting the timeout structure
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        // setting the time out on the socket
        if(setsockopt(sfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
        {
            perror("Error in setsockopt()");
            exit(EXIT_FAILURE);
        }
        
        // setting the Destination Address structure and port number
        struct sockaddr_in dest_addr;                          
        memset(&dest_addr, 0, sizeof(struct sockaddr_in));
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
        dest_addr.sin_port = htons(i);
        
        // connecting to the desired port on the remote server
        if(connect(sfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) >= 0)
        {
            printf("Port %d is open.\n", i);
        }
        close(sfd);   // closing the TCP socket
    }
    return 0;
}