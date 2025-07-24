//FormAI DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  char *hostname = "www.google.com";
  struct hostent *host_info;
  struct sockaddr_in address;
  int sock, status, timeout = 3;

  // Use getopt to parse command line arguments.
  int opt = 0;
  while ((opt = getopt(argc, argv, "h:t:")) != -1) {
    switch(opt) {
      case 'h':
        hostname = optarg;
        break;
      case 't':
        timeout = atoi(optarg);
        break;
    }
  }

  // Get IP address of the host.
  host_info = gethostbyname(hostname);
  if (host_info == NULL) {
    fprintf(stderr, "Error: Could not resolve host %s.\n", hostname);
    return 1;
  }

  // Set up the address struct.
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr = *((struct in_addr *) host_info->h_addr_list[0]);
  address.sin_port = htons(0);

  // Create socket.
  sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock < 0) {
    fprintf(stderr, "Error: Could not create socket.\n");
    return 1;
  }

  // Set socket options.
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
  setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

  // Connect to host.
  status = connect(sock, (struct sockaddr *) &address, sizeof(address));
  if (status < 0) {
    fprintf(stderr, "Error: Could not connect to host %s.\n", hostname);
    close(sock);
    return 1;
  }

  printf("Successfully connected to %s! Starting ping test...\n", hostname);

  // Ping test loop.
  int i;
  for (i = 1; i <= 10; i++) {
    printf("Pinging %s [%s], attempt %d...\n", hostname, inet_ntoa(address.sin_addr), i);

    // Send and receive ping message.
    const char *ping_msg = "ping";
    char recv_buf[1024];
    send(sock, ping_msg, strlen(ping_msg), 0);
    int recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);

    // Check if ping message was received.
    if (recv_len > 0) {
      printf("Ping response received from %s: %s\n", hostname, recv_buf);
    } else {
      printf("Error: No response received from %s.\n", hostname);
    }

    // Sleep for 1 second before next ping.
    sleep(1);
  }

  printf("Ping test complete. Closing socket.\n");

  // Close socket.
  close(sock);

  return 0;
}