//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
  // create socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  // check for errors in creating socket
  
  // initialize server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
  
  // connect to server
  int connection_result = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
  
  // check for errors in connecting to server
  
  // send HTTP request to server
  char *http_request = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
  int send_result = send(client_socket, http_request, strlen(http_request), 0);
  
  // check for errors in sending request
  
  // receive HTTP response from server
  char response_buffer[1024];
  int recv_result;
  while ((recv_result = recv(client_socket, response_buffer, 1024, 0)) > 0) {
    printf("%s", response_buffer);
    memset(response_buffer, 0, 1024);
  }
  
  // check for errors in receiving response
  
  // close socket
  close(client_socket);

  return 0;
}