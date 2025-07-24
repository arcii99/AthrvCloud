//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAX 500

int main() {
    int sock;
    char message[MAX], ipAddress[15], pagePath[MAX], response[MAX];
    struct sockaddr_in server;

    printf("Enter IP Address of the server: ");
    fgets(ipAddress, 15, stdin);

    printf("Enter Page Path (without http:// and IP Address): ");
    fgets(pagePath, MAX, stdin);

    //remove new line characters from input strings
    strtok(ipAddress, "\n");
    strtok(pagePath, "\n");

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    //server address
    server.sin_addr.s_addr = inet_addr(ipAddress);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    //connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error connecting to the server!\n");
        exit(1);
    }

    //create http request message
    sprintf(message, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", pagePath, ipAddress);

    //send http request to server
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending http request!\n");
        exit(1);
    }

    //receive http response from server
    if (recv(sock, response, MAX, 0) < 0) {
        printf("Error receiving http response!\n");
        exit(1);
    }
    
    //print http response
    printf("HTTP Response:\n%s\n", response);

    //close socket
    close(sock);
    
    return 0;
}