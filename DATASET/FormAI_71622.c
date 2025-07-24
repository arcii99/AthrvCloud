//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];
  char* blocked_ip_addresses[100];
  int num_blocked_ips = 0;
  
  FILE* log_file = fopen("access_log.txt", "r");
  if (log_file == NULL) {
    printf("Error: Failed to open access_log.txt\n");
    exit(1);
  }
  
  while (fgets(buffer, BUFFER_SIZE, log_file) != NULL) {
    char* ip_address = strtok(buffer, " ");
    char* timestamp = strtok(NULL, "[");
    char* http_request = strtok(NULL, "]");
    char* http_status_code = strtok(NULL, " ");
    
    // Check if recent request came from a blocked IP
    for (int i = 0; i < num_blocked_ips; i++) {
      if (strcmp(ip_address, blocked_ip_addresses[i]) == 0) {
        printf("Blocked IP made a request at %s - %s %s\n", timestamp, http_request, http_status_code);
        break;
      }
    }
    
    // Check if request has excessive status code errors
    if (strcmp(http_status_code, "404") == 0 || strcmp(http_status_code, "401") == 0) {
      int errors = 0;
      for (int i = 0; i < num_blocked_ips; i++) {
        if (strcmp(ip_address, blocked_ip_addresses[i]) == 0) {
          errors++;
        }
      }
      if (errors >= 10) {
        printf("Blocking IP %s for excessive error codes\n", ip_address);
        blocked_ip_addresses[num_blocked_ips++] = ip_address;
      }
    }
  }
  
  fclose(log_file);
  return 0;
}