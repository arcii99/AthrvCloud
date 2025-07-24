//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scientific
/* 
  Author: [Your Name]
  Date: [Date]

  A simple web server program in C language
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000

void handle_request(int client_socket) {
  char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
  send(client_socket, response, strlen(response), 0);
}

int main(int argc, char *argv[]) {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  int opt = 1;
  int addrlen = sizeof(server_addr);
  
  // create TCP socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  
  // set socket options
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }
  
  // bind socket to address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  
  // listen for incoming connections
  if (listen(server_socket, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }
  
  printf("Listening on port %d\n", PORT);
  
  // accept incoming connections
  while (1) {
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }
    
    printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    handle_request(client_socket);
    
    close(client_socket);
    printf("Connection closed\n");
  }
  
  close(server_socket);
  return 0;
}