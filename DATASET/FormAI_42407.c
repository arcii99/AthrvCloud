//FormAI DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  // Create socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set up server address
  struct sockaddr_in address = { 0 };
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind to socket
  if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen on socket
  if (listen(server_fd, BACKLOG) == -1) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port: %d\n", PORT);

  // Accept client connections
  while (1) {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
      perror("Accept failed");
      exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE] = { 0 };

    // Receive request
    if (recv(client_fd, buffer, BUFFER_SIZE, 0) == -1) {
      perror("Receive failed");
      exit(EXIT_FAILURE);
    }

    // Parse request method
    char* method = strtok(buffer, " ");
    if (method == NULL) {
      printf("Invalid request\n");
      continue;
    }

    char* url = strtok(NULL, " ");
    if (url == NULL) {
      printf("Invalid request\n");
      continue;
    }

    // Serve static files
    if (strcmp(method, "GET") == 0) {
      // Open file
      FILE* file = fopen(url+1, "r");
      if (file == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
      }

      // Get file size
      fseek(file, 0L, SEEK_END);
      long int file_size = ftell(file);
      fseek(file, 0L, SEEK_SET);

      // Allocate memory for file content
      char* file_content = malloc(file_size);
      if (file_content == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
      }

      // Read file content
      size_t bytes_read = fread(file_content, sizeof(char), file_size, file);
      if (bytes_read != file_size) {
        perror("File read failed");
        exit(EXIT_FAILURE);
      }

      // Send header
      char response_header[BUFFER_SIZE] = { 0 };
      sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", file_size);
      send(client_fd, response_header, strlen(response_header), 0);

      // Send file content
      send(client_fd, file_content, file_size, 0);

      // Close file and free memory
      free(file_content);
      fclose(file);
    }
    // Handle other request methods
    else {
      printf("Not implemented\n");
    }

    close(client_fd);
  }

  return 0;
}