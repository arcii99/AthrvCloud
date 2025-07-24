//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    // Creating socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1){
        printf("Could not create socket");
    }

    // Setting up connection using server and ip address
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to remote server
    if( connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
        puts("connect error");
        return 1;
    }

    puts("Connected");
    printf("Port %d is open\n",ntohs(server.sin_port));

    // Close the socket
    close(socket_desc);

    return 0;
}