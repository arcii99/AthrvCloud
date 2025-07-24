//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>

#define MAX_IFS 64

int main()
{
   int sock_fd;
   struct ifconf ifcfg;
   struct ifreq ifr[MAX_IFS];
   int num_ifs, i;
   char ip[INET_ADDRSTRLEN];

   sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
   if (sock_fd < 0)
   {
      perror("Cannot open socket");
      return 1;
   }

   ifcfg.ifc_buf = (void *) ifr;
   ifcfg.ifc_len = sizeof(ifr);
   if (ioctl(sock_fd, SIOCGIFCONF, &ifcfg) < 0)
   {
      perror("Cannot get list of interfaces");
      return 1;
   }

   num_ifs = ifcfg.ifc_len / sizeof(struct ifreq);
   for (i = 0; i < num_ifs; i++)
   {
      struct sockaddr_in *addr;
      addr = (struct sockaddr_in *) &ifr[i].ifr_addr;

      if (addr->sin_family != AF_INET)
         continue;

      if (inet_ntop(AF_INET, &addr->sin_addr, ip, INET_ADDRSTRLEN) == NULL)
      {
         perror("Cannot convert IP address to string");
         return 1;
      }

      printf("%-8s %s\n", ifr[i].ifr_name, ip);
   }

   return 0;
}