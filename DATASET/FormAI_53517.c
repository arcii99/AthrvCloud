//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: peaceful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

/* callback function that processes packets */
void process_packet(u_char *args, const struct pcap_pkthdr *header,
                    const u_char *packet) {
  // print packet length
  printf("Packet length: %d\n", header->len);

  // print raw packet data
  for (int i = 0; i < header->len; i++) {
    printf("%02x ", packet[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  char *device = NULL;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  // obtain device name
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "pcap_lookupdev failed: %s\n", errbuf);
    exit(1);
  }

  // open device for sniffing
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live failed: %s\n", errbuf);
    exit(1);
  }

  // compile filter expression
  struct bpf_program fp;
  char *filter_exp = "tcp port 80";
  if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1) {
    fprintf(stderr, "pcap_compile failed\n");
    exit(1);
  }

  // apply filter expression
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "pcap_setfilter failed\n");
    exit(1);
  }

  // start capturing packets
  pcap_loop(handle, -1, process_packet, NULL);

  // cleanup
  pcap_freecode(&fp);
  pcap_close(handle);

  return 0;
}