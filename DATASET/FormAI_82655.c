//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

int main(int argc, char *argv[]) 
{ 
  int socket_desc, new_socket, c; 
  struct sockaddr_in server, client; 
  char *message = "Hello from the server!"; 
  
  // Create server socket 
  socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
  if (socket_desc == -1) 
  { 
    printf("Could not create socket"); 
    return 1; 
  } 
  printf("Socket created successfully!\n"); 
  
  // Prepare sockaddr_in structure 
  server.sin_family = AF_INET; 
  server.sin_addr.s_addr = INADDR_ANY; 
  server.sin_port = htons(8888); 
  
  // Bind the socket to port 8888 
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) 
  { 
    perror("Bind failed"); 
    return 1; 
  } 
  printf("Successfully bind to port %d\n", ntohs(server.sin_port)); 
  
  // Listen for incoming connections 
  listen(socket_desc, 3); 
  
  // Accept incoming connection 
  c = sizeof(struct sockaddr_in); 
  new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c); 
  if (new_socket < 0) 
  { 
    perror("Accept failed"); 
    return 1; 
  } 
  printf("Connection accepted!\n"); 
  
  // Send hello message to the client 
  if (send(new_socket, message, strlen(message), 0) < 0) 
  { 
    printf("Send failed"); 
    return 1; 
  } 
  printf("Hello message sent to the client!\n"); 
  
  return 0; 
}