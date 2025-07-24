//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
   int sock;
   struct sockaddr_in server;
   char message[1000], server_reply[2000];

   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock == -1) {
      printf("Could not create socket\n");
   }

   server.sin_addr.s_addr = inet_addr("127.0.0.1");
   server.sin_family = AF_INET;
   server.sin_port = htons(8888);

   if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
      perror("connect failed. Error");
      return 1;
   }

   printf("Connected\n");

   printf("Enter HTTP request:\n");
   fgets(message, 1000, stdin);

   if(send(sock, message, strlen(message), 0) < 0) {
      printf("Send failed\n");
      return 1;
   }

   if(recv(sock, server_reply, 2000, 0) < 0) {
      printf("Recv failed\n");
      return 1;
   }

   printf("Server reply:\n%s\n", server_reply);

   close(sock);
   return 0;
}