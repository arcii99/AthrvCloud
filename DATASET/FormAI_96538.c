//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("\nUsage: %s <IP> <Port Range>\n", argv[0]);
      exit(0);
   }
   
   char *ip = argv[1];
   int portStart = atoi(argv[2]);
   int portEnd = portStart + 100;
   printf("\nScanning IP %s ...\n", ip);
   
   for (int i = portStart; i <= portEnd; i++) {
      int sock = socket(AF_INET, SOCK_STREAM, 0);
      struct sockaddr_in server;
      server.sin_family = AF_INET;
      server.sin_port = htons(i);
      server.sin_addr.s_addr = inet_addr(ip);

      int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
      if (result == 0) {
         printf("Port %d - OPEN\n", i);
      }
      
      close(sock);
   }
   printf("\nScan Complete!\n");
   return 0;
}