//FormAI DATASET v1.0 Category: Simple Web Server ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
     int server_socket, new_socket, valread, status;
     struct sockaddr_in address;
     char buffer[BUFFER_SIZE] = {0};

     server_socket = socket(AF_INET, SOCK_STREAM, 0);
     if(server_socket == -1){
          printf("Error creating socket!\n");
          return -1;
     }

     memset(&address, '0', sizeof(address));
     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(PORT);

     status = bind(server_socket, (struct sockaddr *)&address, sizeof(address));
     if(status < 0){
          printf("Error in binding the socket!\n");
          return -1;
     }

     status = listen(server_socket, 10);
     if(status < 0){
          printf("Error in listening to the socket!\n");
          return -1;
     }

     printf("Simple Web Server started on port 8080!\n");

     while(1){
          new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&status);
          if(new_socket < 0){
               printf("Error in accepting the client request!\n");
               continue;
          }

          printf("Request received from client at %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

          valread = read(new_socket, buffer, BUFFER_SIZE);
          printf("%s\n", buffer);

          char response[1024] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>\n";
          send(new_socket, response, strlen(response), 0);

          close(new_socket);
     }

     close(server_socket);
     return 0;
}