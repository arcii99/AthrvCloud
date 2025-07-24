//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);

int main(int argc, char** argv) {
  char* device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* handle;
  int buffer_size = 1024 * 1024;
  int timeout_ms = 100;

  if (argc != 2) {
    printf("Usage: pcap_sniffer <interface>\n");
    return -1;
  }

  device = argv[1];

  handle = pcap_create(device, errbuf);

  if (handle == NULL) {
    printf("pcap_create() failed: %s\n", errbuf);
    return -1;
  }

  if (pcap_set_buffer_size(handle, buffer_size) != 0) {
    printf("pcap_set_buffer_size() failed: %s\n", pcap_geterr(handle));
    return -1;
  }

  if (pcap_set_promisc(handle, 1) != 0) {
    printf("pcap_set_promisc() failed: %s\n", pcap_geterr(handle));
    return -1;
  }

  if (pcap_activate(handle) != 0) {
    printf("pcap_activate() failed: %s\n", pcap_geterr(handle));
    return -1;
  }

  if (pcap_set_timeout(handle, timeout_ms) != 0) {
    printf("pcap_set_timeout() failed: %s\n", pcap_geterr(handle));
    return -1;
  }

  printf("Listening on %s...\n", device);

  pcap_loop(handle, -1, packet_handler, NULL);

  return 0;
}

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
  // packet processing code
  printf("Packet captured: length=%d\n", header->len);
}