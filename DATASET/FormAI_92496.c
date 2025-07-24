//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>

#define MAX_ADDR_SIZE 128
#define MAX_DEVS 256

// Structure to hold information about each device on the network
typedef struct Device {
    char ip_address[MAX_ADDR_SIZE];
    char mac_address[MAX_ADDR_SIZE];
    char hostname[MAX_ADDR_SIZE];
    int is_online;
} Device;

// Structure to hold information about each interface on the system
typedef struct Interface {
    char ip_address[MAX_ADDR_SIZE];
    char netmask[MAX_ADDR_SIZE];
} Interface;

// Function to get the list of interfaces on the system
// and their IP addresses
int get_interfaces(Interface *interfaces) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s, n;
  
  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }
  
  for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
    if (ifa->ifa_addr == NULL) {
      continue;
    }
    
    family = ifa->ifa_addr->sa_family;
    
    if (family == AF_INET || family == AF_INET6) {
      s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                      interfaces[n].ip_address, NI_MAXHOST,
                      NULL, 0, NI_NUMERICHOST);
      
      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        return -1;
      }
    }
  }
  
  freeifaddrs(ifaddr);
  return n;
}

// Function to get the MAC address of a device with a given IP address
int get_mac_address(char *ip_address, char *mac_address) {
  int sockfd;
  
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket");
    return -1;
  }
  
  struct sockaddr_in server_address = {
      .sin_family = AF_INET,
      .sin_port = htons(67),
      .sin_addr = {
          .s_addr = htonl(INADDR_ANY),
      },
  };
  
  if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("bind");
    return -1;
  }
  
  struct sockaddr_in client_address = {
      .sin_family = AF_INET,
      .sin_port = htons(68),
      .sin_addr = {
          .s_addr = inet_addr(ip_address),
      },
  };
  
  char buff[1024];
  unsigned char *mac;
  
  struct iovec iov[1];
  iov[0].iov_base = buff;
  iov[0].iov_len = sizeof(buff);
  
  struct msghdr message = {
      .msg_name = &client_address,
      .msg_namelen = sizeof(client_address),
      .msg_iov = iov,
      .msg_iovlen = 1,
  };
  
  if (recvmsg(sockfd, &message, 0) < 0) {
    perror("recvmsg");
    return -1;
  }
  
  struct dhcp_packet {
    uint8_t jmp[4];
    uint8_t op;
    uint8_t htype;
    uint8_t hlen;
    uint8_t hops;
    uint32_t xid;
    uint16_t secs;
    uint16_t flags;
    struct in_addr ciaddr;
    struct in_addr yiaddr;
    struct in_addr siaddr;
    struct in_addr giaddr;
    uint8_t chaddr[16];
    uint8_t sname[64];
    uint8_t file[128];
    uint8_t options[1];
  } __attribute__((packed));
  
  struct dhcp_packet *packet = (struct dhcp_packet *)buff;
  
  if (packet->op == 0x02 && 
      packet->options[0] == 0x63 &&
      packet->options[1] == 0x82 &&
      packet->options[2] == 0x53 &&
      packet->options[3] == 0x63) {
  
    mac = packet->chaddr;
    sprintf(mac_address, "%02x:%02x:%02x:%02x:%02x:%02x",
            mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  
    return 0;
  }
  
  return -1;
}

// Function to scan the network for devices
void scan_network(Device *devices, int num_interfaces) {
  for (int i = 0; i < num_interfaces; i++) {
    char network[MAX_ADDR_SIZE];
    strncpy(network, devices[i].ip_address, strrchr(devices[i].ip_address, '.') - devices[i].ip_address + 1);
    int online_devices = 0;
    for (int j = 1; j < 256; j++) {
      char ip_address[MAX_ADDR_SIZE];
      sprintf(ip_address, "%s%d", network, j);
      Device device = {
          .is_online = 0,
      };
      if (get_mac_address(ip_address, device.mac_address) == 0) {
        if (getnameinfo((struct sockaddr *)&(struct sockaddr_in){.sin_family = AF_INET, .sin_addr.s_addr = inet_addr(ip_address)}, sizeof(struct sockaddr_in), device.hostname, sizeof(device.hostname), NULL, 0, 0) == 0) {
          strcpy(device.ip_address, ip_address);
          device.is_online = 1;
          online_devices++;
        }
      }
      devices[j + 255 * i - 256] = device;
    }
    printf("Interface %s has %d online devices\n", devices[i].ip_address, online_devices);
  }
}

int main(int argc, char **argv) {
  Interface interfaces[MAX_DEVS];
  int num_interfaces = get_interfaces(interfaces);
  if (num_interfaces == -1) {
    printf("Could not get interfaces\n");
    return -1;
  }
  
  Device devices[MAX_DEVS * 256];
  memset(devices, 0, sizeof(devices));
  
  scan_network(devices, num_interfaces);
  
  for (int i = 0; i < MAX_DEVS * 256; i++) {
    if (devices[i].is_online) {
      printf("%s %s %s\n", devices[i].ip_address, devices[i].mac_address, devices[i].hostname);
    }
  }
  
  return 0;
}