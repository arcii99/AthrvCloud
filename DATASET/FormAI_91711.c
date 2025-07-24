//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* define default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 65535

/* define Ethernet header struct */
struct eth_header {
    u_char ether_dhost[6];
    u_char ether_shost[6];
    u_short ether_type;
};

/* define IP header struct */
struct ip_header {
    u_char ip_vhl;          /* version << 4 | header length >> 2 */
    u_char ip_tos;          /* type of service */
    u_short ip_len;         /* total length */
    u_short ip_id;          /* identification */
    u_short ip_off;         /* fragment offset field */
#define IP_RF 0x8000        /* reserved fragment flag */
#define IP_DF 0x4000        /* dont fragment flag */
#define IP_MF 0x2000        /* more fragments flag */
#define IP_OFFMASK 0x1fff   /* mask for fragmenting bits */
    u_char ip_ttl;          /* time to live */
    u_char ip_p;            /* protocol */
    u_short ip_sum;         /* checksum */
    struct in_addr ip_src,ip_dst; /* source and dest address */
};

/* define TCP header struct */
typedef u_int tcp_seq;

struct tcp_header {
    u_short th_sport;	/* source port */
    u_short th_dport;	/* destination port */
    tcp_seq th_seq;		/* sequence number */
    tcp_seq th_ack;		/* acknowledgement number */
    u_char th_offx2;	/* data offset, rsvd */
#define TH_OFF(th)	(((th)->th_offx2 & 0xf0) >> 4)
    u_char th_flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x04
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
    u_short th_win;		/* window */
    u_short th_sum;		/* checksum */
    u_short th_urp;		/* urgent pointer */
};

/* define function to parse packet */
void parse_packet(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct eth_header *eth_hdr; // Ethernet header
    struct ip_header *ip_hdr;   // IP header
    struct tcp_header *tcp_hdr; // TCP header
    const char *payload; // Packet payload
    int payload_size; // Size of payload

    /* define ethernet header */
    eth_hdr = (struct eth_header *) (packet);

    /* define IP header */
    ip_hdr = (struct ip_header *) (packet + sizeof(struct eth_header));

    /* define TCP header */
    tcp_hdr = (struct tcp_header *) (packet + sizeof(struct eth_header) + sizeof(struct ip_header));

    /* define size of payload */
    payload_size = pkthdr->len - (sizeof(struct eth_header) + sizeof(struct ip_header) + sizeof(struct tcp_header));

    /* define payload */
    payload = (const char *) (packet + sizeof(struct eth_header) + sizeof(struct ip_header) + sizeof(struct tcp_header));

    /* print packet data */
    printf("\nPacket captured:\n");
    printf("\tSource MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", eth_hdr->ether_shost[0], eth_hdr->ether_shost[1], eth_hdr->ether_shost[2], eth_hdr->ether_shost[3], eth_hdr->ether_shost[4], eth_hdr->ether_shost[5]);
    printf("\tDestination MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", eth_hdr->ether_dhost[0], eth_hdr->ether_dhost[1], eth_hdr->ether_dhost[2], eth_hdr->ether_dhost[3], eth_hdr->ether_dhost[4], eth_hdr->ether_dhost[5]);
    printf("\tSource IP: %s\n", inet_ntoa(ip_hdr->ip_src));
    printf("\tDestination IP: %s\n", inet_ntoa(ip_hdr->ip_dst));
    printf("\tSource Port: %d\n", ntohs(tcp_hdr->th_sport));
    printf("\tDestination Port: %d\n", ntohs(tcp_hdr->th_dport));
    printf("\tPayload: %.*s\n", payload_size, payload);
}

int main(int argc, char **argv) {
    char *dev = NULL;           /* capture device name */
    char errbuf[PCAP_ERRBUF_SIZE];  /* error buffer */
    pcap_t *handle;             /* packet capture handle */

    /* define pcap filter string */
    char filter_exp[] = "tcp port 80";

    /* define pcap capture buffer size */
    int buffer_size = 100;

    /* define pcap timeout (in milliseconds) */
    int timeout_ms = 100;

    /* find a capture device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(EXIT_FAILURE);
    }

    /* open capture device */
    handle = pcap_open_live(dev, SNAP_LEN, 1, timeout_ms, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(EXIT_FAILURE);
    }

    /* compile filter expression */
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    /* apply compiled filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    /* start packet capture loop */
    pcap_loop(handle, buffer_size, parse_packet, NULL);

    /* cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("\nPacket capture complete.\n");

    return(EXIT_SUCCESS);
}