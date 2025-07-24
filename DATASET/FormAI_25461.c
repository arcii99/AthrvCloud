//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define PORT 8888

int main() {

     int sock = 0, valread;
     struct sockaddr_in serv_addr;
     char *message = "Hello from the other side!";
     char buffer[1024] = {0};

     // Creating socket file descriptor
     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
         printf("\n Socket creation error \n");
         return -1;
     }

     memset(&serv_addr, '0', sizeof(serv_addr));

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_port = htons(PORT);

     // Convert IPv4 and IPv6 addresses from text to binary form
     if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
         printf("\nInvalid address/ Address not supported \n");
         return -1;
     }

     // Connect the socket to the server address
     if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
         printf("\nConnection Failed \n");
         return -1;
     }

     // Send a message to the server
     send(sock , message , strlen(message) , 0 );
     printf("[*]Message sent to the server!\n");

     // Receive response from the server
     valread = recv( sock , buffer, 1024, 0);
     printf("[*]Server response: %s\n", buffer );

     return 0;
 }