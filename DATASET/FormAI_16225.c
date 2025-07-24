//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void firewall(char *ip_address, int port, int *allowed_ips, int num_allowed_ips) {
    int i;
    int ip[4];
    sscanf(ip_address, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    int allowed = 0;
    for (i = 0; i < num_allowed_ips; i++) {
        if (ip[0] == allowed_ips[i]/(256*256*256) && 
            ip[1] == (allowed_ips[i]/(256*256))%256 && 
            ip[2] == (allowed_ips[i]/256)%256 && 
            ip[3] == allowed_ips[i]%256) {
            allowed = 1;
            break;
        }
    }
    if (!allowed || port != 80) {
        printf("Access denied!\n");
        return;
    }
    else {
        printf("Access granted!\n");
        return;
    }
}
 
int main(void) {
    char *ip_address = "192.168.0.1";
    int port = 80;
    int allowed_ips[] = {2130706433, 3232235777, 2130706434, 3232235778};
    int num_allowed_ips = 4;
    firewall(ip_address, port, allowed_ips, num_allowed_ips);
    return 0;
}