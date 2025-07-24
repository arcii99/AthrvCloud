//FormAI DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, new_sockfd, max_fd, activity, i, valread, sd, bytes_sent, file_fd;
  struct sockaddr_in address;
  struct sockaddr_storage remoteaddr;
  socklen_t addrlen;
  char buffer[BUFFER_SIZE], filename[255], send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE], *c;
  fd_set readfds;
  int opt = 1;
  int flags;
  int client_sockets[MAX_CLIENTS];
  int num_clients = 0;
  
  // Create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }
  
  // Set socket options
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }

  // Set non-blocking socket
  flags = fcntl(sockfd, F_GETFL, 0);
  fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  // Bind socket to address
  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }
  
  // Listen for connections
  if (listen(sockfd, MAX_CLIENTS) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }
  
  // Initialize client sockets array
  memset(client_sockets, 0, sizeof(client_sockets));

  while (1) {
      // Clear the file descriptor set
      FD_ZERO(&readfds);
    
      // Add the server socket to the file descriptor set
      FD_SET(sockfd, &readfds);
      max_fd = sockfd;

      // Add the client sockets to the file descriptor set
      for (i = 0; i < MAX_CLIENTS; i++) {
          sd = client_sockets[i];

          // If valid socket descriptor then add to read list
          if(sd > 0) {
              FD_SET(sd, &readfds);
          }

          // Highest file descriptor number, need it for select function
          if(sd > max_fd) {
              max_fd = sd;
          }
      }

      // Wait for activity on one or more sockets
      activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);

      if ((activity < 0) && (errno!=EINTR)) {
          printf("Select error");
      }

      // New connection
      if (FD_ISSET(sockfd, &readfds)) {
          addrlen = sizeof(remoteaddr);
          new_sockfd = accept(sockfd, (struct sockaddr *)&remoteaddr, &addrlen);

          if (new_sockfd < 0) {
              perror("accept");
              exit(EXIT_FAILURE);
          }

          // Set non-blocking socket
          flags = fcntl(new_sockfd, F_GETFL, 0);
          fcntl(new_sockfd, F_SETFL, flags | O_NONBLOCK);

          // Add new socket to array of client sockets
          for (i = 0; i < MAX_CLIENTS; i++) {
              if (client_sockets[i] == 0) {
                  client_sockets[i] = new_sockfd;
                  num_clients++;
                  break;
              }
          }
      }

      // Check client sockets for activity
      for (i = 0; i < MAX_CLIENTS; i++) {
          sd = client_sockets[i];

          if (FD_ISSET(sd, &readfds)) {
              // Check if socket was disconnected
              if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                  // Client disconnected
                  close(sd);
                  client_sockets[i] = 0;
                  num_clients--;

              // Process message from client
              } else {
                  buffer[valread] = '\0';
                  if (strstr(buffer, "open")) {
                      // Extract filename from message
                      c = strchr(buffer, ' ');
                      strcpy(filename, c+1);
                      // Open file for editing
                      file_fd = open(filename, O_RDWR);
                      if (file_fd < 0) {
                          sprintf(send_buffer, "Error opening file: %s", strerror(errno));
                      } else {
                          sprintf(send_buffer, "File opened for editing: %s", filename);
                      }
                      // Send response to client
                      bytes_sent = send(sd, send_buffer, strlen(send_buffer), 0);
                  } else if (strstr(buffer, "read")) {
                      // Read file
                      int num_bytes = read(file_fd, recv_buffer, BUFFER_SIZE-1);
                      if (num_bytes < 0) {
                          sprintf(send_buffer, "Error reading file: %s", strerror(errno));
                      } else {
                          recv_buffer[num_bytes] = '\0';
                          sprintf(send_buffer, "%s", recv_buffer);
                      }
                      // Send response to client
                      bytes_sent = send(sd, send_buffer, strlen(send_buffer), 0);
                  } else if (strstr(buffer, "write")) {
                      // Extract data to be written from message
                      c = strchr(buffer, ' ');
                      c++;
                      // Write data to file
                      int num_bytes = write(file_fd, c, strlen(c));
                      if (num_bytes < 0) {
                          sprintf(send_buffer, "Error writing to file: %s", strerror(errno));
                      } else {
                          sprintf(send_buffer, "Data written to file: %s", c);
                      }
                      // Send response to client
                      bytes_sent = send(sd, send_buffer, strlen(send_buffer), 0);
                  } else if (strstr(buffer, "close")) {
                      // Close file and reset file descriptor
                      close(file_fd);
                      file_fd = -1;
                      sprintf(send_buffer, "File closed");
                      // Send response to client
                      bytes_sent = send(sd, send_buffer, strlen(send_buffer), 0);
                  }
              }
          }
      }
  }

  // Close server socket
  close(sockfd);

  return 0;
}