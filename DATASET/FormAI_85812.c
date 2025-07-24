//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <linux/types.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define MAX_PACKET_SIZE 65535
#define MIN_PACKET_SIZE 28

u_int16_t csum (u_int16_t *buf, int nwords)
{       
        u_int32_t sum;
        for (sum = 0; nwords > 0; nwords--)
                sum += *buf++;
        sum = (sum >> 16) + (sum &0xffff);
        sum += (sum >> 16);
        return ~sum;
}

struct iphdr *create_ip_header(char *src, char *dst, int packet_size)
{
        struct iphdr *iph = malloc(sizeof(struct iphdr));
        iph->ihl = 5;
        iph->version = 4;
        iph->tos = 0;
        iph->tot_len = htons(packet_size);
        iph->id = htonl(rand()%65535);
        iph->frag_off = htons(0x4000);
        iph->ttl = 64;
        iph->protocol = IPPROTO_TCP;
        iph->check = 0;
        iph->saddr = inet_addr(src);
        iph->daddr = inet_addr(dst);
        iph->check = csum((unsigned short *) iph, sizeof(struct iphdr)/2);
        return iph;
}

struct tcphdr *create_tcp_header(int srcport, int dstport, int packet_size)
{
        struct tcphdr *th = malloc(sizeof(struct tcphdr));
        th->source = htons(srcport);
        th->dest = htons(dstport);
        th->seq = htonl(rand()%4294967295);
        th->ack_seq = 0;
        th->doff = 5;
        th->syn = 1;
        th->window = htons(65535);
        th->check = 0;
        th->urg_ptr = 0;
        th->urg = 0;
        th->psh = 0;
        th->rst = 0;
        th->fin = 0;
        th->ack = 0;
        th->res1 = 0;
        th->res2 = 0;
        th->check = csum((unsigned short *) th,sizeof(struct tcphdr)/2);
        return th;
}

int main(int argc, char **argv)
{
        //check arguments
        if(argc < 3)
        {
                fprintf(stderr, "usage: %s src_ip dst_ip [src_port] [dst_port] [packet_size]\n", argv[0]);
                return 1;
        }

        //initialize packet parameters
        char *src_ip = argv[1];
        char *dst_ip = argv[2];
        int src_port = argc>3 ? atoi(argv[3]) : rand()%65535;
        int dst_port = argc>4 ? atoi(argv[4]) : rand()%65535;
        int packet_size = argc>5 ? atoi(argv[5]) : MIN_PACKET_SIZE;

        //setup socket
        int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
        if(sock<0)
        {
                perror("socket creation");
                return 1;
        }
        int one = 1;
        if(setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one))<0)
        {
                perror("setsockopt");
                return 1;
        }

        //create packet
        char *packet = malloc(MAX_PACKET_SIZE);
        memset(packet, 0, MAX_PACKET_SIZE);
        struct iphdr *iph = create_ip_header(src_ip, dst_ip, packet_size);
        struct tcphdr *tcph = create_tcp_header(src_port, dst_port, packet_size - sizeof(struct iphdr));
        memcpy(packet, iph, sizeof(struct iphdr));
        memcpy(packet + sizeof(struct iphdr), tcph, sizeof(struct tcphdr));
        iph->tot_len = htons(packet_size);
        iph->check = csum((unsigned short *) iph, sizeof(struct iphdr)/2);

        //start sending packets
        long start_time = time(NULL);
        long last_capture_time = start_time;
        long total_bytes = 0;
        while(1)
        {
                if(send(sock, packet, packet_size, 0)<0)
                {
                        perror("sendto");
                        return 1;
                }
                total_bytes += packet_size;

                //capture traffic stats every 5 seconds
                if(time(NULL) - last_capture_time > 5)
                {
                        last_capture_time = time(NULL);
                        printf("QoS: %ld bytes/s\n", total_bytes/(last_capture_time-start_time));
                }
        }

        return 0;
}