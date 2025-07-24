//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include<stdio.h> 
#include<sys/socket.h>    
#include<arpa/inet.h> //inet_addr
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc , char *argv[])   
{
    if(argc != 2)
    {
        printf("Invalid number of arguments!!\n");
        printf("Usage : ./portscanner <IP>\n");
        return 0;
    }
    
    int sock, port, start_port = 1, end_port = 65535;
    struct sockaddr_in server;
    char *message;
    char server_reply[2000];
    
    if(inet_addr(argv[1]) == -1)
    {
        printf("Invalid IP address!!\n");
        return 0;
    }
    
    printf("Starting the port scan on %s\n\n", argv[1]);
    
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        return 0;
    }
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    
    for(port = start_port; port <= end_port; port++)
    {
        server.sin_port = htons(port);
        
        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0)
        {
            printf("Port %d : Open\n", port);
        }
        
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
    
    printf("\nPort scan completed!!\n");
    
    return 0;
}