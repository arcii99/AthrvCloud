//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "icmp";
  bpf_u_int32 net;

  // Step 1: Open the capture device
  handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
  if(handle == NULL)
  {
    fprintf(stderr, "Could not open device: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Step 2: Compile the filter expression
  if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
  {
    fprintf(stderr, "Could not parse filter: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // Step 3: Apply the filter to the capture device
  if(pcap_setfilter(handle, &fp) == -1)
  {
    fprintf(stderr, "Could not apply filter: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // Step 4: Start the capture loop
  pcap_loop(handle, -1, packet_handler, NULL);

  // Step 5: Close the capture device
  pcap_close(handle);
  return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
  // TODO: Implement packet handling logic here
  printf("Received packet of length %d\n", header->len);
}