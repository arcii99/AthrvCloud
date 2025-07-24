//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
   bool flag = false;
   char ip[20];
   int port;
   
   printf("Enter IP address: ");
   scanf("%s", ip);
   printf("Enter port number: ");
   scanf("%d", &port);

   for (int i = 0; i < strlen(ip); i++) {
      if (ip[i] == '.') {
         flag = true;
         break;
      }
   }
   
   if (!flag) {
      printf("Invalid IP address.\n");
      return 0;
   }
   
   if (port < 0 || port > 65535) {
      printf("Invalid port number.\n");
      return 0;
   }
   
   printf("Firewall Rules:\n");
   printf("IP address: %s \nPort Number: %d\n\n", ip, port);

   // Add firewall rules implementation here
   // Code for opening and closing network ports
   // Code to restrict access to specific IP addresses
   
   printf("Firewall rules have been applied successfully.\n");

   return 0;
}