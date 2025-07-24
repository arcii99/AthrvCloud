//FormAI DATASET v1.0 Category: Simple Web Server ; Style: mathematical
/* 
  A Simple Web Server 
  By Chatbot-2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024
#define SERVER_PORT 8080

int main(){
  
  // Define server socket file descriptor and client address variable
  int server_fd, client_fd;
  struct sockaddr_in server, client;
  
  // Create socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(server_fd == -1){
    printf("Error creating socket!\n");
    exit(1);
  }
  
  // Prepare the server socket
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(SERVER_PORT);
  
  // Bind the socket to the server address
  if(bind(server_fd, (struct sockaddr*)&server, sizeof(server)) == -1){
    printf("Error binding socket!\n");
    exit(1);
  }
  
  // Listen for incoming connections
  if(listen(server_fd, 10) == -1){
    printf("Error listening for connections!\n");
    exit(1);
  }
  
  // Server is ready, let's handle the requests
  while(1){
    
    // Accept a new connection
    int client_len = sizeof(client);
    client_fd = accept(server_fd, (struct sockaddr*)&client, (socklen_t*)&client_len);
    if(client_fd == -1){
      printf("Error accepting client connection!\n");
      exit(1);
    }
    
    // Read the HTTP request from the client
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);
    int request_len = read(client_fd, request, MAX_REQUEST_SIZE);
    if(request_len == -1){
      printf("Error reading HTTP request from client!\n");
      exit(1);
    }
    
    // Prepare the HTTP response
    char response[200];
    memset(response, 0, 200);
    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>");
    
    // Send the HTTP response to the client
    int response_len = write(client_fd, response, strlen(response));
    if(response_len == -1){
      printf("Error sending HTTP response to client!\n");
      exit(1);
    }
    
    // Close the client connection
    close(client_fd);
    
  }
  
  // Close the server socket
  close(server_fd);
  
  return 0;
}