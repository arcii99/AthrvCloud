//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>

void scanNetwork(char* ip_base){
    struct hostent* host;
    char* hostname;
    struct sockaddr_in addr;
    int sock;
    int port = 80;
    char ip[16];
    sprintf(ip, "%s.1", ip_base);
    for(int i = 1; i < 256; i++){
        sprintf(ip, "%s.%d", ip_base, i);
        if((host = gethostbyname(ip)) != NULL){
            hostname = host->h_name;
            printf("Host %s found!\n", hostname);
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            memcpy(&addr.sin_addr, host->h_addr_list[0], sizeof(addr.sin_addr));
            if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
                printf("Could not create socket\n");
                exit(1);
            }
            if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0){
                printf("Port %d open on host %s\n", port, hostname);
                close(sock);
            }else{
                printf("Port %d closed on host %s\n", port, hostname);
            }
        }
    }
}

int main(){
    char ip_base[16];
    printf("Enter the first three octets of the IP address to scan: ");
    scanf("%15s", ip_base);
    scanNetwork(ip_base);
    return 0;
}