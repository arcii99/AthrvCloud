//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

void error_handler(const char *msg) {
   perror(msg);
   exit(EXIT_FAILURE);
}

void sig_handler(int sig) {
   printf("Signal %d received, closing socket and terminating program...\n", sig);
   exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
   if (signal(SIGINT, sig_handler) == SIG_ERR) {
       error_handler("Error registering signal handler");
   }

   int server_fd, client_fd;
   struct sockaddr_in server_addr, client_addr;

   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       error_handler("Error creating socket");
   }

   memset(&server_addr, 0, sizeof(server_addr));

   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(8080);

   if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
       error_handler("Error binding socket");
   }

   if (listen(server_fd, SOMAXCONN) == -1) {
       error_handler("Error listening on socket");
   }

   printf("Socket is now listening on port %d\n", ntohs(server_addr.sin_port));

   while (1) {
       socklen_t client_len = sizeof(client_addr);

       client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

       if (client_fd == -1) {
           error_handler("Error accepting client connection");
       }

       char client_ip[INET_ADDRSTRLEN];

       if (inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN) == NULL) {
           error_handler("Error converting client address to string");
       }

#define RESPONSE_BODY   "<html><head><title>Welcome to my server</title></head><body><h1>Hello from my server!</h1></body></html>"

       char response[512];
       snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\n"
                                            "Content-Type: text/html\r\n"
                                            "Content-Length: %lu\r\n"
                                            "Connection: close\r\n"
                                            "\r\n"
                                            "%s",
                                            strlen(RESPONSE_BODY), RESPONSE_BODY);

       if (send(client_fd, response, strlen(response), 0) == -1) {
           error_handler("Error sending response to client");
       }

       close(client_fd);
   }

   return 0;
}