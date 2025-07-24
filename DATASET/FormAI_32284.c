//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
   // Create a socket for the client.
   int client_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (client_socket < 0) {
      perror("Unable to create socket!\n");
      exit(EXIT_FAILURE);
   }

   // Define the IP address and port of the server we want to connect to.
   struct sockaddr_in server_addr;
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(9999);
   server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

   // Try to connect to the server.
   if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
      perror("Unable to connect to server!\n");
      exit(EXIT_FAILURE);
   }

   // Send a message to the server.
   char message[100] = "Hello from the client!";
   if (send(client_socket, message, strlen(message), 0) < 0) {
      perror("Unable to send message!\n");
      exit(EXIT_FAILURE);
   }

   // Receive a message from the server.
   char buffer[100];
   if (recv(client_socket, buffer, sizeof(buffer), 0) < 0) {
      perror("Unable to receive message!\n");
      exit(EXIT_FAILURE);
   }

   // Print the message received from the server.
   printf("Message from server: %s\n", buffer);

   // Close the socket.
   close(client_socket);
   return 0;
}