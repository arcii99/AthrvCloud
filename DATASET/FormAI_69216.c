//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
  char dev[] = "eth0";
  char errbuf[PCAP_ERRBUF_SIZE];
  
  /* Open capture device */
  pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return 1;
  }
  
  printf("Packet capture has started...\n\n");

  /* Start the capture loop */
  struct pcap_pkthdr header;
  const u_char *packet;
  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      /* Timeout expired */
      continue;
    }
    
    /* Packet captured! */
    printf("Packet length: %d bytes\n", header.len);
    printf("--- Start of packet ---\n");
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
      if (i % 16 == 15) {
        printf("\n");
      }
    }
    printf("\n--- End of packet ---\n\n");
  }
  
  /* Close the capture device */
  pcap_close(handle);
  
  return 0;
}