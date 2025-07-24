//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
/*
Welcome to the Network Topology Mapper program!

This program uses sockets to perform a network scan and map the topology of a network. 
It is designed to run on a single machine, acting as a scanning node, and gather information 
about other machines that are connected to the network.

To use this program, you need to provide a list of IP addresses to scan. You can do that 
by providing a text file containing the IP addresses, one address per line.

The program will perform a series of network scans, gathering information about the devices 
that are connected to the network. It will then use that information to construct a map of 
the network topology.

Remember that network scanning can be a sensitive operation, and in some cases, may be 
considered unethical. Always seek permission before scanning any network, and make sure 
that your actions comply with the applicable laws and regulations. 

Happy scanning!

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants
#define MAX_ADDR_LEN 256  // Maximum length of an IP address string
#define MAX_HOSTNAME_LEN 256  // Maximum length of a hostname string
#define MAX_PORTS 100  // Maximum number of ports to scan
#define MAX_CONNECTIONS 100  // Maximum number of open connections
#define TIMEOUT_SECS 5  // Timeout in seconds for socket operations

// Functions declarations
bool scan_port(const char *ip_address, int port);
void resolve_address(const char *address, char *hostname);
bool is_ip_address(const char *address);

// Main function
int main(int argc, char *argv[]) {
  // Check the command-line arguments
  if (argc != 2) {
    printf("Usage: %s [input file]\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the input file
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Could not open input file\n");
    return EXIT_FAILURE;
  }

  // Read the list of IP addresses from the input file
  char ip_addresses[MAX_CONNECTIONS][MAX_ADDR_LEN];
  int num_addresses = 0;
  char line[MAX_ADDR_LEN];
  while (num_addresses < MAX_CONNECTIONS && fgets(line, MAX_ADDR_LEN, input_file) != NULL) {
    int len = strlen(line);
    if (len > 0 && line[len-1] == '\n') {
      line[len-1] = '\0';
    }
    if (is_ip_address(line)) {
      strcpy(ip_addresses[num_addresses], line);
      num_addresses++;
    }
  }

  // Close the input file
  fclose(input_file);

  // Scan the network
  bool connections[MAX_CONNECTIONS][MAX_CONNECTIONS] = {{false}};
  for (int i = 0; i < num_addresses; i++) {
    for (int j = 0; j < num_addresses; j++) {
      if (i != j) {
        for (int port = 1; port <= MAX_PORTS; port++) {
          if (scan_port(ip_addresses[i], port)) {
            connections[i][j] = true;
            break;
          }
        }
      }
    }
  }

  // Print the network map
  printf("Network Topology Map:\n");
  for (int i = 0; i < num_addresses; i++) {
    char hostname[MAX_HOSTNAME_LEN];
    resolve_address(ip_addresses[i], hostname);
    printf("%s (%s)\n", hostname, ip_addresses[i]);
    for (int j = 0; j < num_addresses; j++) {
      if (i != j && connections[i][j]) {
        char other_hostname[MAX_HOSTNAME_LEN];
        resolve_address(ip_addresses[j], other_hostname);
        printf("  -> %s (%s)\n", other_hostname, ip_addresses[j]);
      }
    }
  }

  return EXIT_SUCCESS;
}

// Scan a specific port on a given IP address
bool scan_port(const char *ip_address, int port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    return false;
  }

  // Set the socket options
  struct timeval timeout = {TIMEOUT_SECS, 0};
  setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

  // Construct the address of the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  server_addr.sin_port = htons(port);

  // Connect to the server
  int connect_result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  close(sockfd);
  if (connect_result < 0) {
    return false;
  }

  return true;
}

// Resolve an IP address or hostname to a hostname
void resolve_address(const char *address, char *hostname) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo *results;
  int status = getaddrinfo(address, NULL, &hints, &results);
  if (status != 0) {
    strcpy(hostname, address);
    return;
  }

  struct sockaddr_in *ip_addr = (struct sockaddr_in *)results->ai_addr;

  char ip_address_string[MAX_ADDR_LEN];
  inet_ntop(AF_INET, &(ip_addr->sin_addr), ip_address_string, MAX_ADDR_LEN);

  getnameinfo(results->ai_addr, results->ai_addrlen, hostname, MAX_HOSTNAME_LEN, NULL, 0, 0);

  freeaddrinfo(results);
}

// Check if a given string is an IP address
bool is_ip_address(const char *address) {
  struct sockaddr_in sa;
  int result = inet_pton(AF_INET, address, &(sa.sin_addr));
  return result != 0;
}