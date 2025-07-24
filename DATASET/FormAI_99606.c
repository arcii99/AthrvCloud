//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

#define PORT 8080
#define ADDRESS "127.0.0.1"
#define BUFFER_SIZE 512

int main() {
    int sockfd = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    //create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ADDRESS, &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    //connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while (1) {
        //read input from user
        printf("Enter message : ");
        char message[BUFFER_SIZE] = {0};
        if(fgets(message, BUFFER_SIZE, stdin) == NULL){
            continue;
        }
        message[strcspn(message, "\n")] = 0; //removing newline character from input

        //send message to server
        send(sockfd, message, strlen(message), 0);

        //receive response from server
        valread = read( sockfd, buffer, BUFFER_SIZE);
        if(valread == 0){//server has closed the connection 
            printf("Server disconnected!\n");
            break;
        }
        if(valread == -1){//some error has occured
            printf("Error reading socket: %s\n", strerror(errno));
            break;
        }

        printf("Server response: %s\n", buffer);
        memset(buffer, 0, BUFFER_SIZE); //reset buffer
    }

    close(sockfd); //close socket
    return 0;
}