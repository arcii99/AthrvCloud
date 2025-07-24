//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<ifaddrs.h>

int main(int argc, char *argv[])
{

  struct ifaddrs *addrs, *tmp;
  getifaddrs(&addrs);
  tmp = addrs;
  while (tmp)
  {
    if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_PACKET)
    {
        printf("Interface: %s\n", tmp->ifa_name);
        printf("MAC Address: ");
        for(int i=0; i < 6; i++)
        {
            printf("%.2X:", (unsigned char)tmp->ifa_addr->sa_data[i]);
        }
        printf("\n");
    }
    tmp = tmp->ifa_next;
  }
  freeifaddrs(addrs);

  return 0;
}