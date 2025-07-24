//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock, valread, newsocket, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int addrlen = sizeof(server_addr);
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to port 8080
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the port
    if(bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Accepting new connections
        if((newsocket = accept(sock, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Reading and sending message to client
        valread = read(newsocket, buffer, 1024);
        printf("%s", buffer);
        send(newsocket, hello, strlen(hello), 0);
    }
    return 0;
}