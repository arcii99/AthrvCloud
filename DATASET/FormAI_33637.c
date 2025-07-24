//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
  // Create a socket for the client
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
  {
    perror("Error: Socket creation failed");
    return EXIT_FAILURE;
  }

  // Set the IP address and port of the server to connect to
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

  // Connect to the server
  int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
  if (connection_status != 0)
  {
    perror("Error: Failed to connect to the server");
    return EXIT_FAILURE;
  }

  // Build the HTTP request
  char request[1024] = "";
  strcat(request, "GET / HTTP/1.1\r\n");
  strcat(request, "Host: localhost\r\n");
  strcat(request, "Connection: close\r\n");
  strcat(request, "\r\n");

  // Send the HTTP request to the server
  int send_status = send(client_socket, request, strlen(request), 0);
  if (send_status == -1)
  {
    perror("Error: Failed to send HTTP request");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response from the server
  char response[4096] = "";
  int receive_status = recv(client_socket, response, sizeof(response), 0);
  if (receive_status == -1)
  {
    perror("Error: Failed to receive HTTP response");
    return EXIT_FAILURE;
  }

  // Print the HTTP response from the server
  printf("HTTP Response from the server:\n%s", response);

  // Close the socket
  close(client_socket);

  return EXIT_SUCCESS;
}