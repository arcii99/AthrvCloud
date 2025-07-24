//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char ip_address[16];
   int port;
} Address;

typedef struct {
   Address source;
   Address destination;
} Packet;

int main() {
   Packet data[5];
   int i = 0;
   int j;
   int allowed = 1;
    
   // Add some example packets to the data array
   strcpy(data[0].source.ip_address, "192.168.1.1");
   data[0].source.port = 80;
   strcpy(data[0].destination.ip_address, "10.0.0.20");
   data[0].destination.port = 22;
    
   strcpy(data[1].source.ip_address, "192.168.1.2");
   data[1].source.port = 22;
   strcpy(data[1].destination.ip_address, "10.0.0.20");
   data[1].destination.port = 80;
    
   strcpy(data[2].source.ip_address, "192.168.1.3");
   data[2].source.port = 443;
   strcpy(data[2].destination.ip_address, "10.0.0.21");
   data[2].destination.port = 22;
    
   strcpy(data[3].source.ip_address, "192.168.1.4");
   data[3].source.port = 22;
   strcpy(data[3].destination.ip_address, "10.0.0.21");
   data[3].destination.port = 80;
    
   strcpy(data[4].source.ip_address, "192.168.1.5");
   data[4].source.port = 8080;
   strcpy(data[4].destination.ip_address, "10.0.0.20");
   data[4].destination.port = 80;
    
   // Check each packet to see if it should be allowed or blocked
   for (i = 0; i < 5; i++) {
      allowed = 1;
      // Check for specific IP address blocks
      if (strncmp(data[i].source.ip_address, "192.168.", 8) == 0 ||
                strncmp(data[i].destination.ip_address, "192.168.", 8) == 0) {
         allowed = 0;
      }
      // Check for specific port blocks
      if (data[i].source.port == 22 || data[i].destination.port == 22) {
         allowed = 0;
      }
      // Print the result of the analysis
      printf("Packet %d: %s:%d to %s:%d is %s\n", i+1, data[i].source.ip_address,
             data[i].source.port, data[i].destination.ip_address, data[i].destination.port,
             allowed == 1 ? "ALLOWED" : "BLOCKED");
   }
   
   return 0;
}