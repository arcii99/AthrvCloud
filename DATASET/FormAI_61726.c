//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define PORT 8080
#define FILE_PATH "/var/www/html"   // The directory where server files are located

int main() {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUF_SIZE] = {0};

  // Creating a server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    return -1;
  }

  // Setting socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    perror("setsockopt");
    return -1;
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Binding the socket to the specified port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    return -1;
  }
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    return -1;
  }

  // Main loop
  while (1) {
    printf("Waiting for incoming connections...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                         (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      continue;
    }

    // Reading HTTP request from the client
    if ((valread = read(new_socket, buffer, BUF_SIZE)) > 0) {

      // Extracting the requested file path
      char* token = strtok(buffer, " ");
      token = strtok(NULL, " ");
      char file_path[BUF_SIZE];
      sprintf(file_path, "%s%s", FILE_PATH, token);
      int file_fd = open(file_path, O_RDONLY);

      // Checking if the file exists
      if (file_fd == -1) {
        char response[] = "HTTP/1.1 404 Not Found\nContent-Length: 21\n\nError 404: Not Found\n";
        send(new_socket, response, strlen(response), 0);
      } else {

        // Sending the contents of the file as the HTTP response
        char response[BUF_SIZE];
        int file_size = lseek(file_fd, 0, SEEK_END);
        sprintf(response, "HTTP/1.1 200 OK\nContent-Length: %d\n\n", file_size);
        send(new_socket, response, strlen(response), 0);

        lseek(file_fd, 0, SEEK_SET);
        int bytes_read;
        while ((bytes_read = read(file_fd, buffer, BUF_SIZE)) > 0) {
          send(new_socket, buffer, bytes_read, 0);
        }
        close(file_fd);
      }
    }

    // Closing the connection
    close(new_socket);
  }

  return 0;
}