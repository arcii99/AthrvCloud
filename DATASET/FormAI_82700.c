//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *callback_args, const struct pcap_pkthdr *pkthdr, const u_char *packet){
    static int count = 1;
    printf("Packet %d:\n", count);
    printf("Timestamp: %s", ctime((const time_t *)&pkthdr->ts.tv_sec));
    printf("Length: %d bytes\n", pkthdr->len);
    printf("Captured Length: %d bytes\n", pkthdr->caplen);
    // print packet data in hex
    for (int i = 0; i < pkthdr->caplen; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
    count++;
}

int main(int argc, char **argv){
    char *device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);  // open live capture on device
    if (!handle){
        printf("Error opening device %s: %s\n", device, error_buffer);
        return 1;
    }
    printf("Listening on device: %s\n", device);
    // set a filter to only capture TCP packets on port 80
    struct bpf_program fp;
    bpf_u_int32 net;
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        printf("Error compiling filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter\n");
        return 1;
    }
    pcap_loop(handle, -1, packet_handler, NULL);  // capture packets infinitely and call packet_handler for each packet
    pcap_close(handle);
    return 0;
}