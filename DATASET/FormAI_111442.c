//FormAI DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void printMsg(char* msg) {
    printf("[+] %s\n", msg);
}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char* ip = "127.0.0.1";

    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printMsg("Socket creation error");
        return -1;
    }

    // Setup the server address structure
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0) {
        printMsg("Invalid address or Address not supported");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printMsg("Connection failed");
        return -1;
    }

    char* msg = "Hello from client";
    send(sock, msg, strlen(msg), 0);
    printMsg("Message sent to server");

    valread = read(sock, buffer, 1024);
    printf("[Server] %s\n",buffer);

    return 0;
}