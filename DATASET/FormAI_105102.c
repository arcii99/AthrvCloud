//FormAI DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

  // creating socket
  int server_fd;
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Error: Socket creation failed\n");
    return 0;
  }

  // prepare server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // bind socket to address
  if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Error: Bind failed\n");
    return 0;
  }

  // listen for incoming requests
  if (listen(server_fd, 3) < 0) {
    printf("Error: Listen failed\n");
    return 0;
  }

  // accept client connection
  int client_fd;
  struct sockaddr_in client_address;
  int address_len = sizeof(client_address);
  if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) < 0) {
    printf("Error: Accept failed\n");
    return 0;
  }

  // receive request
  char buffer[BUFFER_SIZE] = {0};
  int read_result;
  if ((read_result = read(client_fd, buffer, BUFFER_SIZE)) < 0) {
    printf("Error: Read failed\n");
    close(client_fd);
    close(server_fd);
    return 0;
  }

  // parse request
  char *request_type = strtok(buffer, " ");
  char *file_path = strtok(NULL, " ");
  char *file_name = strtok(file_path, "/");
  file_name = strtok(NULL, "/");

  // open file
  FILE *file;
  file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error: File not found\n");
    close(client_fd);
    close(server_fd);
    return 0;
  }

  // calculate file size
  fseek(file, 0L, SEEK_END);
  int file_size = ftell(file);
  fseek(file, 0L, SEEK_SET);

  // prepare response header
  char header[BUFFER_SIZE] = {0};
  sprintf(header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", file_size);

  // send response header
  if (send(client_fd, header, strlen(header), 0) < 0) {
    printf("Error: Send failed\n");
    fclose(file);
    close(client_fd);
    close(server_fd);
    return 0;
  }

  // send file content
  char file_buffer[BUFFER_SIZE];
  int bytes_read;
  while ((bytes_read = fread(file_buffer, 1, BUFFER_SIZE, file)) > 0) {
    if (send(client_fd, file_buffer, bytes_read, 0) < 0) {
      printf("Error: Send failed\n");
      fclose(file);
      close(client_fd);
      close(server_fd);
      return 0;
    }
  }

  // close file and sockets
  fclose(file);
  close(client_fd);
  close(server_fd);

  return 0;
}