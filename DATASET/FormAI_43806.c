//FormAI DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(){

    //create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){ 
        printf("Could not create socket");
        return -1;
    }

    //bind socket to port 8000
    struct sockaddr_in server_address ;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1 ){
        printf("Could not bind to port 8000");
        return -1;
    }

    //start listening for incoming connections
    if(listen(server_fd, 10) == -1){
        printf("Could not listen for incoming connections");
        return -1;
    }

    //accept incoming connections
    int client_fd;
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);
    while(1){
        client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_len);
        if(client_fd == -1){
            printf("Could not accept incoming connection");
            return -1;
        }

        //handle incoming requests
        char buffer[1024] = {0};
        read(client_fd, buffer, 1024);
        printf("%s\n", buffer);

        //send response
        char* send_response = "HTTP/1.0 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>\n";
        write(client_fd, send_response, strlen(send_response));

        //close connection
        close(client_fd);
    }
    return 0;
}