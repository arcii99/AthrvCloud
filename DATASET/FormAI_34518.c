//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char **argv)
{
    pcap_t *handle;         /* Session handle */
    char *dev;              /* The device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE];  /* Error string */
    struct bpf_program fp;      /* The compiled filter expression */
    char filter_exp[] = "port 80"; /* The filter expression */
    bpf_u_int32 mask;       /* Our netmask */
    bpf_u_int32 net;        /* Our IP */
    int num_packets = 10;   /* number of packets to capture */

    /* Define the device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    /* Find the properties for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    /* Compile and apply the filter expression */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    /* Start capturing packets */
    pcap_loop(handle, num_packets, process_packet, NULL);
    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("\nFinished packet capture\n");
    return(0);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;   /* packet counter */

    /* print packet header */
    printf("\nPacket number %d:\n", count);

    printf("Packet size: %d bytes\n", header->len);
    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec)); 
    /* ctime() adds a newline */

    /* loop through each byte of the packet */
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("   ");
            for (int j = i - 15; j <= i; j++) {
                if (packet[j] > 31 && packet[j] < 127) {
                    printf("%c", packet[j]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    count++;
}