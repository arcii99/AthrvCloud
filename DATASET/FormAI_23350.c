//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Alan Touring
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured!");
    //Do something with the packet data here
}

int main(int argc, char **argv) 
{
    char errbuf[PCAP_ERRBUF_SIZE];

    //Open network device for live capture
    pcap_t *handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);
    if (handle == NULL)
    {
        printf("Failed to open device: %s", errbuf);
        return 1;
    }

    //Compile filter expression
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "tcp dst port 80", 0, 0) == -1)
    {
        printf("Failed to compile filter expression: %s", pcap_geterr(handle));
        return 1;
    }

    //Apply filter expression
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Failed to apply filter expression: %s", pcap_geterr(handle));
        return 1;
    }

    //Begin packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    //Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}