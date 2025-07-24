//FormAI DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080

int main(int argc, char *argv[]){
  int server_socket = 0, valread;
  struct sockaddr_in server_address;

  char *hello = "Hello from server";
  char buffer[1024] ={0};

  // Creating socket file descriptor
  if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
      perror("Socket creation has failed");
      exit(EXIT_FAILURE);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Forcefully attaching socket to the port 
  if( bind(server_socket, (struct sockaddr *)&server_address,sizeof(server_address)) < 0 ){
      perror("Binding has failed");
      exit(EXIT_FAILURE);
  }

  if (listen(server_socket, 3) < 0){
      perror("Error listening");
      exit(EXIT_FAILURE);
  }
  printf("Listening on port: %d \n", PORT);

  int client_socket;
  struct sockaddr_in client_address;
  int client_address_length = sizeof(client_address);

  if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length))<0){
      perror("Error accepting connection");
      exit(EXIT_FAILURE);
  }

  char *ip = inet_ntoa(client_address.sin_addr);
  printf("Connection established with %s:%d\n", ip, ntohs(client_address.sin_port));

  valread = read(client_socket , buffer, 1024);
  if(valread > 0){
    printf("Message received: %s\n", buffer);
  }

  write(client_socket , hello , strlen(hello));
  printf("Hello message sent\n");
  return 0;
}