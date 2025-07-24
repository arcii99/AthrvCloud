//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAX_SIZE 1024

void error(char *message){
    perror(message);
    exit(EXIT_FAILURE);
}

int main(){
    puts("Welcome to the HTTP Client!");

    // Create Socket
    int http_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(http_socket == -1){
        error("Error creating Socket!");
    }

    // Define Server Address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("216.58.194.174");

    // Connect to Server
    if(connect(http_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        error("Error connecting to Server!");
    }

    // Prepare the Request
    char request[MAX_SIZE];
    sprintf(request, "GET / HTTP/1.1\nHost: www.google.com\n\n");

    // Send the Request
    if(send(http_socket, request, strlen(request), 0) == -1){
        error("Error sending Request to Server!");
    }

    // Receive Response from Server
    char response[MAX_SIZE];
    if(recv(http_socket, response, MAX_SIZE, 0) == -1){
        error("Error receiving Response from Server!");
    }

    // Display Server Response
    puts("Server Response:");
    puts(response);

    // Close the Socket
    close(http_socket);

    puts("Thank You for using HTTP Client!");

    return 0;
}