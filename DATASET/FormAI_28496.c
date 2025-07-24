//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>      

int main(int argc, char *argv[]) 
{
    int sock;
    struct sockaddr_in server;
    char message[1024], server_reply[2000];
    
    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) 
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) 
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    //Receive the reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //Send a USER command to the server
    strcpy(message,"USER [Your Email Address Here]\r\n");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
     
    //Receive the reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //Send a PASS command to the server
    strcpy(message,"PASS [Your Password Here]\r\n");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
     
    //Receive the reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //Send a STAT command to the server
    strcpy(message,"STAT\r\n");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    
    //Receive the reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    printf("\nServer response: %s",server_reply);
 
    //Close the socket
    close(sock);
    return 0;
}