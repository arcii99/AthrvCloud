//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
/* ---- C Wireless Network Scanner ---- */
/* ----- by The Code Master ----- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_wireless_networks(char** networks, int num_networks) {
  printf("Scanning for wireless networks...\n");

  /* Placeholder code - replace with actual scanning code */
  for (int i = 0; i < num_networks; i++) {
    printf("Network found: %s\n", networks[i]);
  }

  printf("Scan complete.\n\n");
}

int main() {
  char* networks[] = {"Network A", "Network B", "Network C", "Network D", "Network E"};
  int num_networks = sizeof(networks) / sizeof(char*);

  printf("Welcome to the C Wireless Network Scanner!\n\n");
  printf("Press any key to start scanning for wireless networks...\n");
  getchar();

  scan_wireless_networks(networks, num_networks);

  printf("Thank you for using the C Wireless Network Scanner!\n");

  return 0;
}