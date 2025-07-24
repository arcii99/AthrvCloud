//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000], response[2000];
    
    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //change IP address as required
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 ); //change port number as required
 
    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    
    puts("Connected to server");
    
    //Send http request
    sprintf(message, "GET / HTTP/1.1\r\n\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Request sent");
    
    //Receive response from server
    if (recv(sock, response, 2000, 0) < 0)
    {
        puts("Receive failed");
        return 1;
    }
    puts("Response received");
    puts(response);
    
    close(sock);
    return 0;
}