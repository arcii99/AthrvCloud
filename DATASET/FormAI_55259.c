//FormAI DATASET v1.0 Category: Client Server Application ; Style: complex
/* Complex C Client Server Application Example */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {

  /* Creating a Socket */
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  /* Binding the Socket to an IP Address and Port */
  if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }

  /* Listening for the Connection Request */
  if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }

  /* Accept the Connection Request */
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
  }

  /* Read the Message from the Client */
  valread = read( new_socket , buffer, 1024);
  printf("%s\n",buffer );
  char *hello = "Hello from Server";
  send(new_socket , hello , strlen(hello) , 0 );
  printf("Hello message sent\n");
  
  return 0;
}