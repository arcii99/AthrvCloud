//FormAI DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   if(argc !=4){
      printf("Usage: %s <IP address> <start port> <end port>\n",argv[0]);
      exit(0);
   }

   char *ip = argv[1];
   int start_port = atoi(argv[2]);
   int end_port = atoi(argv[3]);

   for(int port = start_port; port <= end_port; port++){
      struct sockaddr_in addr;
      int sock = socket(AF_INET, SOCK_STREAM, 0);

      // Set the IP and port of the address to scan
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = inet_addr(ip);

      // Connect to the address
      int res = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

      if (res == 0) {
         printf("Port %d is open\n", port);
      }

      // Close the socket
      close(sock);
   }

   return 0;
}