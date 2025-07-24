//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <pcap.h>

// The following code will capture packets while making fun of them

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Ha ha! Nice try, packet!\n");
    printf("Packet length: %d\n", header->len);
    printf("Au revoir!\n");
}

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net;
    int num_packets = 10;

    // Open capture device
    printf("Opening capture device... Ha ha!\n");
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Uh oh, error opening device: %s\n", errbuf);
        return 1;
    }

    // Compile and apply filter
    printf("Compiling and applying filter... Wait for it...\n");
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error applying filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets!
    printf("Capturing packets... Ha ha!\n");
    pcap_loop(handle, num_packets, got_packet, NULL);

    // Close handle
    printf("Closing capture device... Bye bye!\n");
    pcap_close(handle);
    
    return 0;
}