//FormAI DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

int main(int argc, char const *argv[]) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *message = "Hello from server";
		
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
		
  // Attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
		
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
		
  // Binding socket to the address and port
  if (bind(server_fd, (struct sockaddr *)&address,
    sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
		
  // Listening for connections
  if (listen(server_fd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
		
  printf("Server is listening on port %d...\n", PORT);

  // Accepting new connections
  while(1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
      (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }
			
    // Sending message to client
    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent to client\n");
		
    valread = read(new_socket, buffer, 1024);
    printf("%s\n",buffer);
    memset(buffer, 0, sizeof buffer);
  }
  return 0;
}