//FormAI DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void print_usage() {
  printf("usage: portscan [IP address]\n");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    print_usage();
    return 1;
  }

  char *ip_address = argv[1];
  printf("Scanning for open ports on %s...\n", ip_address);

  int ivalid_ip = inet_addr(ip_address);
  if (ivalid_ip == -1) {
    printf("Invalid IP address: %s\n", ip_address);
    return 1;
  }

  int socket_desc;
  struct sockaddr_in server;
  for (int port = 1; port < 65536; port++) {
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
      printf("Could not create socket\n");
      return 1;
    }

    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
      close(socket_desc);
      continue;
    }

    printf("Port %d is open on %s\n", port, ip_address);
    close(socket_desc);
  }

  printf("Port scanning completed\n");
  return 0;
}