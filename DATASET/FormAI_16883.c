//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netinet/tcp.h>
#include<netinet/ip.h>

#define TRUE 1
#define FALSE 0
#define BUFSIZE 65536

int sock_raw;
FILE *logfile;
int tcp=0,udp=0,icmp=0,others=0,iphdrlen;

void print_packet(unsigned char*,int);
void process_packet(unsigned char * , int);

int main()
{
    int saddr_size , data_size;
    struct sockaddr saddr;

    unsigned char *buffer = (unsigned char *) malloc(BUFSIZE);

    if (!buffer)
    {
        perror("Buffer error");
        exit(1);
    }

    logfile=fopen("log.txt","w");
    if(!logfile)
    {
        perror("Log file creation error");
        exit(1);
    }

    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);

    if(sock_raw < 0)
    {
        perror("Socket Error");
        exit(1);
    }

    while(TRUE)
    {
        saddr_size = sizeof(saddr);

        data_size = recvfrom(sock_raw , buffer , BUFSIZE , 0 , &saddr , (socklen_t*)&saddr_size);

        if(data_size <0 )
        {
            perror("Recvfrom error ");
            exit(1);
        }

        process_packet(buffer , data_size);
    }

    close(sock_raw);

    return 0;
}

void process_packet(unsigned char* buffer, int size)
{
    struct iphdr *iph = (struct iphdr*)buffer;
    iphdrlen = iph->ihl*4;

    switch (iph->protocol)
    {
        case 6:
            ++tcp;
            break;

        case 17:
            ++udp;
            break;

        case 1:
            ++icmp;
            break;

        default:
            ++others;
            break;
    }

    print_packet(buffer, size);
}

void print_packet(unsigned char* buffer, int size)
{
    struct iphdr *iph = (struct iphdr*)buffer;

    switch (iph->protocol)
    {
        case 6:
            fprintf(logfile , "TCP Packet\n");
            break;

        case 17:
            fprintf(logfile , "UDP Packet\n");
            break;

        case 1:
            fprintf(logfile , "ICMP Packet\n");
            break;

        default:
            fprintf(logfile , "Other Protocol Packet\n");
            break;
    }

    fprintf(logfile , "--------------------------\n");

    fprintf(logfile , "IP Header\n");
    fprintf(logfile , "   |-IP Version        : %d\n",(unsigned int)iph->version);
    fprintf(logfile , "   |-IP Header Length  : %d DWORDS or %d Bytes\n",(unsigned int)iph->ihl,((unsigned int)(iph->ihl))*4);
    fprintf(logfile , "   |-Type Of Service   : %d\n",(unsigned int)iph->tos);
    fprintf(logfile , "   |-IP Total Length   : %d  Bytes(Size of Packet)\n",ntohs(iph->tot_len));
    fprintf(logfile , "   |-Identification    : %d\n",ntohs(iph->id));
    fprintf(logfile , "   |-TTL      : %d\n",(unsigned int)iph->ttl);
    fprintf(logfile , "   |-Protocol : %d\n",(unsigned int)iph->protocol);
    fprintf(logfile , "   |-Checksum : %d\n",ntohs(iph->check));
    fprintf(logfile , "   |-Source IP        : %s\n",inet_ntoa(*(struct in_addr*)&iph->saddr));
    fprintf(logfile , "   |-Destination IP   : %s\n",inet_ntoa(*(struct in_addr*)&iph->daddr));

    fprintf(logfile , "\n");

    unsigned short iphdrlen = iph->ihl*4;
    struct tcphdr *tcph=(struct tcphdr*)(buffer + iphdrlen);

    fprintf(logfile , "TCP Header\n");
    fprintf(logfile , "   |-Source Port      : %u\n",ntohs(tcph->source));
    fprintf(logfile , "   |-Destination Port : %u\n",ntohs(tcph->dest));
    fprintf(logfile , "   |-Sequence Number    : %u\n",ntohl(tcph->seq));
    fprintf(logfile , "   |-Acknowledgement Number : %u\n",ntohl(tcph->ack_seq));
    fprintf(logfile , "   |-Header Length      : %d DWORDS or %d BYTES\n" ,(unsigned int)tcph->doff,(unsigned int)tcph->doff*4);
    fprintf(logfile , "   |-Urgent Flag          : %d\n",(unsigned int)tcph->urg);
    fprintf(logfile , "   |-Acknowledge Flag     : %d\n",(unsigned int)tcph->ack);
    fprintf(logfile , "   |-Push Flag            : %d\n",(unsigned int)tcph->psh);
    fprintf(logfile , "   |-Reset Flag           : %d\n",(unsigned int)tcph->rst);
    fprintf(logfile , "   |-Synchronise Flag     : %d\n",(unsigned int)tcph->syn);
    fprintf(logfile , "   |-Finish Flag          : %d\n",(unsigned int)tcph->fin);
    fprintf(logfile , "   |-Window         : %d\n",ntohs(tcph->window));
    fprintf(logfile , "   |-Checksum       : %d\n",ntohs(tcph->check));
    fprintf(logfile , "   |-Urgent Pointer : %d\n",tcph->urg_ptr);
    fprintf(logfile , "\n");
    fprintf(logfile, "\n#######################################################################################################\n\n");

    fflush(logfile);
}