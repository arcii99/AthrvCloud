//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   int sock, start_port, end_port, i, result;
   char ip[15];
   struct sockaddr_in target;

   printf("Welcome to the Happy Port Scanner!\n");
   printf("Please enter the IP address to scan: ");
   fgets(ip, 15, stdin);
   printf("Please enter the starting port: ");
   scanf("%d", &start_port);
   printf("Please enter the ending port: ");
   scanf("%d", &end_port);

   // create socket
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if(sock == -1) {
      printf("Could not create socket.\n");
      exit(1);
   }

   // set up target ip and port
   target.sin_family = AF_INET;
   target.sin_addr.s_addr = inet_addr(ip);

   // scan port range
   for(i = start_port; i <= end_port; i++) {
      target.sin_port = htons(i);
      result = connect(sock, (struct sockaddr *)&target, sizeof(target));
      if(result == 0) {
         printf("Port %d is open! Happy scanning :)\n", i);
      } else {
         printf("Port %d is closed :( Keep smiling :)\n", i);
      }
   }

   // close socket
   close(sock);
   printf("Scan complete. Thanks for using the Happy Port Scanner!\n");

   return 0;
}