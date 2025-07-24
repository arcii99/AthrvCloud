//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HOST "www.google.com"
#define PORT 80

int main() {

    while(1) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("172.217.167.36");
        server.sin_port = htons(PORT);

        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Website is down\n");
        }
        else {
            printf("Website is up and running!\n");
        }

        close(sock);
        sleep(5);
    }

    return 0;
}