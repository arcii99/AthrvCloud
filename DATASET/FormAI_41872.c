//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <pcap.h>

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main() {
    pcap_t *handle;
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 mask, net;

    // find the default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // get network mask and IP
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // compile and apply the filter
    if (pcap_compile(handle, &fp, "port 80", 0, net) == -1) {
        printf("Couldn't compile filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't apply filter\n");
        return 1;
    }

    // start capturing packets
    pcap_loop(handle, -1, processPacket, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    static int packetCount = 1;
    printf("\nPacket %d:\n", packetCount);

    // print packet timestamp
    struct tm *ltime;
    char timestr[16];
    time_t local_tv_sec;

    local_tv_sec = header->ts.tv_sec;
    ltime = localtime(&local_tv_sec);
    strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);
    printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);

    // print packet content
    int i;
    for (i = 0; i < header->len; i++) {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    packetCount++;
}