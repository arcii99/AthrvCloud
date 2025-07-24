//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define NUM_PORTS 100 // number of ports to scan
#define TIMEOUT 2 // timeout in seconds

// Function to check if a port is open
int is_open(int port) {
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(1);
  }

  struct timeval tv;
  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;

  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

  if (connect(sock, (struct sockaddr*)&server_addr, sizeof server_addr) == -1) {
    close(sock);
    return 0;
  }
  close(sock);
  return 1;
}

int main(int argc, char* argv[]) {
  printf("Hey there! Welcome to my Port Scanner program!\n");
  printf("I will scan the local machine for open ports\n");

  int open_ports[NUM_PORTS] = {0};
  int num_open = 0;

  for (int i = 0; i < NUM_PORTS; i++) {
    if (is_open(i)) {
      open_ports[num_open] = i;
      num_open++;
      printf(":) :) :) Port %d is open! :) :) :)\n", i);
    } else {
      printf(":| :| :| Port %d is not open :| :| :|\n", i);
    }
  }

  printf("\nI finished scanning! Here are the results:\n");
  if (num_open == 0) {
    printf(":( :( :( Sorry, no ports are open :( :( :(\n");
  } else {
    printf(":) :) :) Yay! %d ports are open! :) :) :)\n", num_open);
    printf(":) :) :) The open ports are: :) :) :)\n");
    for (int i = 0; i < num_open; i++) {
      printf(":) Port %d is open :) \n", open_ports[i]);
    }
  }

  printf("\nThanks for using my program! Have a great day! :)\n");
  return 0;
}