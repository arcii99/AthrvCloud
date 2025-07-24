//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    // Set up server address and port number
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Connect failed. Error");
        return 1;
    }
    puts("Connected\n");
    
    // Send some data to server
    strcpy(message, "Hello server, I'm your dear client!");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data sent to server successfully");
    
    // Receive a reply from server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("Receive failed");
    }
    puts("Reply received from server :");
    puts(server_reply);
    
    close(sock);
    return 0;
}