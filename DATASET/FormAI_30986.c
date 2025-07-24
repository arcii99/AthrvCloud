//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle each request
void handle_request(int client_socket)
{
  char buffer[BUFFER_SIZE] = {0};
  read(client_socket, buffer, BUFFER_SIZE);
  printf("Client request:\n%s", buffer);

  // Default response in case request cannot be handled
  char* response = "HTTP/1.1 400 Bad Request\nContent-Length: 0\n\n";
  int response_len = strlen(response);

  // Check if request is for the root directory
  if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0) {
    response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 159\n\n<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>Welcome to the apocalypse</title></head><body><h1>Welcome, survivor!</h1><p>After the apocalypse, the only way to communicate is through the internet. Luckily, this server is still running. Feel free to explore our wasteland.</p><ul><li><a href=\"/food\">Find food</a></li><li><a href=\"/shelter\">Find shelter</a></li><li><a href=\"/weapons\">Find weapons</a></li></ul></body></html>";
    response_len = strlen(response);
  }
  // Check if request is for finding food
  else if (strncmp(buffer, "GET /food HTTP/1.1", 18) == 0) {
    response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 55\n\n<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>Find food</title></head><body><h1>Find food</h1><p>Sorry, all food has been scavenged.</p></body></html>";
    response_len = strlen(response);
  }
  // Check if request is for finding shelter
  else if (strncmp(buffer, "GET /shelter HTTP/1.1", 21) == 0) {
    response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 61\n\n<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>Find shelter</title></head><body><h1>Find shelter</h1><p>Sorry, all shelters are full.</p></body></html>";
    response_len = strlen(response);
  }
  // Check if request is for finding weapons
  else if (strncmp(buffer, "GET /weapons HTTP/1.1", 21) == 0) {
    response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 72\n\n<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><title>Find weapons</title></head><body><h1>Find weapons</h1><p>Sorry, all weapons have been claimed.</p></body></html>";
    response_len = strlen(response);
  }

  // Send response to client
  send(client_socket, response, response_len, 0);

  // Close socket connection
  close(client_socket);
}

int main(int argc, char const *argv[])
{
  int server_fd, client_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  // Create server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind socket to IP address and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Start listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Loop forever to handle incoming requests
  while (1) {
    // Accept incoming connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    // Handle the request
    handle_request(client_socket);
  }

  return 0;
}