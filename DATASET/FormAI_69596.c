//FormAI DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define PORT 8000  
#define MAX_BUFF_SIZE 1024  

int main(int argc, char *argv[]) {  
    int sockfd; // file descriptor for the socket created  
    struct sockaddr_in server_addr; // structure that stores server address information  
    struct sockaddr_in client_addr; // structure that stores client address information  
    socklen_t addr_len = sizeof(struct sockaddr);  
    char buffer[MAX_BUFF_SIZE]; // buffer to store incoming messages  

    // create new socket  
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {  
        perror("ERROR: Failed to create socket");  
        exit(1);  
    }  

    // clear server address structure  
    memset(&server_addr, 0, sizeof(struct sockaddr_in));  

    // fill in server address structure  
    server_addr.sin_family = AF_INET; // IPv4 protocol  
    server_addr.sin_port = htons(PORT); // port number  
    server_addr.sin_addr.s_addr = INADDR_ANY; // any incoming interface  

    // bind socket to server address  
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_in)) == -1) {  
        perror("ERROR: Failed to bind socket to server address");  
        exit(1);  
    }  

    printf("Server ready to receive messages on Port: %d\n", PORT);  

    // continuously receive messages and send replies  
    while (1) {  
        // clear buffer  
        memset(&buffer, 0, sizeof(buffer));  

        // receive message  
        if (recvfrom(sockfd, buffer, MAX_BUFF_SIZE - 1, 0, (struct sockaddr *)&client_addr, &addr_len) == -1) {  
            perror("ERROR: Failed to receive message");  
            continue; // continue to next iteration  
        }  

        // print received message  
        printf("Received message from client: %s\n", buffer);  

        // prepare response message  
        char response[MAX_BUFF_SIZE];  
        sprintf(response, "ACK: %s", buffer);  

        // send response message  
        if (sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, addr_len) == -1) {  
            perror("ERROR: Failed to send message");  
            continue; // continue to next iteration  
        }  

        // print sent message  
        printf("Sent message to client: %s\n", response);  
    }  

    // close socket  
    close(sockfd);  

    return 0;  
}