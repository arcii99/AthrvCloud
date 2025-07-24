//FormAI DATASET v1.0 Category: Chat server ; Style: scientific
/* 
Title: Scientific Chat Server
Author: [Your Name]

Description: This program implements a chat server that allows users to connect and communicate with each other in a scientific way. Users can ask scientific questions and the server will respond with the relevant scientific answers.The program is implemented in C language using socket programming.

*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 9005

int main(){

    /* create socket */ 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Socket Creation Failed");
        exit(1);
    }

    /* set socket options */ 
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    /* bind socket to port */ 
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));  

    if(bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1){
        perror("Socket Binding Failed");
        exit(1);
    }
    
    /* listen for incoming connections */ 
    if(listen(sockfd, 10) == -1){
        perror("Socket Listening Failed");
        exit(1);
    }
    
    /* accept incoming connections */ 
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if(clientSockfd == -1){
        perror("Client Accepting Failed");
        exit(1);
    }
    
    char* welcomeMsg = "Welcome to the Scientific Chat Server!\nPlease input your scientific question:\n";
    send(clientSockfd, welcomeMsg, strlen(welcomeMsg), 0);
    
    /* chat loop */ 
    while(1){
        char buf[1024];
        int recvRet = recv(clientSockfd, buf, sizeof(buf), 0);
        if(recvRet == -1){
            perror("Receiving Failed");
            exit(1);
        }
        
        /* scientific question and answer logic */ 
        char* responseMsg;
        if(strcmp(buf, "What is gravity?\n") == 0){
            responseMsg = "Gravity is the force by which a planet or other body draws objects toward its center.\n";
        } else if(strcmp(buf, "What is the speed of light?\n") == 0){
            responseMsg = "The speed of light in a vacuum is 299,792,458 meters per second.\n";
        } else if(strcmp(buf, "What are black holes?\n") == 0){
            responseMsg = "Black holes are extremely compressed pockets of space-time with an intense gravitational field.\n";
        } else if(strcmp(buf, "What is E=mc^2?\n") == 0){
            responseMsg = "E=mc^2 is the famous mass-energy equivalence equation discovered by Albert Einstein.\n";
        } else if(strcmp(buf, "What is the Higgs boson?\n") == 0){
            responseMsg = "The Higgs boson is an elementary particle in the Standard Model of physics that is responsible for giving other particles mass.\n";
        } else if(strcmp(buf, "exit\n") == 0 || strcmp(buf, "quit\n") == 0){
            responseMsg = "Goodbye!\n";
            send(clientSockfd, responseMsg, strlen(responseMsg), 0);
            close(clientSockfd);
            break;
        } else{
            responseMsg = "Invalid scientific question!";
        }
        
        /* send scientific answer */ 
        send(clientSockfd, responseMsg, strlen(responseMsg), 0);
    }
    
    /* close socket */ 
    close(sockfd);

    return 0;
}