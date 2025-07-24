//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>

#define MAX_PORT_SIZE 10
#define MAX_IP_SIZE 16

//Function to display usage message
void usage() {
  printf("\nUsage: wireless_network_scanner <options>\n");
  printf("\nOptions:\n");
  printf("   -h, --help                Display this help message\n");
  printf("   -i, --interface <iface>   Name of the network interface (e.g. wlan0)\n");
  printf("   -p, --port <port number>  Port number to scan (default: 80)\n");
  printf("\n");
}

//Function to validate IP address
int validate_ip_address(char *ip_address) {
   struct sockaddr_in sa;
   int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
   return result != 0;
}

//Function to validate port number
int validate_port(char *port) {
  for(int i=0; i<strlen(port); i++) {
    if(!isdigit(port[i])) {
      return 0;
    }
  }
  int num = atoi(port);
  return (num >= 1) && (num <= 65535);
}

//Function to get IP address of a network interface
int get_ip_address(char *iface, char *ip_address) {
  int fd;
  struct ifreq ifr;
  memset(&ifr, 0, sizeof(ifr));
  strcpy(ifr.ifr_name, iface);
  fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(ioctl(fd, SIOCGIFADDR, &ifr) == -1) {
    return 0;
  }
  sprintf(ip_address, "%s", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
  close(fd);
  return 1;
}

int main(int argc, char *argv[]) {
  int option;
  char iface[10];
  char port[MAX_PORT_SIZE];
  strcpy(port, "80");

  //Parsing command line arguments
  while((option = getopt(argc, argv, "hi:p:")) != -1) {
    switch (option) {
      case 'h' :
        usage();
        return 0;
      case 'i' :
        strcpy(iface, optarg);
        break;
      case 'p' :
        if(validate_port(optarg)) {
          strcpy(port, optarg);
        } else {
          printf("Invalid port number provided. Defaulting to port 80\n");
        }
        break;
      default :
        usage();
        return 1;
    }
  }

  //Verifying if a valid network interface name is provided
  if(strlen(iface) == 0) {
    printf("Please provide a valid network interface name\n");
    return 1;
  }

  //Verifying if the IP address of the provided network interface is valid
  char ip_address[MAX_IP_SIZE];
  if(!get_ip_address(iface, ip_address)) {
    printf("Unable to get IP address for the network interface %s\n", iface);
    return 1;
  }
  if(!validate_ip_address(ip_address)) {
    printf("The IP address of the network interface %s is invalid\n", iface);
    return 1;
  }

  printf("Wireless Network Scanner - Scanning on port %s...\n", port);
  printf("Network Interface: %s, IP Address: %s\n", iface, ip_address);
  printf("------------------------------------------------------\n");

  //Scanning for wireless networks
  struct hostent *he;
  struct in_addr **addr_list;
  char *hostname;
  int sockfd;
  struct sockaddr_in addr;
  int i;

  hostname = "255.255.255.255";
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0) {
    printf("Error creating socket\n");
    return 1;
  }

  int broadcast = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1) {
    printf("Error setting socket options\n");
    close(sockfd);
    return 1;
  }

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));
  inet_pton(AF_INET, hostname, &addr.sin_addr);

  if(sendto(sockfd, "WLANSCAN", 8, 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    printf("Error sending broadcast message\n");
    close(sockfd);
    return 1;
  }

  //Waiting for responses
  char buffer[1024];
  struct timeval tv;
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

  printf("Wireless Networks found:\n");
  printf("------------------------\n");

  while(1) {
    memset(buffer, 0, sizeof(buffer));
    if(recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL) < 0) {
      break;
    }
    he = gethostbyname(buffer);
    addr_list = (struct in_addr**)he->h_addr_list;
    for(i=0; addr_list[i] != NULL; i++) {
      printf("%s\n", inet_ntoa(*addr_list[i]));
    }
  }

  close(sockfd);

  return 0;

}