//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>

#define MAX_IFS 10
#define MAX_SSID_LEN 32

int main()
{
  struct ifreq ifaces[MAX_IFS];	// This struct is defined in net/if.h
  int count;
  int skfd;
  char ssid[MAX_SSID_LEN];

  if ((skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  // Get list of interfaces.
  if (ioctl(skfd, SIOCGIFCONF, ifaces) < 0) {
    perror("ioctl");
    exit(1);
  }

  count = sizeof(ifaces)/sizeof(ifaces[0]);
  while (count--) {
    if (ifaces[count].ifr_flags & IFF_UP && ifaces[count].ifr_flags & IFF_BROADCAST) {
      printf("%s\n", ifaces[count].ifr_name);

      // Get SSID
      strncpy(ssid, ifaces[count].ifr_name, MAX_SSID_LEN);
      int i;
      for (i = 0; i < strlen(ssid); i++)
        ssid[i] = toupper(ssid[i]);
      printf("\tSSID: %s\n", ssid);
    }
  }

  close(skfd);

  return 0;
}