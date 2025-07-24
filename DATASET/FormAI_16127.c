//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {

    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connect error");
        exit(EXIT_FAILURE);
    }

    clock_t begin = clock();
    send(sock , "Hello from client" , strlen("Hello from client") , 0 );
    valread = read( sock , buffer, BUF_SIZE);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("[CLIENT] Connection established.\n");
    printf("[CLIENT] Time taken: %lf seconds\n", time_spent);

    close(sock);
    return 0;
}