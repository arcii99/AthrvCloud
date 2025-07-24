//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8000

int main() {
   int listen_sock, comm_sock, bytes_read, fd;
   struct sockaddr_in servaddr;
   char buffer[BUFFER_SIZE], http_response[BUFFER_SIZE];

   // Create a socket.
   if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("Socket creation failed.");
      exit(EXIT_FAILURE);
   }

   // Set socket options.
   int opt = 1;
   if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("Setsockopt failed.");
      exit(EXIT_FAILURE);
   }

   // Bind the socket to a port.
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = INADDR_ANY;
   servaddr.sin_port = htons(SERVER_PORT);
   if (bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      perror("Bind failed.");
      exit(EXIT_FAILURE);
   }

   // Start listening for incoming connections.
   if (listen(listen_sock, 5) < 0) {
      perror("Listen failed.");
      exit(EXIT_FAILURE);
   }

   // Accept incoming connections and serve requests.
   while (1) {
      comm_sock = accept(listen_sock, (struct sockaddr *)NULL, NULL);
      if (comm_sock < 0) {
         perror("Accept failed.");
         continue;
      }

      // Read the request from the client.
      memset(buffer, 0, BUFFER_SIZE);
      bytes_read = read(comm_sock, buffer, BUFFER_SIZE);
      if (bytes_read < 0) {
         perror("Read failed.");
         continue;
      }

      // Get the path of the requested file.
      char *file_path_start = strchr(buffer, ' ') + 1;
      if (file_path_start == NULL) {
         sprintf(http_response, "HTTP/1.1 400 Bad Request\r\n\r\n");
         write(comm_sock, http_response, strlen(http_response));
         close(comm_sock);
         continue;
      }
      char *file_path_end = strchr(file_path_start, ' ');
      if (file_path_end == NULL) {
         sprintf(http_response, "HTTP/1.1 400 Bad Request\r\n\r\n");
         write(comm_sock, http_response, strlen(http_response));
         close(comm_sock);
         continue;
      }
      *file_path_end = '\0';

      // Open the requested file.
      fd = open(file_path_start, O_RDONLY);
      if (fd < 0) {
         sprintf(http_response, "HTTP/1.1 404 Not Found\r\n\r\n");
         write(comm_sock, http_response, strlen(http_response));
         close(comm_sock);
         continue;
      }

      // Serve the file contents to the client.
      memset(http_response, 0, BUFFER_SIZE);
      sprintf(http_response, "HTTP/1.1 200 OK\r\n\r\n");
      write(comm_sock, http_response, strlen(http_response));
      memset(buffer, 0, BUFFER_SIZE);
      while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
         write(comm_sock, buffer, bytes_read);
      }

      // Cleanup.
      close(fd);
      close(comm_sock);
   }

   return 0;
}