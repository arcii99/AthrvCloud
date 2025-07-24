//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
/*The following program captures network packets using the pcap library*/

#include <stdio.h>
#include <pcap.h>

//Function to print packet data
void print_packet(const u_char *packet, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
}

//Packet handler function
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("\nPacket Info:\n");
    printf("Capture length: %d bytes\n", header->caplen);
    printf("Actual length: %d bytes\n", header->len);
    printf("\nPacket Data:\n");
    print_packet(packet, header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE]; //Error buffer
    pcap_t *handle;                //Packet capture handle
    char *dev;                     //Device to sniff on
    struct bpf_program fp;         //Compiled filter expression
    char filter_exp[] = "tcp";     //Filter expression
    bpf_u_int32 mask;              //Netmask
    bpf_u_int32 net;               //IP

    //Find a capture device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    //Get the network address and mask of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    //Open the capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    //Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    //Apply the compiled filter expression
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    //Start capturing packets
    printf("Starting capture on device %s...\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    //Close the handle
    pcap_close(handle);
    return 0;
}