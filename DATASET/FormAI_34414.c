//FormAI DATASET v1.0 Category: Networking ; Style: Donald Knuth
/* Networking: An Example Program in the Style of Donald Knuth */
/* Created by AI language model */

/* Introduction */
/* This program simulates a client-server architecture that transfers an array of integers between two processes using TCP/IP protocol. The main purpose of this program is to demonstrate networking concepts in C programming language. */

#include <stdio.h> /* Standard Input Output Functions */
#include <stdlib.h> /* Standard Library Functions */
#include <sys/types.h>
#include <sys/socket.h> /* Socket Programming Functions */
#include <netinet/in.h> /* Internet Protocol Functions */

/* Function Declaration */
void error(char *msg); /* Error Handling Function */

/* Main Function */
int main(int argc, char *argv[]) {

    /* Variable Declarations */
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    int data[10] = {2,4,6,8,10,12,14,16,18,20}; /* Sample Data */

    /* Socket Creation */
    sockfd = socket(AF_INET, SOCK_STREAM, 0); /* Create a New Socket */
    if(sockfd < 0)  
        error("Error opening socket."); /* Error Handling */

    /* Socket Configuration */
    bzero((char *) &serv_addr, sizeof(serv_addr)); /* Set the Server Address to Zero */
    portno = 8080; /* Set the Port Number */
    serv_addr.sin_family = AF_INET; /* Address Family */
    serv_addr.sin_addr.s_addr = INADDR_ANY; /* Allow Any IP Address to Connect */
    serv_addr.sin_port = htons(portno); /* Set the Port Number */

    /* Socket Binding */
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)  
        error("Error on binding."); /* Error Handling */

    /* Client Connection */
    listen(sockfd, 5); /* Listen for Client Connection Requests */
    clilen = sizeof(cli_addr); /* Get the Length of the Client Address */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); /* Accept the Incoming Connection */
    if(newsockfd < 0)  
        error("Error on accept."); /* Error Handling */

    /* Data Transmission */
    n = write(newsockfd, data, sizeof(data)); /* Write the Data to the Socket */
    if(n < 0)  
        error("Error writing to socket."); /* Error Handling */

    /* Close the Sockets */
    close(newsockfd); /* Close the Client Socket */
    close(sockfd); /* Close the Server Socket */

    return 0;
}

/* Error Handling Function */
void error(char *msg) {
    perror(msg); /* Print the Error Message */
    exit(1); /* Exit the Program */
}