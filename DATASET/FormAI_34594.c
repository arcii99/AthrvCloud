//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Wireless Network Scanner!\n\n");

  // Get user input
  char* ssid;
  printf("Please enter the SSID of the network to scan: ");
  scanf("%s", ssid);
  int channel;
  printf("Please enter the channel number to scan (1-11): ");
  scanf("%d", &channel);

  // Validate channel number
  if (channel < 1 || channel > 11) {
    printf("Invalid channel number. Please enter a value between 1 and 11.\n");
    return 1;
  }

  // Construct command string and execute
  char command[100];
  sprintf(command, "sudo iwlist wlan0 scan essid %s channel %d", ssid, channel);
  system(command);

  printf("\nScan complete!\n");

  return 0;
}