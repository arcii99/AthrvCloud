//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <pcap.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 2;
    }
    printf("Welcome to the Packet Capturer Program!\n");
    printf("Let's capture some packets, shall we?\n");
    printf("Press \'q\' at any time to exit.\n\n");

    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 0;
    
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        printf("Packet number %d:\n", ++packet_count);
        printf("    Length: %d bytes\n", header.len);
        printf("    Encapsulation type: %s\n\n", pcap_datalink_val_to_name(pcap_datalink(handle)));
        if (getc(stdin) == 'q') {
            break;
        }
    }
    pcap_close(handle);
    printf("Thanks for using the Packet Capturer Program!\n");
    return 0;
}