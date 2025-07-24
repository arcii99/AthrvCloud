//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
//This is a simple C client-server program that allows clients to connect to the server and exchange messages

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 200

int main(int argc, char *argv[]){
    int sock_fd;
    struct sockaddr_in server_addr;
    char client_msg[MAX_SIZE], server_msg[MAX_SIZE];

    //create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        printf("Failed to create socket.\n");
        return -1;
    }
    
    //set sockaddr in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost IP Address
    server_addr.sin_port = htons(8888); //port number
    
    //connect to server
    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed.\n");
        return -1;
    }
    
    printf("Connected to server.\n");
    
    //communication with server
    while(1){
        printf("Enter message to send to server: ");
        fgets(client_msg, MAX_SIZE, stdin);
        
        //send message to server
        if(send(sock_fd, client_msg, strlen(client_msg), 0) < 0){
            printf("Send Failed.\n");
            return -1;
        }
        
        //receive server message
        if(recv(sock_fd, server_msg, MAX_SIZE, 0) < 0){
            printf("Receive Failed.\n");
            return -1;
        }
        
        printf("Server Message: %s", server_msg);
    }
    
    //close socket connection
    close(sock_fd);
    return 0;
}