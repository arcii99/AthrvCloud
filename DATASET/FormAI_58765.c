//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    printf("Packet captured!\n");
}

int main(int argc, char **argv)
{
    char *devname; // name of the device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE]; // buffer to hold any error messages
    pcap_t *handle; // handle to the device to capture packets from
    int snapshot_len = 1024; // size of each packet snapshot
    int promiscuous = 0; // do not use promiscuous mode
    int timeout = 1000; // timeout for capturing packets in milliseconds

    if (argc == 2) {
        devname = argv[1];
    } else {
        devname = pcap_lookupdev(errbuf);
        if (devname == NULL) {
            printf("Error finding default device: %s\n", errbuf);
            return 1;
        }
    }

    printf("Using device: %s\n", devname);

    handle = pcap_open_live(devname, snapshot_len, promiscuous, timeout, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}