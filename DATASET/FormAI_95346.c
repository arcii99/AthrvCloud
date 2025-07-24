//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);
//Callback function to receive packets from pcap_loop
//param is the user defined variable that can be used in our function

int main()
{
    pcap_t *handle; //Handle to the device for packet capture
    char errbuf[PCAP_ERRBUF_SIZE]; //To store error messages
    struct bpf_program fp; //To store compiled filter expression
    char filter_exp[] = "ip proto icmp"; //The filter expression (In this case we are interested in only ICMP packets)
    bpf_u_int32 net, mask; //To store network address and netmask of the device in use
    int num_packets = 10; //Number of packets to capture

    //Find a device for packet capture
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }
    printf("Device: %s\n", dev);

    //Get the network address and netmask of the device in use
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    //Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    //Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    //Start packet capture
    printf("Start capturing packets...\n");
    pcap_loop(handle, num_packets, packet_handler, NULL);

    //Close the device for packet capture
    pcap_close(handle);

    printf("Packet capture completed.\n");
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    static int packet_count = 0;

    printf("\nPacket #%d\n", ++packet_count);

    //Print packet timestamp
    printf("Timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    //Print packet size
    printf("Packet size: %d bytes\n", header->len);

    //Print packet data
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", pkt_data[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
}