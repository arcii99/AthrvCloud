//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>

#define MAX_INTERFACES 64
#define MAX_LINE_SIZE 256

void get_local_interfaces(char (*if_list)[INET_ADDRSTRLEN], int *if_count){
    int fd, intrface, retn = 0, flags;
    struct ifreq buf[MAX_INTERFACES];
    struct ifconf ifc;
    *if_count = 0;
    if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) >= 0)
    {
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = (caddr_t) buf;
        if (!ioctl(fd, SIOCGIFCONF, (char *) &ifc))
        {
            intrface = ifc.ifc_len / sizeof(struct ifreq);
            while (intrface-- > 0)
            {
                strcpy(if_list[*if_count], inet_ntoa(((struct sockaddr_in*) &(buf[intrface].ifr_addr))->sin_addr));
                ++(*if_count);
            }
        }
        close(fd);
    }
}

int main(){
    char if_list[MAX_INTERFACES][INET_ADDRSTRLEN];
    int if_count;
    get_local_interfaces(if_list, &if_count);
    printf("Found %d interfaces:\n", if_count);
    for(int i=0;i<if_count;i++){
        printf("%s\n",if_list[i]);
    }
    return 0;
}