//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include<stdio.h> // for standard input-output operations
#include<sys/socket.h> // for socket operations
#include<arpa/inet.h> // for internet address operations
#include<stdlib.h> // for standard library functions
#include<string.h> // for string operations

#define POP3_PORT 110 // POP3 uses port number 110

int main(int argc, char *argv[]) {
    int sock; // variable to hold socket id
    struct sockaddr_in server; // variable to hold server address
    char *message, server_reply[2000]; // variables for sending and receiving messages
    int recv_size;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Could not create socket");
    }

    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // change this to the IP address of your POP3 server
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);

    // Connect to remote server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Receive greeting message from the server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }

    puts(server_reply);

    // Send username to the server
    message = "USER username\r\n";
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }

    // Receive response from the server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }

    puts(server_reply);

    // Send password to the server
    message = "PASS password\r\n";
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }

    // Receive response from the server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }

    puts(server_reply);

    // Send command to list emails
    message = "LIST\r\n";
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }

    // Receive response from the server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }

    puts(server_reply);

    // Send command to retrieve an email
    message = "RETR 1\r\n";
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }

    // Receive response from the server
    if(recv(sock, server_reply, 2000, 0) < 0) {
        puts("receive failed");
    }

    puts(server_reply);

    // Close socket
    close(sock);
    return 0;
}