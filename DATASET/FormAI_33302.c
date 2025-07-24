//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DEVICES 100
#define MAX_IP_LENGTH 16

typedef struct {
  char* name;
  char* ip_address;
  int port;
} Device;

int n_devices = 0;
Device devices[MAX_DEVICES];

void add_device(char* name, char* ip_address, int port) {
  if (n_devices < MAX_DEVICES) {
    devices[n_devices].name = name;
    devices[n_devices].ip_address = ip_address;
    devices[n_devices].port = port;
    n_devices++;
    printf("Device %s added successfully.\n", name);
  } else {
    printf("Cannot add device. Maximum number of devices reached.\n");
  }
}

int main() {
  // Add devices manually for testing purposes
  add_device("Router", "192.168.1.1", 8080);
  add_device("Switch", "192.168.1.2", 8081);
  add_device("Server", "192.168.1.3", 8082);

  // Create socket
  int sockfd;
  struct sockaddr_in sa;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Set socket address
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr = htonl(INADDR_ANY);
  sa.sin_port = htons(0);

  // Bind socket
  if (bind(sockfd, (struct sockaddr*)&sa, sizeof(sa)) < 0) {
    perror("Error binding socket");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Get port number
  socklen_t sa_len = sizeof(sa);
  if (getsockname(sockfd, (struct sockaddr*)&sa, &sa_len) < 0) {
    perror("Error getting port number");
    close(sockfd);
    return EXIT_FAILURE;
  }
  int port = ntohs(sa.sin_port);
  printf("Listening on port %d...\n", port);

  // Listen for incoming connections
  if (listen(sockfd, 10) < 0) {
    perror("Error listening for connections");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    printf("Waiting for incoming connection...\n");
    int client_fd = accept(sockfd, NULL, NULL);
    printf("New connection established.\n");
    close(client_fd);
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}