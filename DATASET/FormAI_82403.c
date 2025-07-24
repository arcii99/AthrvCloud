//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
//This is a Wi-Fi Signal Strength Analyzer program developed in C language.
//The program uses socket programming in C to establish a socket connection and fetch signal strength data.
//The program also utilizes system commands in C to display the output on the console.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 80
//this is the port to which we will connect and fetch signal strength data.

int main(){
    int sock;
    struct sockaddr_in server;
    char *message,server_reply[2000];
    //message will store the GET request that we will send to fetch data
    //server_reply will store the response received from the server
    
    sock = socket(AF_INET,SOCK_STREAM,0);
    //creating a socket for IPv4 and TCP connection
    
    if(sock==-1){
        printf("Could not create socket");
    }
    puts("Socket created successfully");
    
    server.sin_addr.s_addr = inet_addr("192.168.1.1");
    //IP address of the router/modem that we will connect to
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    //converting PORT to network byte order
    
    //connect to the remote server
    if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){
        perror("Connection failed. Error");
        return 1;
    }
    
    puts("Connected successfully");
    message = "GET /signal_strength HTTP/1.1\r\n\r\n";
    //HTTP GET request to fetch signal strength data from the router/modem
    
    if(send(sock,message,strlen(message),0)<0){
        puts("Send failed");
        return 1;
    }
    
    puts("Data Sent successfully");
    
    //receive data from server
    if(recv(sock,server_reply,2000,0)<0){
        puts("recv failed");
    }
    puts("Data received successfully");
    
    printf("\nSignal Strength: %s\n",(server_reply+22));
    //display the signal strength data. +22 skips the initial HTTP headers
    
    return 0;
}