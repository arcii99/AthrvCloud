//FormAI DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  printf("Wow, I'm creating a C Chat server!\n");

  // Create the socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    printf("Uh oh, couldn't create the socket. Aborting...\n");
    return -1;
  }
  printf("Created the socket successfully!\n");

  // Bind the socket
  struct sockaddr_in server_address;
  memset(&server_address, '\0', sizeof(server_address));

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    printf("Woah, couldn't bind the socket. This is unexpected...\n");
    return -1;
  }
  printf("Bound the socket successfully!\n");

  // Start listening
  if (listen(server_socket, 5) < 0) {
    printf("Oh no, the server couldn't start listening. What a surprise...\n");
    return -1;
  }
  printf("Started listening to incoming connections!\n");

  // Accept incoming connections
  int client_socket, pid;
  struct sockaddr_in client_address;
  socklen_t client_address_length = sizeof(client_address);

  while (1) {
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
    if (client_socket < 0) {
      printf("Uh oh, couldn't accept the incoming connection. This is unexpected...\n");
      continue;
    }

    printf("New client connected! Handling their request...\n");

    // Fork a new process to handle the connection
    pid = fork();
    if (pid < 0) {
      printf("Yikes, we couldn't fork a new process. This is surprising...\n");
      return -1;
    }

    if (pid == 0) {
      // In child process, handle the client request
      char buffer[256];
      memset(buffer, '\0', sizeof(buffer));
      int message_size;

      while (1) {
        message_size = read(client_socket, buffer, sizeof(buffer));
        if (message_size < 0) {
          printf("Oops, couldn't read message from client. That's not good...\n");
          break;
        }

        if (message_size == 0) {
          printf("Client disconnected! This is actually a good surprise...\n");
          break;
        }

        printf("Client sent message: %s", buffer);
        write(client_socket, "I received your message! :)\n", 28);
      }
      close(client_socket);
      exit(0);
    }
    else {
      // In parent process, continue listening for connections
      close(client_socket);
    }
  }
  close(server_socket);
  return 0;
}