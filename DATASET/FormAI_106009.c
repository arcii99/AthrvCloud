//FormAI DATASET v1.0 Category: Simple Web Server ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define MAX_BUF 1024
int main(){
    int server_socket,client_socket;
    struct sockaddr_in server_address,client_address;
    char response[]="HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                    "<html><body><h1>Hello, World!</h1></body></html>\r\n";
    char client_message[MAX_BUF];
    socklen_t client_length;
    int port=8080;
    //Create server socket
    server_socket=socket(AF_INET,SOCK_STREAM,0);
    if(server_socket<0){
        printf("Error in creating socket\n");
        exit(1);
    }
    //Initialize server socket
    memset(&server_address,0,sizeof(server_address));
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=INADDR_ANY;
    server_address.sin_port=htons(port);
    
    //Bind server socket to the given IP and Port
    if(bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0){
        printf("Error in binding socket\n");
        exit(1);
    }

    //Listen for incoming connections
    listen(server_socket,3);
    printf("Server listening on port %d...\n",port);
    while(1){
        //Accept a new connection
        client_length=sizeof(client_address);
        client_socket=accept(server_socket,(struct sockaddr*)&client_address,&client_length);
        if(client_socket<0){
            printf("Error in accepting connection\n");
            exit(1);
        }
        printf("Accepted connection from %s:%d\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));
        pid_t pid=fork();
        if(pid==0){
            close(server_socket);
            //Receive the request from the client
            if(recv(client_socket,client_message,MAX_BUF,0)<0){
                printf("Error in receiving message\n");
            }
            else{
                printf("Received: %s\n",client_message);
                //Send the response back to the client
                if(send(client_socket,response,strlen(response),0)<0){
                    printf("Error in sending response\n");
                }
                else{
                    printf("Response sent!\n");
                }
            }
            close(client_socket);
            exit(0);
        }
        else{
            close(client_socket);
        }
    }
    close(server_socket);
    return 0;
}