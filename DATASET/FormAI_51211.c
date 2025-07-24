//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_BUFFER_SIZE 1024

void print_error(const char* error_buffer, const char* error_prefix, const char* error_suffix) {
   char error_message[ERROR_BUFFER_SIZE];
   snprintf(error_message, ERROR_BUFFER_SIZE, "%s %s %s", error_prefix, error_buffer, error_suffix);
   printf("%s\n", error_message);
   exit(1);
}

void handle_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* buffer) {
   printf("Packet Captured\n");
   printf("Packet length: %d\n", header->len);
}

int main(int argc, char* argv[]) {
   char* device = "eth0";
   char error_buffer[PCAP_ERRBUF_SIZE];

   // Get the network's device
   printf("Getting the network's device...\n");
   pcap_if_t* interface_list = NULL;
   if (pcap_findalldevs(&interface_list, error_buffer) == -1 || interface_list == NULL) {
      print_error(error_buffer, "Could not find device:", pcap_geterr(NULL));
   }
   device = interface_list->name;
   printf("Device found: %s\n", device);
   pcap_freealldevs(interface_list);

   // Open device for capturing
   printf("Opening device for capturing...\n");
   pcap_t* handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
   if (handle == NULL) {
      print_error(error_buffer, "Could not open device:", pcap_geterr(NULL));
   }

   // Capture packets
   printf("Starting packet capturing...\n");
   if (pcap_loop(handle, -1, handle_packet, NULL) == -1) {
      print_error(error_buffer, "Could not start capturing:", pcap_geterr(handle));
   }

   // Close device and exit
   pcap_close(handle);
   exit(0);
}