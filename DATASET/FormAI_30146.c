//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <pcap.h>
#include <stdio.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open a live capture session on the first available network device
    pcap_t *handle = pcap_open_live(pcap_lookupdev(errbuf), BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Couldn't open device: %s\n", errbuf);
        return 1;
    }

    // Set a filter to capture only ICMP packets
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net, mask;

    if (pcap_lookupnet(pcap_lookupdev(errbuf), &net, &mask, errbuf) == -1)
    {
        printf("Couldn't get netmask: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        printf("Couldn't parse filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Couldn't apply filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Listening for ICMP packets...\n");

    // Start capturing packets
    pcap_loop(handle, -1, capture_packet, NULL);

    // Close the session and free allocated memory
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}