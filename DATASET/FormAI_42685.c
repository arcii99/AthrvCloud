//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
// A Statistical Example Program for TCP/IP Programming
// This program accepts data from a client, performs some statistical analysis on it, and sends the result back to the client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // First, let's create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Now, let's set the server address information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 1234; // Let's use port 1234
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address information
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept incoming connections and handle them
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Read the data from the client
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        // Perform some statistical analysis on the data
        // For this example, let's calculate the mean and standard deviation of the numbers
        double sum = 0;
        double square_sum = 0;
        int count = 0;
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            double num = atof(token);
            sum += num;
            square_sum += num*num;
            count++;
            token = strtok(NULL, ",");
        }
        double mean = sum / count;
        double std_dev = sqrt(square_sum/count - mean*mean);

        // Send the result back to the client
        bzero(buffer, 256);
        sprintf(buffer, "Mean: %lf, Standard Deviation: %lf", mean, std_dev);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd); // Close the connection
    }

    close(sockfd); // Close the socket
    return 0;
}