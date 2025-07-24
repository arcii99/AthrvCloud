//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Initializing the send and receive functions
void send_data(int sock, const char *data);
void receive_data(int sock);

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server;
  char message[1000];

  // Creating the socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error: Could not create socket");
    exit(1);
  }

  // Specifying the server address and port
  server.sin_addr.s_addr = inet_addr("192.168.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(8888);

  // Connecting to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Error: Connection failed");
    exit(1);
  }

  // Sending data to the server
  send_data(sock, "Hello, server! This is the client.");

  // Receiving data from the server
  receive_data(sock);

  // Closing the socket
  close(sock);

  return 0;
}

// Implementing the send function
void send_data(int sock, const char *data) {
  if (send(sock, data, strlen(data), 0) < 0) {
    printf("Error: Send failed");
    exit(1);
  }
  printf("Data sent successfully\n");
}

// Implementing the receive function
void receive_data(int sock) {
  char buffer[1000];
  int bytes_received;

  // Receiving data in chunks until the end of the message is reached
  while (1) {
    bytes_received = recv(sock, buffer, 1000, 0);
    if (bytes_received < 0) {
      printf("Error: Receive failed");
      exit(1);
    }
    if (bytes_received == 0) {
      break;
    }
    printf("%.*s", bytes_received, buffer);
  }
  printf("\nData received successfully\n");
}