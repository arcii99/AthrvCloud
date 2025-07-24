//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<netdb.h>
#include<time.h>

#define PORT 80

int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    struct hostent *host;
    int sock, opt = 1;
    char *hostname;
    time_t start_time, end_time;
    double elapsed_time;
    
    if(argc < 2)
    {
        printf("Enter a website URL to monitor uptime\n");
        return 1;
    }
    hostname = argv[1];
    
    host = gethostbyname(hostname);
    if(host == NULL)
    {
         printf("Error in resolving hostname\n");
         return 1;
    }
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        printf("Error in creating socket\n");
        return 1;
    }
    
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Error in setting socket options\n");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr*)host->h_addr);
    
    start_time = time(NULL);
    
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
         printf("Error in connecting to the server\n");
         close(sock);
         return 1;
    }
    
    end_time = time(NULL);
    
    elapsed_time = difftime(end_time, start_time);
    
    char status[30];
    
    if(elapsed_time <= 5)
    {
        strcpy(status, "UP");
    }
    else
    {
        strcpy(status, "DOWN");
    }
    
    printf("%s is %s\n", hostname, status);
    
    close(sock);
    return 0;
}