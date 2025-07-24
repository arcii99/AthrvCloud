//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);
void print_payload(const u_char *, int);

int main(int argc, char const *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 net, mask;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count_limit = 10; /* number of packets to capture */
    int timeout_limit_ms = 100; /* capture timeout in milliseconds */
    int result;

    /* check command line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    dev = (char *)argv[1];

    /* get network number and mask associated with capture device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* open capture device */
    handle = pcap_open_live(dev, BUFSIZ, 1, timeout_limit_ms, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    /* compile the filter expression */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* apply the compiled filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* now we can set our callback function */
    pcap_loop(handle, packet_count_limit, process_packet, NULL);

    /* cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("\nDone.\n");
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1; /* packet counter */
    const struct ip *ip_hdr; /* The IP header */
    const struct tcphdr *tcp_hdr; /* The TCP header */
    int packet_len = header->len; /* Total packet length */
    int ip_hdr_len = sizeof(struct ip);
    int tcp_hdr_len, payload_len;
    const u_char *payload;
    u_short sport, dport;

    /* print packet number */
    printf("\nPacket number %d:\n", count);
    count++;

    /* print timestamp */
    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));

    /* print packet length */
    printf("Packet length: %d bytes\n", packet_len);

    /* print source and destination IP addresses */
    ip_hdr = (const struct ip *)packet;
    printf("Source IP address: %s\n", inet_ntoa(ip_hdr->ip_src));
    printf("Destination IP address: %s\n", inet_ntoa(ip_hdr->ip_dst));

    /* print source and destination port numbers */
    tcp_hdr = (const struct tcphdr *)(packet + ip_hdr_len);
    sport = ntohs(tcp_hdr->source);
    dport = ntohs(tcp_hdr->dest);
    printf("Source port number: %hu\n", sport);
    printf("Destination port number: %hu\n", dport);

    /* print TCP flags */
    printf("TCP flags: ");
    if (tcp_hdr->syn) printf("SYN ");
    if (tcp_hdr->ack) printf("ACK ");
    if (tcp_hdr->fin) printf("FIN ");
    if (tcp_hdr->rst) printf("RST ");
    printf("\n");

    /* calculate payload (application data) offset and length */
    tcp_hdr_len = tcp_hdr->doff * 4;
    payload = packet + ip_hdr_len + tcp_hdr_len;
    payload_len = packet_len - ip_hdr_len - tcp_hdr_len;
    if (payload_len > 0) {
        printf("Payload (application data):\n");
        print_payload(payload, payload_len);
    }
}

void print_payload(const u_char *payload, int payload_len) {
    int len_rem = payload_len;
    int line_width = 16; /* number of bytes per line */
    int line_len;
    int offset = 0;
    const u_char *ch = payload;

    if (payload_len <= 0)
        return;

    /* data fits on one line */
    if (payload_len <= line_width) {
        printf("%06x: ", offset);
        for (int i = 0; i < payload_len; i++) {
            printf("%02x ", *ch);
            ch++;
        }
        printf("\n");
        return;
    }

    /* data spans multiple lines */
    for (;;) {
        /* compute current line length */
        line_len = line_width % len_rem;

        /* print line */
        printf("%06x: ", offset);
        for (int i = 0; i < line_len; i++) {
            printf("%02x ", *ch);
            ch++;
        }
        printf("\n");

        /* shift pointers to next line */
        offset += line_width;
        len_rem -= line_len;
        if (len_rem <= 0) {
            break;
        }
    }
    return;
}