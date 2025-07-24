//FormAI DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main() {
  int sock, new_sock;
  struct sockaddr_in addr;
  socklen_t addr_len = sizeof(addr);
  char buf[1024];

  // Create a TCP socket
  if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to the IP address
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, 5) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept incoming connections and display the data received
  while ((new_sock = accept(sock, (struct sockaddr *)&addr, &addr_len)) != -1) {
    memset(buf, '\0', sizeof(buf));
    recv(new_sock, buf, sizeof(buf), 0);
    printf("Received data: %s\n", buf);
    close(new_sock);
  }

  close(sock);
  return 0;
}