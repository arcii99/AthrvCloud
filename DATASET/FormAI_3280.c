//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  //initializing the required information
  int server_socket, new_socket;
  struct sockaddr_in server_address, client_address;
  char message[100] = "Hello client, glad to connect!\n";
  
  //creating a server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  //checking if the socket was created successfully
  if(server_socket == -1){
    printf("Oh no! The server socket cannot be created! Error code: %d\n", server_socket);
    exit(0);
  }
  
  printf("Server socket created successfully! Here's your socket id: %d\n", server_socket);
  
  //configuring the server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);
  
  //binding the socket to the server address
  if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
    printf("Oops! The binding failed. Please try again later... Error code: %d\n", server_socket);
    exit(0);
  }
  
  printf("Binding successful! Server address has been assigned.\n");
  
  //listening for incoming client connections
  listen(server_socket, 5);
  
  printf("Listening for incoming client connections...\n");
  
  //accepting incoming client connections
  int client_address_size = sizeof(client_address);
  new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size);
  
  if(new_socket < 0){
    printf("Looks like connection was not successful. Better luck next time! Error code: %d\n", new_socket);
    exit(0);
  }
  
  printf("Connection established with the client! Welcome to the server...\n");
  
  //sending a message to the client
  send(new_socket, message, sizeof(message), 0);
  
  //receiving a message from the client
  char client_message[100];
  recv(new_socket, client_message, sizeof(client_message), 0);
  
  printf("Client says: %s \n", client_message);
  
  //closing the sockets
  close(new_socket);
  close(server_socket);
  
  return 0;
}