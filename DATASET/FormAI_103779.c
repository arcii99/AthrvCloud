//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<sys/socket.h> 
#include<arpa/inet.h> 
#include<unistd.h> 

int main(int argc, char *argv[]) 
{ 
    int sock; 
    struct sockaddr_in server; 
    char message[1000], server_reply[2000]; 
    
    //create socket 
    sock = socket(AF_INET , SOCK_STREAM , 0); 
    if (sock == -1) 
    { 
        printf("Could not create socket"); 
    } 
    puts("Socket created");
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET; 
    server.sin_port = htons( 5000 ); 
    
    //connect to remote server 
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) 
    { 
        perror("connect failed. Error"); 
        return 1; 
    } 
    
    puts("Connected\n"); 
    
    //keep communicating with server 
    while(1) 
    { 
        printf("Enter message: "); 
        scanf("%s" , message); 
        
        //send some data 
        if( send(sock , message , strlen(message) , 0) < 0) 
        { 
            puts("Send failed"); 
            return 1; 
        } 
        
        //receive a reply from the server 
        if( recv(sock , server_reply , 2000 , 0) < 0) 
        { 
            puts("recv failed"); 
            break; 
        } 
        
        puts("Server reply :"); 
        puts(server_reply); 
    } 
    
    close(sock); 
    return 0; 
}