//FormAI DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define PORT 8080  

int main()  
{  
  int sockfd, new_sockfd; 
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr; 
  socklen_t client_len;
  char buffer[1024];
  int n;

  sockfd = socket(AF_INET, SOCK_STREAM, 0); 

  bzero(&server_addr, sizeof(server_addr)); 
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY; 

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {  
    printf("Failed to bind to port %d\n", PORT);  
    return 1;  
  }  

  if (listen(sockfd, 10) != 0) {  
    printf("Failed to listen on socket\n");  
    return 1;  
  }  

  printf("Server running on port %d\n", PORT);

  while (1) {  
    client_len = sizeof(client_addr); 
    new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len); 

    if (new_sockfd < 0) {  
      printf("Error accepting client connection\n");  
      continue;  
    }  

    printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    bzero(buffer, sizeof(buffer)); 

    n = read(new_sockfd, buffer, 1024); 

    if (n < 0) {  
      printf("Error reading from socket\n");  
      close(new_sockfd);  
      continue;  
    }  

    if (strcmp(buffer, "Hello") == 0) {  
      write(new_sockfd, "Hi there!", 9); 
    } else if (strcmp(buffer, "What is your name?") == 0) {
      write(new_sockfd, "My name is curious_server!", 26);
    } else {  
      write(new_sockfd, "I don't understand...", 21); 
    } 

    close(new_sockfd); // Close the connection with the client  
  }  

  close(sockfd); // Close the server socket  
  return 0;
}