//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 4096

int main(int argc, char const *argv[]) {

  int socket_fd;
  struct sockaddr_in server_address;
  char buffer[BUFFER_SIZE] = {0};
  
  // Create a socket
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("Cannot create socket");
      exit(EXIT_FAILURE);
  }

  // Set the server address and port
  memset(&server_address, '0', sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
    
  if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
      perror("Invalid address / Address not supported");
      exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
      perror("Cannot connect");
      exit(EXIT_FAILURE);
  }

  // Send the USER command
  char* user_cmd = "USER [username]\r\n";
  send(socket_fd , user_cmd , strlen(user_cmd) , 0);
  memset(buffer, 0, BUFFER_SIZE);
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("Response: %s", buffer);

  // Send the PASS command
  char* pass_cmd = "PASS [password]\r\n";
  send(socket_fd , pass_cmd , strlen(pass_cmd) , 0);
  memset(buffer, 0, BUFFER_SIZE);
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("Response: %s", buffer);

  // Send the STAT command
  char* stat_cmd = "STAT\r\n";
  send(socket_fd , stat_cmd , strlen(stat_cmd) , 0);
  memset(buffer, 0, BUFFER_SIZE);
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("Response: %s", buffer);

  // Send the LIST command
  char* list_cmd = "LIST\r\n";
  send(socket_fd , list_cmd , strlen(list_cmd) , 0);
  memset(buffer, 0, BUFFER_SIZE);
  recv(socket_fd, buffer, BUFFER_SIZE, 0);
  printf("Response: %s", buffer);
  
  // Close the connection
  close(socket_fd);
  return 0;
}