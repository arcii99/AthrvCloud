//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Firewall program!\n");
  printf("Please enter the IP address you want to block: ");
  char ip[16];
  scanf("%s", ip);
  printf("Great! We will block %s\n", ip);
  
  printf("Setting up firewall rules...\n");
  
  // Blocking IP address using iptables
  char command[50];
  sprintf(command, "iptables -A INPUT -s %s -j DROP", ip);
  system(command);
  
  printf("Done! %s has been blocked.\n", ip);
  
  return 0;
}