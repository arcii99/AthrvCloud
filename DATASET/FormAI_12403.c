//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sockfd, new_sockfd, valread;
  struct sockaddr_in address;
  int opt = 1;
  int address_len = sizeof(address);
  char buffer[1024] = {0};

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Setsock option failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(sockfd, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  if ((new_sockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&address_len)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  int a = 5, b = 10, c = 15;
  send(new_sockfd, &a, sizeof(a), 0);
  send(new_sockfd, &b, sizeof(b), 0);
  send(new_sockfd, &c, sizeof(c), 0);

  int sum = a + b + c;
  send(new_sockfd, &sum, sizeof(sum), 0);

  float d = 1.1, e = 2.2, f = 3.3;
  send(new_sockfd, &d, sizeof(d), 0);
  send(new_sockfd, &e, sizeof(e), 0);
  send(new_sockfd, &f, sizeof(f), 0);

  float avg = (d + e + f) / 3;
  send(new_sockfd, &avg, sizeof(avg), 0);

  char message[20] = "Hello, Client!";
  send(new_sockfd, message, strlen(message), 0);

  valread = read(new_sockfd, buffer, 1024);
  printf("%s\n", buffer);

  close(new_sockfd);
  close(sockfd);

  return 0;
}