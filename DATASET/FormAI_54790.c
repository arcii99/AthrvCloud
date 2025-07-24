//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    clock_t start, end;
    double time_taken;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created...\n");

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket binding failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded...\n");

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening on port %d...\n", PORT);

    int len = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd < 0) {
        printf("Server accceptance failed...\n");
        exit(0);
    }
    else
        printf("Server acccepted the client...\n");

    memset(buffer, 0, sizeof(buffer));
    read(connfd, buffer, sizeof(buffer));
    printf("Client requested to start the speed test...\n");

    char* response = "Start";
    write(connfd, response, strlen(response));

    memset(buffer, 0, sizeof(buffer));
    read(connfd, buffer, sizeof(buffer));
    printf("Client is ready to send data...\n");

    start = clock();

    for(int i=0;i<10485760;i++){
        read(connfd, buffer, sizeof(buffer));
        if (i == 10485759){
            end = clock();
            printf("Data received successfully...\n");
            break;
        }
    }

    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken to download 10MB file: %f seconds\n", time_taken);

    char* end_response = "End";
    write(connfd, end_response, strlen(end_response));

    close(sockfd);
    return 0;
}