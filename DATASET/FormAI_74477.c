//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>    
#include <stdlib.h>    
#include <netinet/in.h>    
#include <string.h>    
#include <sys/socket.h>    
#include <unistd.h>    
#include <arpa/inet.h>

#define PORT 8080

int main()    
{    
    int sock = socket(AF_INET, SOCK_STREAM, 0);    
    if (sock < 0)    
    {    
        printf("\n Error : Could not create socket \n");    
        return 1;    
    }    
    
    struct sockaddr_in server, client;    
    memset(&server, 0, sizeof(server));    
    memset(&client, 0, sizeof(client));    
    
    server.sin_family = AF_INET;    
    server.sin_port = htons(PORT);    
    server.sin_addr.s_addr = INADDR_ANY;    
    
    int bnd = bind(sock, (struct sockaddr *)&server, sizeof(server));    
    if (bnd < 0)    
    {    
        printf("\n Error : Bind Failed \n");    
        return 1;    
    }    
    
    int lstn = listen(sock, 3);    
    if (lstn < 0)    
    {    
        printf("\n Error : Listen Failed \n");    
        return 1;    
    }    
    printf("\n Waiting for incoming connection... \n");    
    
    int clilen = sizeof(client);    
    int newsock = accept(sock, (struct sockaddr*)&client, &clilen);    
    if (newsock < 0)    
    {    
        printf("\n Error : Accept Failed \n");    
        return 1;    
    }    
    printf("\n Connection Accepted! \n");    
    
    char buffer[256];    
    memset(buffer, 0, sizeof(buffer));  
    
    int rcvBytes = recv(newsock, buffer, sizeof(buffer)-1, 0);    
    if (rcvBytes < 0)    
    {    
        printf("\n Error : Receive Failed \n");    
        return 1;    
    }    
    printf("\n Message from client: %s \n", buffer);    
    
    char* reply = "Got your message! Thanks for connecting.";    
    int replyLen = strlen(reply);    
    
    int sndBytes = send(newsock, reply, replyLen, 0);    
    if (sndBytes < 0)    
    {    
        printf("\n Error : Send Failed \n");    
        return 1;    
    }    
    
    close(newsock);    
    close(sock);    
   
    return 0;    
}