//FormAI DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    
#include <unistd.h>    
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>  
#include <netdb.h>      
#include <errno.h>     

#define PORT 7878
#define MAX_CLIENTS 10
#define MAX_DATA_SIZE 1024

int main() {

  // Initialize variables
  int sockfd, newsockfd, client_sockets[MAX_CLIENTS], max_sd, i, activity, valread, sd;
  struct sockaddr_in serv_addr;
  char buffer[MAX_DATA_SIZE];
  fd_set readfds;

  // Create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR: Failed to open socket");
    exit(EXIT_FAILURE);
  }

  // Set up the server address struct
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR: Failed to bind socket to address");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sockfd, MAX_CLIENTS) < 0) {
    perror("ERROR: Failed to listen for incoming connections");
    exit(EXIT_FAILURE);
  }

  // Initialize client socket descriptors to 0
  for (i = 0; i < MAX_CLIENTS; i++) {
    client_sockets[i] = 0;
  }

  printf("Server is listening on port %d\n", PORT);

  while (1) {
    // Clear the file descriptor set
    FD_ZERO(&readfds);

    // Add the server socket to the file descriptor set
    FD_SET(sockfd, &readfds);
    max_sd = sockfd;

    // Add the active client sockets to the file descriptor set
    for (i = 0; i < MAX_CLIENTS; i++) {
      sd = client_sockets[i];

      if (sd > 0) {
        FD_SET(sd, &readfds);
      }

      if (sd > max_sd) {
        max_sd = sd;
      }
    }

    // Wait for activity on any socket in the set
    activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
    if ((activity < 0) && (errno!=EINTR)) {
      perror("ERROR: Failed to wait for activity on socket");
    }

    // Check for incoming connections
    if (FD_ISSET(sockfd, &readfds)) {
      if ((newsockfd = accept(sockfd, (struct sockaddr*) NULL, NULL)) < 0) {
        perror("ERROR: Failed to accept incoming connection");
        exit(EXIT_FAILURE);
      }

      // Add the new client socket to the array of sockets
      for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == 0) {
          client_sockets[i] = newsockfd;
          printf("New client connected: socket fd %d\n", newsockfd);
          break;
        }
      }
    }

    // Check for incoming data
    for (i = 0; i < MAX_CLIENTS; i++) {
      sd = client_sockets[i];

      if (FD_ISSET(sd, &readfds)) {
        if ((valread = read(sd, buffer, MAX_DATA_SIZE)) == 0) {
          // Disconnect the client
          getpeername(sd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
          printf("Client disconnected %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
          close(sd);
          client_sockets[i] = 0;
        } else {
          buffer[valread] = '\0';
          printf("Received message from client fd %d: %s\n", sd, buffer);

          // Echo the message back to the client
          write(sd, buffer, strlen(buffer));
        }
      }
    }
  }

  return 0;
}