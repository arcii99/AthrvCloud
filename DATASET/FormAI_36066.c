//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("[PACKET] Length: %d\n", header->len);
}

int main(int argc, char *argv[]) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

    if (handle == NULL) {
        printf("[ERROR] Failed to open device: %s", error_buffer);
        return 1;
    }

    printf("[INFO] Listening for packets...\n");

    int result = pcap_loop(handle, -1, packet_handler, NULL);

    if (result == -1) {
        printf("[ERROR] Failed to capture packets: %s", pcap_geterr(handle));
    }

    pcap_close(handle);

    return 0;
}