//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
   printf("Packet captured, length = %d\n", header->len);
}

int main(int argc, char **argv)
{
   char *device;
   char error_buffer[PCAP_ERRBUF_SIZE];
   pcap_t *handle;
   int snapshot_len = 1024;
   int promiscuous_mode = 1;
   int timeout = 1000; // milliseconds
   int packet_count = 10; // number of packets to capture

   // Get a device to capture packets on
   device = pcap_lookupdev(error_buffer);
   if (device == NULL)
   {
      fprintf(stderr, "Could not find device: %s\n", error_buffer);
      exit(EXIT_FAILURE);
   }
   printf("Device found: %s\n", device);

   // Open the device for capturing
   handle = pcap_open_live(device, snapshot_len, promiscuous_mode, timeout, error_buffer);
   if (handle == NULL)
   {
      fprintf(stderr, "Could not open device: %s\n", error_buffer);
      exit(EXIT_FAILURE);
   }
   printf("Device opened for capturing\n");

   // Start capturing packets
   pcap_loop(handle, packet_count, got_packet, NULL);
   printf("Packet capture complete\n");

   // Close the device
   pcap_close(handle);
   return EXIT_SUCCESS;
}