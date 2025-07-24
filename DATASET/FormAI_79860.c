//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Define maximum packet size
#define MAX_PACKET_SIZE 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  // print packet timestamp and length
  printf("Packet timestamp: %s", ctime((const time_t *) &header->ts.tv_sec));
  printf("Packet length: %d\n", header->len);

  // loop through all packet data and print the hex values
  for (int i = 0; i < header->len; i++) {
    printf("%02X ", packet[i]);

    if ((i + 1) % 16 == 0) {
      printf("\n");
    }
  }

  printf("\n");
}

int main(int argc, char *argv[]) {
  char *device;
  char error_buffer[PCAP_ERRBUF_SIZE]; // buffer for capturing errors
  pcap_t *handle; // pcap session handle

  // get the first available device
  device = pcap_lookupdev(error_buffer);
  if (device == NULL) {
    fprintf(stderr, "Error finding first device: %s\n", error_buffer);
    return EXIT_FAILURE;
  }

  printf("Capturing on device: %s\n", device);

  // open the device in promiscuous mode with a 1 second timeout
  handle = pcap_open_live(device, MAX_PACKET_SIZE, 1, 1000, error_buffer);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device: %s\n", error_buffer);
    return EXIT_FAILURE;
  }

  // capture packets indefinitely
  int num_packets = -1;
  pcap_loop(handle, num_packets, packet_handler, NULL);

  // close the session handle
  pcap_close(handle);

  return EXIT_SUCCESS;
}