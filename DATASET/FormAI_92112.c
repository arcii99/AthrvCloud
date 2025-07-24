//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
// Welcome to my unique C Packet Capturer!

#include <pcap.h> // Include the pcap library
#include <stdio.h> // Include standard input/output header
#include <stdlib.h> // Include standard library header

int main(int argc, char **argv) {

  char errbuf[PCAP_ERRBUF_SIZE]; // Create a buffer for error messages
  char *device = pcap_lookupdev(errbuf); // Find the default device
  if(device == NULL) { // Check for errors
    printf("Error finding default device: %s\n", errbuf); // Print error message
    return 1; // Return error
  }

  printf("Using device: %s\n", device); // Print device name

  // Open device for live capture
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if(handle == NULL) { // Check for errors
    printf("Error opening device: %s\n", errbuf); // Print error message
    return 1; // Return error
  }

  // Start packet capture loop
  while(1) {
    struct pcap_pkthdr header; // Create packet header struct
    const u_char *packet = pcap_next(handle, &header); // Get next packet

    // Print packet information
    printf("Packet captured! Length: %d\n", header.len);
    for(int i=0; i<header.len; i++) {
      printf("%02X ", packet[i]); // Print packet data as hexadecimal
    }
    printf("\n");
  }

  pcap_close(handle); // Close capture handle

  return 0; // Exit program
}