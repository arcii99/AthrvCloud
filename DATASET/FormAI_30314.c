//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include<stdio.h>
#include<pcap.h>

void packetsHandler(u_char *args, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    static int i = 0;

    printf("Packet No# %d\n", ++i);

    printf("Packet size: %d\n", pkthdr->len);

    printf("Time: %s", ctime((const time_t *)&pkthdr->ts.tv_sec));

    for (int j = 0; j < pkthdr->len; j++) {
        printf("%.2x ", packet[j]);

        // Print each packet of 16 bytes per line
        if ((j + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(int argc, char *argv[]) {
    pcap_t *handler;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    char *device;

    device = pcap_lookupdev(errorBuffer);

    if (device == NULL) {
        printf("Error finding device: %s\n", errorBuffer);
        return 1;
    }

    printf("Device found: %s\n", device);

    handler = pcap_open_live(device, BUFSIZ, 1, 0, errorBuffer);

    if (handler == NULL) {
        printf("Error opening device: %s\n", errorBuffer);
        return 1;
    }

    printf("Listening for packets...\n");

    pcap_loop(handler, -1, packetsHandler, NULL);

    pcap_close(handler);

    return 0;
}