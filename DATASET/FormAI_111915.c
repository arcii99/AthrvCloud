//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <pcap.h>

int main() {

  printf("Welcome to the C Packet Capturer Example Program!\n");

  //we will be capturing 1024 bytes of the packet payload
  int captureSize = 1024;

  //choose which network interface to capture packets from, in this example we will choose eth0
  char* netInterface = "eth0";

  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* handle = pcap_open_live(netInterface, captureSize, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Failed to open %s: %s\n", netInterface, errbuf);
    return 1;
  }

  while(1) {
    struct pcap_pkthdr header;
    const u_char* packet = pcap_next(handle, &header);
    if (packet == NULL) {
      continue;
    }

    //Print the raw packet data in hex form
    printf("Raw Packet Data:\n");
    for(int i=0; i < header.len; i++) {
      printf("%02x ", packet[i]);
    }

    //Separate the packet data with a newline for readability
    printf("\n");

    //Print some useful information from the packet header
    printf("Packet length: %d\n", header.len);
    printf("Number of bytes captured: %d\n", header.caplen);
    printf("Timestamp: %ld.%06ld\n", header.ts.tv_sec, header.ts.tv_usec);
  }

  //We're done with capturing packets, close the handle and return 0
  pcap_close(handle);
  return 0;
}