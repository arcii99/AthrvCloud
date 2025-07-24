//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>

void print_hex_ascii_line(const u_char *, int, int);

void print_payload(const u_char *payload, int len) {
    int len_rem = len;
    int line_width = 16;                
    int line_len;
    int offset = 0;                     
    const u_char *ch = payload;

    if (len <= 0)
        return;

    if (len <= line_width) {
        print_hex_ascii_line(ch, len, offset);
        return;
    }

    for (;;) {
        line_len = line_width % len_rem;
        print_hex_ascii_line(ch, line_len, offset);
        len_rem = len_rem - line_len;
        ch = ch + line_len;
        offset = offset + line_width;
        if (len_rem <= line_width) {
            print_hex_ascii_line(ch, len_rem, offset);
            break;
        }
    }
}

void print_hex_ascii_line(const u_char *payload, int len, int offset) {
    int i;
    int gap;
    const u_char *ch;

    printf("%05d   ", offset);

    ch = payload;
    for (i = 0; i < len; i++) {
        printf("%02x ", *ch);
        ch++;

        if (i == 7)
            printf(" ");

    }

    if (len < 8)
        printf(" ");

    if (len < 16) {
        gap = 16 - len;
        for (i = 0; i < gap; i++) {
            printf("   ");
        }
    }
    printf("   ");

    ch = payload;
    for (i = 0; i < len; i++) {
        if (isprint(*ch))
            printf("%c", *ch);
        else
            printf(".");
        ch++;
    }

    printf("\n");

}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    static int count = 1;
    const u_char *ch;
    int length = header->len;

    printf("Packet number %d:\n", count);
    printf("Packet length: %d\n", length);

    ch = packet;
    printf("Packet data (in hex):\n");
    print_payload(ch, length);

    count++;
}

int main(int argc, char *argv[]) {

    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000;  

    if(argc != 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    device = argv[1];
    printf("Capturing packets on device '%s'...\n", device);

    handle = pcap_create(device, error_buffer);
    if(handle == NULL) {
        printf("pcap_create() failed: %s\n", error_buffer);
        exit(1);
    }

    if(pcap_set_snaplen(handle, 65535) != 0) {
        printf("pcap_set_snaplen() failed\n");
        exit(1);
    }

    if(pcap_set_promisc(handle, 1) != 0) {
        printf("pcap_set_promisc() failed\n");
        exit(1);
    }

    if(pcap_set_rfmon(handle, 1) != 0) {
        printf("pcap_set_rfmon() failed\n");
        exit(1);
    }

    if(pcap_activate(handle) != 0) {
        printf("pcap_activate() failed\n");
        exit(1);
    }

    if(pcap_loop(handle, -1, got_packet, NULL) < 0) {
        printf("pcap_loop() failed: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_close(handle);
    printf("Packet capture complete.\n");

    return 0;
}