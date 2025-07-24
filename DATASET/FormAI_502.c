//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HOST "www.google.com"
#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"

int main(int argc, char* argv[]) {
  int client_socket = socket(AF_INET, SOCK_STREAM, 0); //Create a TCP socket
  if (client_socket < 0) { //Check if the socket was correctly created
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_address; //Structure containing the server address and port
  memset(&server_address, 0, sizeof(server_address)); //Initialize the structure with 0s
  server_address.sin_family = AF_INET; //Set the address family to IPv4
  server_address.sin_port = htons(PORT); //Set the port to 80
  if (inet_pton(AF_INET, HOST, &server_address.sin_addr) <= 0) { //Convert the IP address to binary form
    perror("Unable to set server address");
    exit(EXIT_FAILURE);
  }

  if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) { //Connect to the server
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  if (send(client_socket, REQUEST, strlen(REQUEST), 0) < 0) { //Send the HTTP request
    perror("Error sending request");
    exit(EXIT_FAILURE);
  }

  char response[2048]; //Buffer to store the server response
  int bytes_received = recv(client_socket, response, sizeof(response), 0); //Receive the server response
  if (bytes_received < 0) { //Check if the response was correctly received
    perror("Error receiving response");
    exit(EXIT_FAILURE);
  }

  printf("Server response:\n%s\n", response); //Print the server response

  close(client_socket); //Close the socket

  return EXIT_SUCCESS; //Exit the program
}