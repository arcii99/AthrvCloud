//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
//In the world of HTTP, there was a client
//longing for a server's love, ever so fervent

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];
    
    //Set up socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created successfully!\n");
    
    //Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
 
    //Connect to remote server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connection failed. Error");
        return 1;
    }
    printf("Connected successfully!\n");
    
    //Create message to send to the server
    sprintf(message, "GET / HTTP/1.1\r\n\r\n");
    
    //Send message to the server
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("Message sent successfully!\n");
    
    //Receive a reply from the server
    if(recv(sock, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed");
    }
    printf("Reply received successfully. Server's response is:\n");
    printf("%s\n", server_reply);
    
    //Close the socket
    close(sock);
    
    printf("Love between HTTP client and server is beautiful. May it last forever!\n");
    
    return 0;
}