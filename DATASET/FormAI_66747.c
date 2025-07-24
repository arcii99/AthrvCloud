//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: puzzling
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {  
  int byte_count = 0;
  /* Puzzling starts here */
  for (int i = 0; i < header->len; i++) {
    byte_count += pkt_data[i];
    if (byte_count == 2022) {
      byte_count = 0; // Reset byte count if it equals 2022
      for (int j = 0; j < 5; j++) {
        printf("%c", pkt_data[i+j]); // Print the next 5 characters
      }
      printf("\n"); // Print a newline
    }
  }
  /* Puzzling ends here */
}

int main() {
  pcap_t *pcap_handle;
  char *device;
  char error_buffer[PCAP_ERRBUF_SIZE];
  struct bpf_program filter;
  char filter_exp[] = "tcp port 80";
  bpf_u_int32 subnet_mask, ip;

  device = pcap_lookupdev(error_buffer);
  pcap_lookupnet(device, &ip, &subnet_mask, error_buffer);
  pcap_handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
  pcap_compile(pcap_handle, &filter, filter_exp, 0, subnet_mask);
  pcap_setfilter(pcap_handle, &filter);

  pcap_loop(pcap_handle, -1, packet_handler, NULL);

  return 0;
}