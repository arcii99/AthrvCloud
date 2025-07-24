//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    char *url = "www.example.com"; //replace with your desired url
    char *path = "/"; //replace with your desired endpoint
    char *host = "Host: www.example.com\r\n"; //replace with your desired website name
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    
    sprintf(message, "GET %s HTTP/1.1\r\n%sConnection: close\r\n\r\n", path, host); //format the GET request
    
    struct hostent *ip = gethostbyname(url); //translate URL to IP address 
    struct sockaddr_in server_address;
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); //HTTP port
    
    memcpy(&server_address.sin_addr, ip->h_addr_list[0], ip->h_length); //copy IP address
    
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); // create new socket
    
    if (client_socket < 0) {
        perror("socket():");
        exit(1);
    }
    
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) { //connect to server
        perror("connect():");
        exit(1);
    }
    
    write(client_socket, message, strlen(message)); //send GET request
    
    while (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0) { //receive response
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    close(client_socket); //close socket

    return 0;
}