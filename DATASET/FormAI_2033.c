//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define MAX_BUFFER_SIZE 1024

int main(){
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[MAX_BUFFER_SIZE] = {0};

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    // Setup the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }
    
    // Send a romantic message to the server
    char *romantic_message = "My love, sending you a message through the TCP/IP protocol,\n just wanted to tell you that I love you more than anything. \n I hope this message finds you happy and healthy, \n missing you more than words can express. \n Always, your love. \n";
    send(sock, romantic_message, strlen(romantic_message), 0);
    
    // Receive a response from the server
    int valread = read(sock, message, MAX_BUFFER_SIZE);
    printf("%s\n", message);
    close(sock);
    return 0;
}