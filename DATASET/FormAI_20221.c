//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MIN_RSSI -100
#define MAX_RSSI 0

#define BIN_COUNT 10

#define NUM_CHANNELS 14

uint32_t bins[BIN_COUNT] = {0};

void count_rssi(const u_char *packet, int channel)
{
    int rssi = (int)packet[22] - 256;
    rssi = -rssi;
    if (rssi > MAX_RSSI)
        rssi = MAX_RSSI;
    if (rssi < MIN_RSSI)
        rssi = MIN_RSSI;
    int bin = (rssi - MIN_RSSI) / (MAX_RSSI - MIN_RSSI) * BIN_COUNT;
    if (bin >= BIN_COUNT)
        bin = BIN_COUNT - 1;
    bins[bin]++;
    return;
}

void print_graph()
{
    int i, j;
    printf("Wi-Fi Signal Strength Analyzer Output\n\n");
    for (i = 0; i < BIN_COUNT; i++) {
        printf("%d dBm - %d dBm | ", MIN_RSSI + (MAX_RSSI - MIN_RSSI) * i / BIN_COUNT,
            MIN_RSSI + (MAX_RSSI - MIN_RSSI) * (i + 1) / BIN_COUNT);
        for (j = 0; j < bins[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int channel = *((int *)args);

    if ((int)packet[36] == 0x80 && (int)packet[37] == 0x00) {
        count_rssi(packet, channel);
    }

    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    char *device = argv[1];
    int monitor = 1;

    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_create(device, error_buffer);

    if (handle == NULL) {
        printf("pcap_create() failed: %s\n", error_buffer);
        return 1;
    }

    if (pcap_set_rfmon(handle, monitor) != 0) {
        printf("pcap_set_rfmon() failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_activate(handle) != 0) {
        printf("pcap_activate() failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    int i;
    for (i = 1; i <= NUM_CHANNELS; i++) {
        char command[100];
        sprintf(command, "iwconfig %s channel %d", device, i);
        system(command);

        int channel = i;
        pcap_loop(handle, -1, process_packet, (u_char *)&channel);

        memset(bins, 0, sizeof(bins));
    }

    print_graph();

    pcap_close(handle);

    return 0;
}