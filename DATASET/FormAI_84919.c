//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Constants */
#define MAX_IP_LENGTH 16
#define MAX_CIDR_LENGTH 3

/* Function prototypes */
void calculateSubnetMask(int cidr, char *subnetMask);
void calculateNetworkID(char *ipAddress, char *subnetMask, char *networkID);
void calculateBroadcastID(char *ipAddress, char *subnetMask, char *broadcastID);
void calculateTotalHosts(int cidr, int *totalHosts);

int main() {

  char ipAddress[MAX_IP_LENGTH];
  int cidr, totalHosts;
  char subnetMask[MAX_IP_LENGTH], networkID[MAX_IP_LENGTH], broadcastID[MAX_IP_LENGTH];
  
  /* Get input */
  printf("Enter an IP address in dotted decimal format: ");
  scanf("%s", ipAddress);
  
  printf("Enter the CIDR notation (between 0 and 32): ");
  scanf("%d", &cidr);
  
  /* Verify input */
  if (cidr < 0 || cidr > 32) {
    printf("Invalid CIDR notation. Please enter a value between 0 and 32.\n");
    exit(1);
  }

  if (strlen(ipAddress) > MAX_IP_LENGTH) {
    printf("Invalid IP address. Length exceeds maximum allowed.\n");
    exit(1);
  }
  
  /* Calculate subnet mask */
  calculateSubnetMask(cidr, subnetMask);

  /* Calculate network ID */
  calculateNetworkID(ipAddress, subnetMask, networkID);

  /* Calculate broadcast ID */
  calculateBroadcastID(ipAddress, subnetMask, broadcastID);

  /* Calculate total number of hosts */
  calculateTotalHosts(cidr, &totalHosts);

  /* Display results */
  printf("\nSubnet Mask: %s\nNetwork ID: %s\nBroadcast ID: %s\nTotal Hosts: %d\n", subnetMask, networkID, broadcastID, totalHosts);

  return 0;
}

/* Function to calculate subnet mask from CIDR notation */
void calculateSubnetMask(int cidr, char *subnetMask) {

  /* Calculate number of bits for subnet mask */
  int ones = cidr, zeroes = 32 - cidr;

  /* Calculate subnet mask */
  int value = (int)pow(2, ones) - 1;
  value <<= zeroes;

  /* Convert subnet mask to dotted decimal format */
  sprintf(subnetMask, "%d.%d.%d.%d", (value >> 24) & 0xFF, (value >> 16) & 0xFF, (value >> 8) & 0xFF, value & 0xFF);

}

/* Function to calculate network ID */
void calculateNetworkID(char *ipAddress, char *subnetMask, char *networkID) {

  /* Convert IP address and subnet mask to arrays of integers */
  int ip[4], mask[4];
  sscanf(ipAddress, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
  sscanf(subnetMask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

  /* Calculate network ID */
  int net[4];
  net[0] = ip[0] & mask[0];
  net[1] = ip[1] & mask[1];
  net[2] = ip[2] & mask[2];
  net[3] = ip[3] & mask[3];

  /* Convert network ID to dotted decimal format */
  sprintf(networkID, "%d.%d.%d.%d", net[0], net[1], net[2], net[3]);

}

/* Function to calculate broadcast ID */
void calculateBroadcastID(char *ipAddress, char *subnetMask, char *broadcastID) {

  /* Convert IP address and subnet mask to arrays of integers */
  int ip[4], mask[4];
  sscanf(ipAddress, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
  sscanf(subnetMask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

  /* Calculate broadcast ID */
  int bcast[4];
  bcast[0] = ip[0] | (~mask[0] & 0xFF);
  bcast[1] = ip[1] | (~mask[1] & 0xFF);
  bcast[2] = ip[2] | (~mask[2] & 0xFF);
  bcast[3] = ip[3] | (~mask[3] & 0xFF);

  /* Convert broadcast ID to dotted decimal format */
  sprintf(broadcastID, "%d.%d.%d.%d", bcast[0], bcast[1], bcast[2], bcast[3]);

}

/* Function to calculate total number of hosts */
void calculateTotalHosts(int cidr, int *totalHosts) {

  /* Calculate number of bits for host */
  int hostBits = 32 - cidr;

  /* Calculate total number of hosts */
  if (cidr == 31 || cidr == 32) {
    *totalHosts = 0; /* Special case for /31 and /32 */
  }
  else {
    *totalHosts = (int)pow(2, hostBits) - 2; /* Subtract 2 for network and broadcast IDs */
  }

}