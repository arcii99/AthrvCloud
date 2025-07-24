//FormAI DATASET v1.0 Category: Client Server Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_NUMBER 12345
#define BUFFER_SIZE 1024

// function to handle communication with the client
void handle_client(int client_sockfd) {
  char buffer[BUFFER_SIZE];
  int n;

  bzero(buffer, BUFFER_SIZE);
  n = read(client_sockfd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  
  printf("Received message from client: %s", buffer);
  
  // send a response message to the client
  char response[BUFFER_SIZE] = "Received your message! Thanks for using our server.\n";
  n = write(client_sockfd, response, strlen(response));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  printf("Response message sent to client.\n");
}

int main(int argc, char *argv[]) {
  int sockfd, client_sockfd, pid;
  socklen_t clilen;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in serv_addr, cli_addr;

  // create a socket for the server
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }
  
  // set the server address structure
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT_NUMBER);
  
  // bind the server socket to the address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }
  printf("Server started on port %d.\n", PORT_NUMBER);
  
  // listen for incoming client connection requests
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  
  while(1) {
    // accept a incoming client connection
    client_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (client_sockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }
    
    // create a child process to handle communication with the client
    pid = fork();
    if (pid < 0) {
      perror("ERROR on fork");
      exit(1);
    }
    if (pid == 0) {
      // child process
      close(sockfd);
      handle_client(client_sockfd);
      exit(0);
    } else {
      // parent process
      close(client_sockfd);
    }
  }
  
  close(sockfd);
  return 0;
}