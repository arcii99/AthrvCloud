//FormAI DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8000
#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd, n;
    socklen_t clilen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFSIZE];
    char filename[256];

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    //set server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //bind socket to address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    //listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(client_addr);

    //wait for client connection
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
    if (newsockfd < 0) {
        perror("Failed to accept");
        exit(1);
    }

    //get filename from client
    bzero(filename, 256);
    n = read(newsockfd, filename, 255);
    if (n < 0) {
        perror("Failed to read filename");
        exit(1);
    }

    //open file for writing
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Failed to open file");
        exit(1);
    }

    //receive file contents from client and write to disk
    while ((n = read(newsockfd, buffer, BUFSIZE)) > 0) {
        if (write(fd, buffer, n) < 0) {
            perror("Failed to write to file");
            exit(1);
        }
    }
    if (n < 0) {
        perror("Failed to read from socket");
        exit(1);
    }

    //close file and socket
    close(fd);
    close(newsockfd);
    close(sockfd);

    printf("File received and written to disk: %s\n", filename);

    return 0;
}