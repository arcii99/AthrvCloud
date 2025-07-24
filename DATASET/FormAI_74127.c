//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
/*
 * A simple C Client Server Application example program
 *
 * This program demonstrates a basic client-server interaction using socket programming in C.
 * The program consists of two files, a server file and a client file, which communicates 
 * with each other through sockets and sends messages.
 * 
 * To compile and run the program:
 * 1. Compile the server.c file using gcc -o server server.c
 * 2. Compile the client.c file using gcc -o client client.c
 * 3. Run the compiled server and client binaries using ./server and ./client respectively.
 *
 * Author: [Your Name Here]
 * Date: [Date]
 * License: [License]
 */

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc , char *argv[])
{
    // Create socket
    int socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    // Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connection Failed");
        return 1;
    }

    printf("Connected to server\n");

    // Send some data
    char *message = "Hello Server!";
    if (send(socket_desc , message , strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Data sent\n");

    // Receive a reply from the server
    char server_reply[2000];
    if (recv(socket_desc, server_reply , 2000 , 0) < 0) {
        puts("recv failed");
    }
    puts("Server reply :");
    puts(server_reply);

    // Close the socket
    close(socket_desc);

    return 0;
}