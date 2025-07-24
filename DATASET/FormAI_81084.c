//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<fcntl.h>
#include<sys/stat.h>

#define PORT_NUM 80
#define BUFFER_SIZE 65536
#define MAXIMUM_IP_ADDRESS_LENGTH 20

volatile int run_flag = 1;

void handle_termination(int sig_num){
    printf("Ctrl-C pressed, scanning terminated.\n");
    run_flag = 0;
}

uint32_t get_local_ip_address(){
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct ifreq ifr;
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
    ioctl(sock, SIOCGIFADDR, &ifr);
    close(sock);

    return ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
}

void scan_tcp_port(char *ip_address, int port){
    int sock;
    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);
    target.sin_port = htons(port);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0){
        printf("%s:%d - open\n", ip_address, port);
        close(sock);
    }
}

void scan_wireless_network(){
    uint32_t local_ip_address = get_local_ip_address();
    char ip_address[MAXIMUM_IP_ADDRESS_LENGTH];
    int i, j, k;

    printf("Scanning started on %d.%d.%d.%d...\n",
            (int)(local_ip_address & 0xff),
            (int)((local_ip_address >> 8) & 0xff),
            (int)((local_ip_address >> 16) & 0xff),
            (int)((local_ip_address >> 24) & 0xff));

    for(i = 1; i < 255 && run_flag; i++){
        for(j = 1; j < 255 && run_flag; j++){
            for(k = 1; k < 255 && run_flag; k++){
                snprintf(ip_address, MAXIMUM_IP_ADDRESS_LENGTH, "%d.%d.%d.%d", i, j, k, 1);
                scan_tcp_port(ip_address, PORT_NUM);
            }
        }
    }
}

int main(){
    signal(SIGINT, handle_termination);
    scan_wireless_network();
    return 0;
}