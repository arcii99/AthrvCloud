//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
//Welcome to the Packet Capturer with Pcap Library example program! Let's get started!

#include <pcap.h> //Include pcap library

int main() {

   pcap_t *packet; //Declare a new packet
   char errorBuffer[PCAP_ERRBUF_SIZE]; //Buffer for storing errors
   struct pcap_pkthdr header; //Declare a new packet header
   const u_char *packetData; //Byte array for storing captured packet data

   //Let's open a network interface for capturing packets
   packet = pcap_open_live("en0", BUFSIZ, 1, 1000, errorBuffer);

   //Check for errors while opening the interface
   if(packet == NULL) {
      printf("An error occurred while opening the network interface: %s\n", errorBuffer);
      return 1;
   }

   //Let's capture a packet and store it in packetData
   packetData = pcap_next(packet, &header);

   //Check if packet is captured successfully
   if(packetData == NULL) {
      printf("No packets were captured!\n");
      return 1;
   }

   //Print out the captured packet data in hexadecimal
   printf("Packet Data:\n");
   printf("----------------------------------------------------\n");
   int count = 0;
   for(int i=0; i < header.len; i++) {
      printf("%02x ", packetData[i]);
      count++;
      if(count == 16) {
         printf("\n");
         count = 0;
      }
   }
   printf("\n");

   //Close the packet capture session
   pcap_close(packet);

   //We're done!
   return 0;
}