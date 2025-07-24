//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main() {
    int sock, count = 0;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if(sock < 0) {
        printf("Could not create socket.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind socket.\n");
        return 1;
    }

    printf("Wireless network scanner started.\n");

    while(1) {
        char buffer[1024], ip_address[16];
        socklen_t addr_len = sizeof(server_addr);

        memset(buffer, 0, sizeof(buffer));
        memset(ip_address, 0, sizeof(ip_address));

        if(recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, &addr_len) < 0) {
            printf("Error while receiving data.\n");
            return 1;
        }

        inet_ntop(AF_INET, &server_addr.sin_addr, ip_address, sizeof(ip_address)); // convert IP to human-readable format

        printf("%d. %s\n", ++count, ip_address);
        fflush(stdout);

        sleep(1);
    }

    return 0;
}