//FormAI DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int is_allowed = 0;
  char *allowed_ip = "192.168.1.100";
  char *allowed_port = "8080";
  char *ip_address = "";
  char *port = "";
  
  if (argc < 3) {
    printf("Usage: %s <ip_address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  ip_address = argv[1];
  port = argv[2];
  
  if (strcmp(ip_address, allowed_ip) == 0 && strcmp(port, allowed_port) == 0) {
    is_allowed = 1;
  }
  
  if (is_allowed) {
    printf("Access granted!\n");
  } else {
    printf("Access denied!\n");
  }
  
  return 0;
}