//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/tcp.h>
#include<netinet/ip.h>
#include<errno.h>

//This function will calculate checksum for the packet
unsigned short calculate_checksum(unsigned short *ptr,int nbytes){
    unsigned long sum=0;
    while(nbytes>1){
        sum+=*ptr++;
        nbytes-=2;
    }
    if(nbytes>0) sum+=*ptr;
    while(sum>>16) sum=(sum&0xffff)+(sum>>16);
    return (unsigned short)(~sum);
}

//Main function for packet sniffing and monitoring
int main(){
    int sock_raw, saddr_size, data_size, tcp=0, udp=0, icmp=0, others=0, total=0;
    struct sockaddr_in saddr;
    unsigned char *buffer=(unsigned char*)malloc(65536);
    memset(buffer,0,65536);

    //Creating Raw Socket to capture packets
    sock_raw=socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
    if(sock_raw==-1){
        printf("Error in creating socket: %d\n",errno);
        exit(1);
    }

    //Listening to traffic on all available interfaces
    while(1){
        saddr_size = sizeof saddr;
        data_size = recvfrom(sock_raw,buffer,65536,0,(struct sockaddr *)&saddr,(socklen_t *)&saddr_size);
        if(data_size<0){
            printf("Error in packet capture: %d\n",errno);
            return 1;
        }
        struct iphdr *iph=(struct iphdr*)buffer;
        if(iph->protocol == IPPROTO_TCP){
            tcp++;
            struct tcphdr *tcph=(struct tcphdr*)(buffer+(iph->ihl)*4);

            //Printing Packet details: Source and Destination IP, Protocol and Packet length
            printf("Packet Details:\n");
            printf("Source IP: %s\n",inet_ntoa(saddr.sin_addr));
            printf("Destination IP: %s\n",inet_ntoa((*(struct in_addr*) &iph->daddr)));
            printf("Protocol: TCP\n");
            printf("Packet Length: %d bytes\n",data_size);
            
            //Printing TCP Header Information
            printf("----------------------------------------------\n");
            printf("TCP Header:\n");
            printf("Source Port: %d\n",ntohs(tcph->source));
            printf("Destination Port: %d\n",ntohs(tcph->dest));
            
            //Calculating and Printing TCP Checksum
            printf("Checksum: ");
            unsigned short *tcpptr=(unsigned short*)(buffer+(iph->ihl)*4);
            int tcplen=(ntohs(iph->tot_len)-(iph->ihl*4));
            unsigned short tcpsrcaddr[2],tcpdestaddr[2];
            tcpsrcaddr[0]=saddr.sin_addr.s_addr >> 16;
            tcpsrcaddr[1]=saddr.sin_addr.s_addr & 0xffff;
            tcpdestaddr[0]=iph->daddr >> 16;
            tcpdestaddr[1]=iph->daddr & 0xffff;
            unsigned short int tcpchecksum;
            tcpchecksum = calculate_checksum(tcpptr,tcplen);
            printf("%04x\n",tcpchecksum);
            printf("----------------------------------------------\n\n");
        }
        else{
            others++;
            printf("Packet Details:\n");
            printf("Source IP: %s\n",inet_ntoa(saddr.sin_addr));
            printf("Destination IP: %s\n",inet_ntoa((*(struct in_addr*) &iph->daddr)));
            printf("Protocol: Others\n");
            printf("Packet Length: %d bytes\n",data_size);
        }
        total++;
    }
    close(sock_raw);
    printf("\nFinished\n");
    return 0;
}