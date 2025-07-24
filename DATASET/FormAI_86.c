//FormAI DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

char *get_response(char *request) {
  // get the request method ("GET" or "POST")
  char *method = strtok(request, " ");
  
  // get the requested URL
  char *url = strtok(NULL, " ");
  if (url[strlen(url) - 1] == '/') {
    strcat(url, "index.html");
  }
  
  // get the HTTP version
  char *http_version = strtok(NULL, "\r\n");
  
  // prepare the response message
  char *response = malloc(BUFFER_SIZE);
  char *content = malloc(BUFFER_SIZE);
  char *header = malloc(BUFFER_SIZE);
  char *body = malloc(BUFFER_SIZE);
  
  sprintf(content, "<html><head><title>Welcome to my server!</title></head><body><h1>Hello, world!</h1><p>You requested the following URL: %s</p></body></html>", url);
  sprintf(header, "HTTP/1.1 200 OK\r\nContent-Length: %lu\r\nContent-Type: text/html\r\n", strlen(content));
  sprintf(body, "%s\r\n%s", header, content);
  strcpy(response, body);
  
  return response;
}

int main() {
  // create a socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // bind the socket to the specified address and port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(server_fd, 3) == -1) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d\n", PORT);

  while (1) {
    // accept a new connection
    int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address);
    if (client_fd == -1) {
      perror("accept failed");
      continue;
    }

    printf("New connection established\n");

    char buffer[BUFFER_SIZE] = {0};
    read(client_fd, buffer, BUFFER_SIZE);

    char *response = get_response(buffer);

    // send the response to the client
    send(client_fd, response, strlen(response), 0);

    // close the connection
    close(client_fd);
    free(response);
  }

  return 0;
}