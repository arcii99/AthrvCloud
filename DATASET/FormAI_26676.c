//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <pcap.h>

/* This function is called every time a packet is captured */
void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet
) {
    printf("Packet handler called\n");
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    /* Open the capture device. Here we are using the default device (usually eth0) */
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    /* Check if opening the device was successful */
    if(handle == NULL) {
        printf("Couldn't open device: %s\n", errbuf);
        return 1;
    }

    /* Start capturing packets */
    pcap_loop(handle, 0, my_packet_handler, NULL);

    /* Close the capture device */
    pcap_close(handle);

    return 0;
}