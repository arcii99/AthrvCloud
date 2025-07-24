//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
    printf("Are you ready to build an HTTP Client?! Let's go!\n");

    //create socket
    int soc_desc = socket(AF_INET, SOCK_STREAM, 0);

    //specify server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("216.58.194.174"); //google.com server address

    //connect to server
    int conn_status = connect(soc_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if(conn_status == -1){
        printf("Connection to server failed :( \n");
        return 0;
    }

    printf("Connection successful :)\n");

    //send request to server
    char request[1024] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    if(send(soc_desc, request, strlen(request), 0) < 0){
        printf("Request sending failed :(\n");
        return 0;
    }

    printf("Request sent successfully!\n");

    //receive response from server
    char server_response[4096];
    if(recv(soc_desc, server_response, sizeof(server_response), 0) < 0){
        printf("Response receiving failed!\n");
        return 0;
    }

    printf("Server responded with: \n%s\n", server_response);

    //close socket connection
    close(soc_desc);

    printf("HTTP Client program completed!\n");

    return 0;
}