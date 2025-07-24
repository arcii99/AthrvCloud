//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>

int main() {
  printf("Oh wow, I am surprised to write a Firewall example program today!\n");

  int incoming_packet;
  int is_blocked = 0;

  printf("Enter the port number of incoming packet: ");
  scanf("%d", &incoming_packet);

  if(incoming_packet == 80 || incoming_packet == 443) {
    printf("This packet is from a secured web server. All good!\n");
  } else if(incoming_packet >= 1024 && incoming_packet <= 65535) {
    printf("This packet is from a valid source. Still need to check for malicious activities...\n");

    // Now let's check for some malicious activities using deep packet inspection
    char packet_data[100];
    printf("Enter the packet data: ");
    scanf("%s", packet_data);

    // Let's check if there are any dangerous keywords in the packet data
    if (strstr(packet_data, "attack") || strstr(packet_data, "hack") || strstr(packet_data, "virus")) {
      printf("WARNING! This packet seems to be a malicious one. Blocking it...");
      is_blocked = 1;
    } else {
      printf("This packet is safe. Let it through!\n");
    }
  } else {
    printf("This packet is not from a valid source. Blocking it...\n");
    is_blocked = 1;
  }

  if(is_blocked) {
    printf("\n[ FIREWALL ALERT ]\n");
    printf("[ ACTION: BLOCKED ]\n");
    printf("[ REASON: MALICIOUS ACTIVITY DETECTED ]\n");
  } else {
    printf("\n[ FIREWALL ALERT ]\n");
    printf("[ ACTION: ALLOWED ]\n");
    printf("[ REASON: PACKET IS SAFE ]\n");
  }

  return 0;
}