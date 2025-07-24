//FormAI DATASET v1.0 Category: Networking ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 1337
#define MAX_DATA_SIZE 1024

int main() {
  int sockfd, new_sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_DATA_SIZE];
  socklen_t client_len;

  sockfd = socket(AF_INET, SOCK_STREAM, 0); // create a new socket
  if (sockfd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // set server address struct
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(sockfd, 10) == -1) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    printf("Waiting for a knight...\n");

    // accept a new connection
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (new_sockfd == -1) {
      perror("accept failed");
      continue;
    }

    printf("A knight has arrived!\n");

    while (1) {
      memset(buffer, 0, MAX_DATA_SIZE);
      ssize_t bytes_read = read(new_sockfd, buffer, MAX_DATA_SIZE);

      if (bytes_read == -1) {
        perror("read error");
        close(new_sockfd);
        break;
      } else if (bytes_read == 0) {
        printf("The knight has retreated\n");
        close(new_sockfd);
        break;
      } else {
        printf("The knight shouts: %s\n", buffer);

        // lowercase the message
        for (int i = 0; i < strlen(buffer); i++) {
          buffer[i] = tolower(buffer[i]);
        }

        // send the message back to the knight
        if (send(new_sockfd, buffer, MAX_DATA_SIZE, 0) == -1) {
          perror("send failed");
          close(new_sockfd);
          break;
        }
      }
    }
  }

  close(sockfd);
  return 0;
}