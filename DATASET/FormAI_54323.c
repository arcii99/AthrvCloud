//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define PORT 8000
#define MAX_CONN 3

void handle_client(int client_sockfd)
{
    int buffer[10];
    memset(buffer, 0, sizeof(buffer));

    //read values from client
    if(read(client_sockfd, buffer, sizeof(buffer))<0){
        perror("Error in receiving data from client\n");
        exit(1);
    }

    int n = buffer[0];
    if(n == 1){
        printf("Server received number 1 from client\n");
        //send message to client
        char* msg = "Thank you for sending 1";
        if(send(client_sockfd, msg, strlen(msg), 0)<0){
            perror("Error in sending data to client\n");
            exit(1);
        }
    } else{
        int child_sockfd;

        //create socket for child process
        if ((child_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Error creating socket\n");
            exit(1);
        }

        struct sockaddr_in child_addr;
        memset(&child_addr, 0, sizeof(child_addr));

        child_addr.sin_family = AF_INET;
        child_addr.sin_addr.s_addr = htonl(INADDR_ANY);    //use any address of the machine
        child_addr.sin_port = htons(0);    //let OS choose the port

        //binding socket
        if (bind(child_sockfd, (struct sockaddr*)&child_addr,sizeof(child_addr)) < 0) {
            perror("Error binding socket\n");
            exit(1);
        }

        //get the port number selected by OS
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        socklen_t len = sizeof(addr);
        if (getsockname(child_sockfd, (struct sockaddr*)&addr, &len) < 0) {
            perror("Error in getsockname\n");
            exit(1);
        }
        int chosen_port = ntohs(addr.sin_port);

        //send the chosen port number to client
        if(send(client_sockfd, &chosen_port, sizeof(chosen_port), 0)<0){
            perror("Error in sending data to client\n");
            exit(1);
        }

        //listen to connection requests on the chosen port
        if (listen(child_sockfd, MAX_CONN) < 0) {
            perror("Error in listen\n");
            exit(1);
        }

        //accept connection from client
        int child_conn_sockfd;
        struct sockaddr_in child_conn_addr;
        socklen_t child_conn_addr_len;
        memset(&child_conn_addr, 0, sizeof(child_conn_addr));
        if((child_conn_sockfd = accept(child_sockfd,(struct sockaddr *)&child_conn_addr,&child_conn_addr_len))<0){
            perror("Error accepting connection\n");
            exit(1);
        }

        printf("Server is transferring connection to the new port number %d\n", chosen_port);
        //recursive call to handle the new connection
        handle_client(child_conn_sockfd);
    }
}

int main(int argc, char const *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    //create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    //binding socket
    if (bind(sockfd, (struct sockaddr*)&addr,sizeof(addr)) < 0) {
        perror("Error binding socket\n");
        exit(1);
    }

    //listening to connection requests
    if (listen(sockfd, MAX_CONN) < 0) {
        perror("Error in listen\n");
        exit(1);
    }

    printf("Server started on port %d....\n", PORT);

    while(1){
        int conn_sockfd;
        struct sockaddr_in conn_addr;
        socklen_t conn_addr_len;
        memset(&conn_addr, 0, sizeof(conn_addr));

        //accepting connection
        if ((conn_sockfd = accept(sockfd,(struct sockaddr *)&conn_addr,&conn_addr_len)) < 0){
            perror("Error accepting connection\n");
            exit(1);
        }

        printf("Server accepted connection from client %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        //handle the connection with client
        handle_client(conn_sockfd);
    }

    return 0;
}