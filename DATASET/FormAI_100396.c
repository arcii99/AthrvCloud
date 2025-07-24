//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: futuristic
#include<stdio.h>
#include<pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 subnet_mask, ip;

    if(pcap_lookupnet("eth0", &ip, &subnet_mask, error_buffer) == -1)
    {
        printf("Error getting netmask\n");
        return 1;
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);
    if(handle == NULL)
    {
        printf("Error opening device\n");
        return 1;
    }

    if(pcap_compile(handle, &fp, filter_exp, 0, ip) == -1)
    {
        printf("Error compiling filter\n");
        return 1;
    }

    if(pcap_setfilter(handle, &fp) == -1)
    {
        printf("Error setting filter\n");
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet Received\n");
    // Your code here to analyze the packet
}