//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Romeo and Juliet
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A callback function to execute upon packet capture
void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packet) {
  printf("Packet captured: %d\n", pkthdr->len);
  
  // Check for our lost packet
  if (memcmp(&packet[0], "Romeo", 5) == 0) {
    printf("Romeo, Romeo, wherefore art thou?\n");
  } else if (memcmp(&packet[0], "Juliet", 6) == 0) {
    printf("Dear Juliet, tis Romeo you seek\n");
  }
}

int main() {
  char errbuf[PCAP_ERRBUF_SIZE];
  
  // Get a list of network devices
  pcap_if_t *devList;
  pcap_findalldevs(&devList, errbuf);
  
  // Choose the first one
  pcap_t *handle;
  handle = pcap_open_live(devList->name, BUFSIZ, 1, 1000, errbuf);
  
  // Compile and apply the filter
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, "tcp port 80", 0, PCAP_NETMASK_UNKNOWN) == -1) {
    printf("Error compiling filter: %s\n", pcap_geterr(handle));
    exit(1);
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    printf("Error applying filter: %s\n", pcap_geterr(handle));
    exit(1);
  }
  
  // Start capturing packets
  pcap_loop(handle, 0, packetHandler, NULL);
  
  // Cleanup
  pcap_freecode(&fp);
  pcap_close(handle);
  return 0;
}