//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
   int socket_desc, new_socket, c;
   struct sockaddr_in server, client;
   char *message, client_reply[2000];

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
   if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
      perror("bind failed. Error");
      return 1;
   }

   // Listen
   listen(socket_desc, 3);

   // Print a message to console
   puts("Waiting for incoming connections...");

   c = sizeof(struct sockaddr_in);
   new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &c);
   if (new_socket < 0) {
      perror("accept failed");
      return 1;
   }

   // Send some messages to the client
   message = "Greetings! I am your connection handler";
   write(new_socket, message, strlen(message));

   message = "\nNow type something and I shall repeat what you type...";
   write(new_socket, message, strlen(message));

   // Receive a message from the client
   while (recv(new_socket, client_reply, 2000, 0) > 0) {

      // Reply to the client
      printf("Client: %s\n", client_reply);
      write(new_socket, client_reply, strlen(client_reply));

      // Clear the buffer
      memset(client_reply, 0, 2000);
   }

   if (new_socket < 0) {
      perror("recv failed");
   }

   return 0;
}