//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
   int client_fd;
   struct sockaddr_in server_addr;
   char buffer[MAX_BUFFER_SIZE];
   
   // Create socket
   if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
   }

   // Initialize server address
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(PORT);
   if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
      perror("address conversion error");
      exit(EXIT_FAILURE);
   }

   // Connect to server
   if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connection failed");
      exit(EXIT_FAILURE);
   }

   // Send message to server
   snprintf(buffer, MAX_BUFFER_SIZE, "%s", "Hello from client");
   if (send(client_fd, buffer, strlen(buffer), 0) == -1) {
      perror("sending failed");
      exit(EXIT_FAILURE);
   }

   // Receive message from server
   memset(buffer, 0, MAX_BUFFER_SIZE);
   if (recv(client_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
      perror("receiving failed");
      exit(EXIT_FAILURE);
   }
   printf("Received message from server: %s\n", buffer);

   // Close socket
   close(client_fd);
   return 0;
}