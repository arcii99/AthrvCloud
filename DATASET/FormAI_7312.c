//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    printf("Received new packet\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net, mask;
    int num_packets = 10;

    // find a suitable device to capture packets on
    char *deviceId;
    deviceId = pcap_lookupdev(errbuf);
    if (deviceId == NULL)
    {
        printf("pcap_lookupdev error: %s\n", errbuf);
        return 1;
    }

    printf("Starting packet capture on device '%s'\n", deviceId);

    // open a handle to the device
    handle = pcap_create(deviceId, errbuf);
    if (handle == NULL)
    {
        printf("pcap_create error: %s\n", errbuf);
        return 1;
    }

    // activate the handle to the device
    if (pcap_activate(handle) != 0)
    {
        printf("pcap_activate error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // get network and mask information for the device
    if (pcap_lookupnet(deviceId, &net, &mask, errbuf) != 0)
    {
        printf("pcap_lookupnet error: %s\n", errbuf);
        return 1;
    }

    // set the filter expression to "ip"
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        printf("pcap_compile error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // set the compiled filter as the filter for the device
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("pcap_setfilter error: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Packet capture started, capturing %d packets\n", num_packets);

    // start capturing packets
    if (pcap_loop(handle, num_packets, process_packet, NULL) == -1)
    {
        printf("pcap_loop error: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Packet capture complete\n");

    return 0;
}