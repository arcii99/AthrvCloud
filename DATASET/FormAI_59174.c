//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>

/* Callback function to handle packets */
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    int size = header->len;
    int i;
    
    printf("Packet Info:\n");
    printf("Packet size: %d bytes\n", size);
    printf("Payload:\n");
    
    /* Print out the payload in hex */
    for (i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    
    printf("\n\n");
}

int main(int argc, char **argv) {
    char *dev = NULL;   /* Device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;     /* Session handle */
    struct bpf_program fp;
    char filter_exp[] = "port 80";  /* Filter expression */
    bpf_u_int32 mask;   /* The netmask for the sniffing device */
    bpf_u_int32 net;    /* The IP of the sniffing device */
    
    /* Get the name of the device to sniff on */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(1);
    }
    
    /* Get the netmask and IP of the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    
    /* Open the session for sniffing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(1);
    }
    
    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    
    /* Start capturing packets */
    printf("Starting packet capture on device %s...\n", dev);
    pcap_loop(handle, -1, handle_packet, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}