//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multivariable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
  printf("Packet Captured\n");
}

int main(int argc, char **argv) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

  if (handle == NULL) {
    printf("Error opening device: %s\n", errbuf);
    return 1;
  }

  if (pcap_loop(handle, 0, packet_handler, NULL) < 0) {
    printf("Error capturing packets: %s\n", pcap_geterr(handle));
    return 1;
  }

  pcap_close(handle);
  
  return 0;
}