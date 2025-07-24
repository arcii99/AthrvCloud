//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>

int main() {
  int num_packets = 100;
  int num_rejects = 0;
  int num_accepts = 0;
  
  printf("Starting firewall with %d packets...\n", num_packets);
  
  for (int i = 1; i <= num_packets; i++) {
    int packet_size = i * 10;
    
    if (packet_size > 500) {
      printf("Packet number %d rejected due to size too large\n", i);
      num_rejects++;
    } else if (packet_size < 20) {
      printf("Packet number %d rejected due to size too small\n", i);
      num_rejects++;
    } else {
      printf("Packet number %d accepted\n", i);
      num_accepts++;
    }
  }
  
  printf("Firewall complete.\n");
  printf("%d packets accepted, %d packets rejected\n", num_accepts, num_rejects);
  
  return 0;
}