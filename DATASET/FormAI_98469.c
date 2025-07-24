//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> 

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s server_ip username password\n", argv[0]);
    exit(1);
  }

  char *server_ip = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Failed to create socket");
    exit(1);
  }

  // Set up connection information
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(21);
  inet_pton(AF_INET, server_ip, &server_address.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
    perror("Failed to connect to server");
    exit(1);
  }

  // Read initial response from server
  char response[BUF_SIZE];
  memset(response, 0, sizeof(response));
  if (recv(sock, response, sizeof(response), 0) == -1) {
    perror("Failed to receive message from server");
    exit(1);
  }
  printf("%s", response);

  // Send username and password
  char user_cmd[BUF_SIZE];
  sprintf(user_cmd, "USER %s\r\n", username);
  if (send(sock, user_cmd, strlen(user_cmd), 0) == -1) {
    perror("Failed to send message to server");
    exit(1);
  }
  printf("%s", user_cmd);

  char pass_cmd[BUF_SIZE];
  sprintf(pass_cmd, "PASS %s\r\n", password);
  if (send(sock, pass_cmd, strlen(pass_cmd), 0) == -1) {
    perror("Failed to send message to server");
    exit(1);
  }
  printf("%s", pass_cmd);

  // Read response to authentication commands
  memset(response, 0, sizeof(response));
  if (recv(sock, response, sizeof(response), 0) == -1) {
    perror("Failed to receive message from server");
    exit(1);
  }
  printf("%s", response);

  // Begin main loop
  while (1) {
    printf("ftp> ");
    char command[BUF_SIZE];
    fgets(command, sizeof(command), stdin);
    
    // Remove trailing newline
    command[strcspn(command, "\n")] = 0;

    // Send command to server
    char full_cmd[BUF_SIZE];
    sprintf(full_cmd, "%s\r\n", command);
    if (send(sock, full_cmd, strlen(full_cmd), 0) == -1) {
      perror("Failed to send message to server");
      exit(1);
    }

    // Read response from server and print to console
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) == -1) {
      perror("Failed to receive message from server");
      exit(1);
    }
    printf("%s", response);

    // If command was "quit", exit program
    if (strncmp(command, "quit", 4) == 0) {
      break;
    }
  }

  // Close socket and exit program
  close(sock);
  return 0;
}