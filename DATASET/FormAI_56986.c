//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = NULL;
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net = 0;
    bpf_u_int32 mask =0;
    char filter_exp[] = "";
    int num_packets =0;

    //find active network device
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device:%s\n",errbuf);
        return (2);
    }
    printf("Device: %s\n", dev);

    //get network address and mask
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    //open network interface
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return (2);
    }

    //compile and apply packet filter
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if(pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    //start loop for packet capture
    printf("Packet capturing started......\n");
    pcap_loop(handle, num_packets, packet_handler, NULL);

    //close and free resources
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Packet capturing ended successfully!\n");

    return 0;
}