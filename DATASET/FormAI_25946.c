//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <pcap.h>
#include <stdio.h>

/* Define a struct for IP header */
typedef struct ip_hdr {
    unsigned char ip_vhl; 
    unsigned char ip_tos; 
    unsigned short ip_len; 
    unsigned short ip_id; 
    unsigned short ip_off; 
    unsigned char ip_ttl; 
    unsigned char ip_p; 
    unsigned short ip_sum; 
    unsigned int ip_src,ip_dst; 
} ip_hdr;

/* Define a struct for TCP header */
typedef struct tcp_hdr {
    unsigned short th_sport; 
    unsigned short th_dport; 
    unsigned int th_seq; 
    unsigned int th_ack; 
    unsigned char th_offx2; 
    unsigned char th_flags; 
    unsigned short th_win; 
    unsigned short th_sum; 
    unsigned short th_urp; 
} tcp_hdr;

/* Define a callback function */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    ip_hdr *ih;
    tcp_hdr *th;
    unsigned int ip_len;
    unsigned short sport,dport;
    struct tm *timeinfo;
    char timestr[16];
    time_t local_tv_sec;

    /* Convert the timestamp to readable format */
    local_tv_sec = header->ts.tv_sec;
    timeinfo = localtime(&local_tv_sec);
    strftime(timestr, sizeof timestr, "%H:%M:%S", timeinfo);
   
    /* Get the IP header */
    ih = (ip_hdr *)(pkt_data + 14); 
    /* Get the TCP header */
    th = (tcp_hdr *)(pkt_data + 14 + sizeof(ip_hdr));

    /* Calculate IP length */
    ip_len = (ih->ip_vhl & 0xf) * 4;

    /* Get the source and destination ports */
    sport = ntohs(th->th_sport);
    dport = ntohs(th->th_dport);

    /* Print packet information */
    printf("%s Src IP: %d.%d.%d.%d  Dst IP: %d.%d.%d.%d  Src Port: %d  Dst Port: %d\n", 
            timestr, 
            (ih->ip_src>>24)&0xff, (ih->ip_src>>16)&0xff, (ih->ip_src>>8)&0xff, ih->ip_src&0xff,
            (ih->ip_dst>>24)&0xff, (ih->ip_dst>>16)&0xff, (ih->ip_dst>>8)&0xff, ih->ip_dst&0xff,
            sport, dport); 
}

int main(int argc, char **argv)
{
    char *dev;      /* Device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE];  /* Error buffer */
    pcap_t *handle; /* Session handle */
    bpf_u_int32 mask;   /* The netmask of our sniffing device */
    bpf_u_int32 net;    /* The IP of our sniffing device */
    struct bpf_program filter;  /* The compiled filter expression */

    /* Find a capture device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    /* Get the network address and netmask of the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", dev);
        net = 0;
        mask = 0;
    }

    /* Open the capture device */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* Compile and apply the filter expression */
    if (pcap_compile(handle, &filter, "tcp", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "tcp", pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "tcp", pcap_geterr(handle));
        return(2);
    }

    printf("Listening on %s...\n", dev);

    /* Enter the main loop */
    pcap_loop(handle, -1, packet_handler, NULL);

    /* Clean up */
    pcap_freecode(&filter);
    pcap_close(handle);

    return(0);
}