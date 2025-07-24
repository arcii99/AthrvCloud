//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Socket creation error\n");
        exit(1);
    }

    printf("Enter the IP address of the network to scan: ");
    char ip[20];
    scanf("%s", ip);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // convert IP address from string to binary format
    if(inet_pton(AF_INET, ip, &server_addr.sin_addr) <=0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("\nWireless Network Scanner\n\n");
    printf("Scanning for wireless networks...\n\n");

    char buffer[1024];
    int valread = read(sock, buffer, 1024);
    printf("Available wireless networks: \n\n");
    printf("%s\n", buffer);

    close(sock);
    return 0;
}