//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <pcap.h>
#include <stdio.h>

/* callback function declaration */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *adapter_handle;
    struct bpf_program bpf_filter;
    char filter_exp[] = "tcp port 80"; /* filter expression */
    bpf_u_int32 subnet_mask, ip_address;
    int packet_count_limit = 10;
    int timeout_limit = 10000;
    int res;

    /* get a network adapter to sniff on */
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        printf("error finding network adapter: %s\n", errbuf);
        return 1;
    }

    /* open the adapter */
    adapter_handle = pcap_open_live(dev, 65536, 1, timeout_limit, errbuf);
    if (adapter_handle == NULL)
    {
        printf("error opening adapter: %s\n", errbuf);
        return 1;
    }

    /* get the IP address and subnet mask of the adapter */
    if (pcap_lookupnet(dev, &ip_address, &subnet_mask, errbuf) == -1)
    {
        printf("error getting IP address and subnet mask: %s\n", errbuf);
        return 1;
    }

    /* compile the filter expression */
    if (pcap_compile(adapter_handle, &bpf_filter, filter_exp, 0, ip_address) == -1)
    {
        printf("error compiling filter expression: %s\n", pcap_geterr(adapter_handle));
        pcap_close(adapter_handle);
        return 1;
    }

    /* apply the compiled filter */
    if (pcap_setfilter(adapter_handle, &bpf_filter) == -1)
    {
        printf("error setting filter: %s\n", pcap_geterr(adapter_handle));
        pcap_close(adapter_handle);
        return 1;
    }

    /* start capturing packets */
    pcap_loop(adapter_handle, packet_count_limit, packet_handler, NULL);

    /* close the adapter */
    pcap_close(adapter_handle);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    /* do something with the captured packet */
    printf("received packet of %d bytes\n", header->len);
    /* ... */
}