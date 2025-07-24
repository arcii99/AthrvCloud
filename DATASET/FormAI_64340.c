//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {

  char *device;
  char error_buffer[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program filter;
  char filter_exp[] = "ip";
  bpf_u_int32 subnet_mask, ip;

  if (argc == 1) {
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
      printf("Could not find default device: %s\n", error_buffer);
      return 2;
    }
  } else {
        device = argv[1];
  }

  if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) {
    printf("Error getting netmask for device %s: %s\n", device, error_buffer);
    return 2;
  }

  handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
  if (handle == NULL) {
    printf("Could not open device %s: %s\n", device, error_buffer);
    return 2;
  }

  if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
    printf("Error compiling filter: %s\n", pcap_geterr(handle));
    return 2;
  }

  if (pcap_setfilter(handle, &filter) == -1) {
    printf("Error setting filter: %s\n", pcap_geterr(handle));
    return 2;
  }

  pcap_loop(handle, -1, got_packet, NULL);

  pcap_freecode(&filter);
  pcap_close(handle);

  return 0;
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("A packet has been caught.\n");
}