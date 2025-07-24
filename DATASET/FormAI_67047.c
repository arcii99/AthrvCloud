//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>

int main() {
   char ipAddress[20];
   int isBlocked = 0;
   
   printf("Enter IP address to check: ");
   scanf("%s", ipAddress);
   
   // Check if IP address is in blocked list
   char* blockedList[] = {"192.168.1.1", "10.0.0.1", "172.16.0.1"};
   for (int i = 0; i < 3; i++) {
      if (strcmp(ipAddress, blockedList[i]) == 0) {
         isBlocked = 1;
         break;
      }
   }
   
   if (isBlocked == 1) {
      printf("IP address %s is blocked.\n", ipAddress);
   } else {
      printf("IP address %s is not blocked.\n", ipAddress);
   }
   
   return 0;
}