//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_ATTACKS 1000

char packets[MAX_ATTACKS][MAX_PACKET_SIZE];
int packet_sizes[MAX_ATTACKS];
int num_attacks = 0;

/* Function to check if a given string is a valid IP address */
int is_valid_ip(char* ip) {
  int i, num_dots = 0, len = strlen(ip);
  
  if (len > 15) {
    return 0; /* Invalid IP */
  }
  
  for (i = 0; i < len; i++) {
    if (!isdigit(ip[i]) && ip[i] != '.') {
      return 0; /* Invalid IP */
    }
    if (ip[i] == '.') {
      num_dots++;
    }
  }
  
  if (num_dots != 3) {
    return 0; /* Invalid IP */
  }
  
  return 1; /* Valid IP */
}

/* Function to detect if a packet is a potential attack */
int detect_attack(char* packet, int size) {
  if (size > MAX_PACKET_SIZE) {
    return 1; /* Attack detected */
  }
  
  if (strstr(packet, "DROP") != NULL) {
    return 1; /* Attack detected */
  }
  
  if (strstr(packet, "MALWARE") != NULL) {
    return 1; /* Attack detected */
  }
  
  if (strstr(packet, "SPAM") != NULL) {
    return 1; /* Attack detected */
  }
  
  return 0; /* No attack detected */
}

/* Function to process a packet */
void process_packet(char* packet, int size) {
  if (detect_attack(packet, size)) {
    strncpy(packets[num_attacks], packet, size);
    packet_sizes[num_attacks] = size;
    num_attacks++;
    printf("Potential attack detected! Packet saved.\n");
  } else {
    printf("Packet OK.\n");
  }
}

/* Function to print all saved packets */
void print_saved_packets() {
  int i;
  for (i = 0; i < num_attacks; i++) {
    printf("[%d]: %s\n", i, packets[i]);
  }
}

int main() {
  char input[100];
  printf("Intrusion Detection System v1.0\n");
  
  while (1) {
    printf("Enter packet: ");
    fgets(input, sizeof(input), stdin);
    
    if (strcmp(input, "exit\n") == 0) {
      break;
    }
    
    if (!is_valid_ip(input)) {
      printf("Invalid input. Must be a valid IP address.\n");
      continue;
    }
    
    process_packet(input, strlen(input));
  }
  
  printf("Number of attacks detected: %d\n", num_attacks);
  print_saved_packets();
  
  return 0;
}