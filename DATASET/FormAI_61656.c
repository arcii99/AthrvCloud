//FormAI DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char const *argv[]) {
  int server_socket, new_socket, client_len;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024] = {0};

  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    error("Error opening socket");
  }

  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    error("Error on binding");
  }

  listen(server_socket, 5);
  client_len = sizeof(client_addr);

  while(1) {
    if ((new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len)) < 0) {
      error("Error on accept");
    }

    char *client_ip = inet_ntoa(client_addr.sin_addr);
    printf("Connection established with client %s\n", client_ip);

    int pid = fork();

    if (pid < 0) {
      error("Error on fork");
    }

    if (pid == 0) {
      close(server_socket);

      while(1) {
        bzero(buffer, 1024);
        int n = read(new_socket, buffer, 1023);
        if (n < 0) {
          error("Error reading from socket");
        }
        printf("Client (%s): %s\n", client_ip, buffer);

        if (strncmp(buffer, "quit", 4) == 0) {
          printf("Closing connection with client %s\n", client_ip);
          break;
        }

        char response[1024];
        strcpy(response, "Server: ");
        strcat(response, buffer);
        n = write(new_socket, response, strlen(response));
        if (n < 0) {
          error("Error writing to socket");
        }
      }

      close(new_socket);
      exit(0);
    }

    else {
      close(new_socket);
    }
  }

  close(server_socket);
  return 0;
}