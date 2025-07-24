//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int sock, status;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);    

    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("216.58.194.174"); 
    // google.com IP address

    server.sin_family = AF_INET;
    server.sin_port = htons(80); 

    // Connect to remote server
    status = connect(sock, (struct sockaddr *)&server , sizeof(server));

    if (status < 0) 
    {
        perror("Connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Send HTTP request
    strcpy(message, "GET / HTTP/1.1\r\n");
    strcat(message, "Host: www.google.com\r\n");
    strcat(message, "Connection: Close\r\n\r\n"); 

    if( send(sock , message , strlen(message) , 0) < 0) 
    {
        puts("Send failed");
        return 1;
    }

    puts("HTTP request sent\n"); 

    // Receive HTTP response
    if(recv(sock, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts("HTTP response received\n");

    puts(server_reply);

    close(sock);
    return 0;
}