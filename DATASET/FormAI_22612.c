//FormAI DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

char *html = "<html><head><title>Simple Web Server</title></head><body><h1>Welcome to my Simple Web Server!</h1></body></html>";

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // configure the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the address and port
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Simple Web Server started on PORT %d\n", PORT);

    while(1) {
        // accept incoming connection
        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // read the incoming request
        int valread = read(new_sockfd, buffer, 1024);

        // print the incoming request
        printf("%s\n", buffer);

        // send a response
        char header[1024] = {0};
        sprintf(header, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\n\n", (int)strlen(html));
        write(new_sockfd, header, strlen(header));
        write(new_sockfd, html, strlen(html));

        // close the connection
        close(new_sockfd);
    }

    return 0;
}