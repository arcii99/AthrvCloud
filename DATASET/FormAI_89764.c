//FormAI DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535
#define MAX_BUFFER_SIZE 1024

void scan_ports(const char *hostname, int start_port, int end_port) {
  int sock, connection_status, port_num;
  struct sockaddr_in target;
  char buffer[MAX_BUFFER_SIZE];

  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET; // IPv4 address family
  target.sin_addr.s_addr = inet_addr(hostname);

  for (port_num = start_port; port_num <= end_port; port_num++) {
    target.sin_port = htons(port_num);
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Try to connect to the port
    connection_status = connect(sock, (struct sockaddr *)&target, sizeof(target));

    if (connection_status == 0) {
      sprintf(buffer, "Port %d is open on %s\n", port_num, hostname);
      write(STDOUT_FILENO, buffer, strlen(buffer));
    }

    close(sock);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s hostname\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *hostname = argv[1];
  int start_port = PORT_RANGE_START;
  int end_port = PORT_RANGE_END;

  scan_ports(hostname, start_port, end_port);

  return EXIT_SUCCESS;
}