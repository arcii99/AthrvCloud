//FormAI DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

  int socket_desc, client_sock, c, read_size, i;
  struct sockaddr_in server, client;
  char *message, client_message[2000];

  // Create socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }

  // Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8888);

  // Bind
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    puts("bind failed");
    return 1;
  }
  puts("bind done");

  // Listen
  listen(socket_desc, 3);

  // Accept and incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);

  while (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) {
    puts("Connection accepted");

    // Send some messages to the client
    message = "Welcome to my unique networking example program in C!\n";
    write(client_sock, message, strlen(message));

    message = "Type in your message and hit enter. I will echo it back to you!\n";
    write(client_sock, message, strlen(message));

    // Receive a message from client
    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0 ) {

      // Print the message received from client
      printf("Message from client: %s\n", client_message);

      // Echo it back to client
      write(client_sock, client_message, strlen(client_message));
      memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
      puts("Client disconnected");
      fflush(stdout);
    } else if (read_size == -1) {
      puts("recv failed");
    }
  }

  return 0;
}