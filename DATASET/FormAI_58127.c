//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sock_fd;
  struct sockaddr_in server_addr;
  char buffer[1024] = {0};

  // create socket
  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation error");
    exit(EXIT_FAILURE);
  }

  // set server address
  memset(&server_addr, '0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(21);

  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
    perror("Invalid address");
    exit(EXIT_FAILURE);
  }

  // connect to server
  if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }

  // send username and password
  char username[] = "user";
  char password[] = "pass";
  send(sock_fd, username, strlen(username), 0);
  send(sock_fd, password, strlen(password), 0);

  // send command to retrieve file
  char get_cmd[] = "get file.txt";
  send(sock_fd, get_cmd, strlen(get_cmd), 0);

  // create and open file for writing
  FILE *file = fopen("file.txt", "wb");

  // receive and write received data to file
  int bytes_received;
  while ((bytes_received = recv(sock_fd, buffer, sizeof(buffer), 0)) > 0) {
    fwrite(buffer, 1, bytes_received, file);
  }

  fclose(file);
  close(sock_fd);

  return 0;
}