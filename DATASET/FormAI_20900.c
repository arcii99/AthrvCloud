//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  char errbuf[PCAP_ERRBUF_SIZE];

  pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Could not open device 'eth0': %s", errbuf);
    exit(1);
  }

  printf("Surrealist Packet Capturer is now running!\n");

  while (1) {
    struct pcap_pkthdr* header;
    const u_char* packet;

    int res = pcap_next_ex(handle, &header, &packet);

    if (res == 0) continue;
    if (res == -1 || res == -2) break;

    printf("Packet capture successful! Here are the bytes in hexadecimal:\n");

    int i;
    for (i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\nHave a surreal day!\n");
  }

  pcap_close(handle);

  return 0;
}