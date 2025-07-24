//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: inquisitive
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;
    printf("Packet %d:\n", count);
    printf("Length: %d bytes\n", pkthdr->len);
    printf("Capture time: %s", ctime((const time_t*)&pkthdr->ts.tv_sec));
    count++;
}

int main(int argc, char *argv[])
{
    char errorBuffer[PCAP_ERRBUF_SIZE];
    const int packetCount = 10;
    int timeoutLimit = 10000; /* In milliseconds */
    pcap_t *handle;

    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, timeoutLimit, errorBuffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open interface %s: %s\n", argv[1], errorBuffer);
        return 2;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Interface %s is not an Ethernet interface\n", argv[1]);
        return 3;
    }

    printf("Listening on %s...\n", argv[1]);
    pcap_loop(handle, packetCount, packet_handler, NULL);
    pcap_close(handle);

    return 0;
}