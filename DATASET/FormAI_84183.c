//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
// Romeo and Juliet - Building a HTTP Client example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Main function
int main(int argc, char **argv) {
    // Tell me wherefore we must build a HTTP client?
    printf("O Romeo, I must build a HTTP client to access the web! Forsooth, we shall be able to request data and receive it from servers, and display it on our own device!\n");

    // Declare socket variables
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // If socket creation fails, let us make a jump to sorrow
    if (sockfd < 0) {
        printf("Alack! Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Clear the server address buffer
    bzero(&servaddr, sizeof(servaddr));

    // Set the server address information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("O woe! Could not connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP request
    char *http_request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    char http_response[4096];

    // Send the HTTP request
    if (send(sockfd, http_request, strlen(http_request), 0) < 0) {
        printf("Oft expectation fails, and most oft there\n"
               "Where most it promises; and oft it hits\n"
               "Where hope is coldest, and despair most fits.\n");
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response
    if (recv(sockfd, http_response, sizeof(http_response), 0) < 0) {
        printf("O fickle Fortune! The response could not be received.\n");
        exit(EXIT_FAILURE);
    }

    // Display the HTTP response
    printf("But soft! What light through yonder window breaks?\n"
           "It is the east, and HTTP response is the sun!\n");

    printf("%s", http_response);

    // Close the socket and bid adieu to our HTTP connection
    close(sockfd);
    printf("Parting is such sweet sorrow, that I shall say good night till it be morrow.\n");

    // Return from the program
    return 0;
}