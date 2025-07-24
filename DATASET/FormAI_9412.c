//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main()
{
    int sockfd, ret;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("[-] Error in connection.\n");
        exit(1);
    }
    printf("[+] Client Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("[-] Error in connection.\n");
        exit(1);
    }
    printf("[+] Connected to Server.\n");

    char buffer[1024];
    while(1){
        printf("Client: ");
        fgets(buffer, 1024, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        if(strcmp(buffer, "exit\n") == 0){
            close(sockfd);
            printf("[-] Disconnected from server.\n");
            exit(1);
        }

        if(recv(sockfd, buffer, 1024, 0) < 0){
            printf("[-] Error in receiving data.\n");
        }else{
            printf("Server: %s", buffer);
        }
    }

    return 0;
}