//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Surprise! You have just stumbled upon a unique C Firewall program!\n");
  
  // First, we need to initialize our firewall ruleset and our packet to be examined
  char *ip_rules[] = {"192.168.0.1", "10.0.0.1"}; // A list of IP addresses allowed through the firewall
  char packet[] = "192.168.0.1"; // An example packet to be examined
  
  // Now, we need to loop through our ruleset and compare it to the packet. If there's a match, allow the packet through, otherwise, block it.
  int rule_count = sizeof(ip_rules)/sizeof(*ip_rules); // Get the size of our IP ruleset
  int i;
  int allow_packet = 0; // This variable is set to 0 if the packet should be blocked
  
  for (i = 0; i < rule_count; i++) {
    if (strcmp(ip_rules[i], packet) == 0) { // If the packet matches one of our rules
      allow_packet = 1; // Allow the packet through
      break;
    }
  }
  
  if (allow_packet) {
    printf("Packet allowed through the firewall!\n");
  } else {
    printf("Packet blocked by the firewall!\n");
  }
  
  return 0; // End the program
}