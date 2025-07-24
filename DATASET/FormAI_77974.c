//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
  char ip[16];
  int mask;
  printf("Enter IP Address: ");
  scanf("%s", ip);
  printf("Enter Subnet Mask: ");
  scanf("%d", &mask);

  int octets[4];
  sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
  
  int binary_mask = (int)pow(2, mask) - 1;
  int wild_card_mask = 255 - binary_mask;

  int network_address[4];
  for (int i = 0; i < 4; i++) {
    network_address[i] = octets[i] & (binary_mask >> (8 * (3 - i)));
  }
  
  int first_address[4];
  for (int i = 0; i < 4; i++) {
    first_address[i] = (i == 3) ? network_address[i] + 1 : network_address[i];
  }

  int broadcast_address[4];
  for (int i = 0; i < 4; i++) {
    broadcast_address[i] = octets[i] | (wild_card_mask >> (8 * (3 - i)));
  }

  int last_address[4];
  for (int i = 0; i < 4; i++) {
    last_address[i] = (i == 3) ? broadcast_address[i] - 1 : broadcast_address[i];
  }

  printf("\n");
  printf("IP Address: %s\n", ip);
  printf("Subnet Mask: %d\n", mask);
  printf("Binary Mask: %d.%d.%d.%d\n", (binary_mask >> 24) & 0xFF, (binary_mask >> 16) & 0xFF, (binary_mask >> 8) & 0xFF, binary_mask & 0xFF);
  printf("Wild Card Mask: %d.%d.%d.%d\n", (wild_card_mask >> 24) & 0xFF, (wild_card_mask >> 16) & 0xFF, (wild_card_mask >> 8) & 0xFF, wild_card_mask & 0xFF);
  printf("Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
  printf("First Address: %d.%d.%d.%d\n", first_address[0], first_address[1], first_address[2], first_address[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
  printf("Last Address: %d.%d.%d.%d\n", last_address[0], last_address[1], last_address[2], last_address[3]);

  return 0;
}