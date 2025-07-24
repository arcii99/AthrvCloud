//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

void usage(char *progname) {
    printf("Usage: %s <ip_address>\n", progname);
}
 
int main(int argc, char *argv[]) {
   
   if(argc != 2) {
      usage(argv[0]);
      exit(0);
   }
   
   char *ip = argv[1];
   int sock = socket(AF_INET, SOCK_STREAM, 0);
   
   struct sockaddr_in target;
   target.sin_family = AF_INET;
   target.sin_port = htons(1);
   target.sin_addr.s_addr = inet_addr(ip);
   
   int conn = connect(sock, (struct sockaddr *)&target, sizeof(target));
   if(conn == 0) {
      printf("[+] Port %d is open\n", 1);
   } else {
      printf("[-] Port %d is closed\n", 1);
   }
   
   for(int i=2;i<=65535;i++) {
      target.sin_port = htons(i);
      conn = connect(sock, (struct sockaddr *)&target, sizeof(target));
      if(conn == 0) {
         printf("[+] Port %d is open\n", i);
      } else {
         //printf("[-] Port %d is closed\n", i);
      }
   }
   
   printf("\nScan Completed!\n");
   close(sock);
   return 0;
}