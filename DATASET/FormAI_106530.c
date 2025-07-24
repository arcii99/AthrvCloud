//FormAI DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h>      // for IO operations
#include <stdlib.h>     // for exit() function
#include <string.h>     // for string operations
#include <sys/socket.h> // for socket and bind functions
#include <netinet/in.h> // for struct sockaddr_in and htons() function

#define PORT 8080       // server port number
#define MAX_PENDING 5   // maximum number of pending connection requests
#define MAX_REQUEST_SIZE 1024   // maximum size of the http request

int main() {
    // create socket
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // bind socket to server address
    if (bind(serverSock, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // listen for incoming connection requests
    if (listen(serverSock, MAX_PENDING) < 0) {
        perror("Error listening for connection requests");
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    char request[MAX_REQUEST_SIZE];

    while (1) {
        // accept incoming connection request
        int clientSock = accept(serverSock, NULL, NULL);
        if (clientSock < 0) {
            perror("Error accepting connection request");
            continue;
        }

        // read http request
        read(clientSock, request, MAX_REQUEST_SIZE);

        // parse http request to get the requested filename
        char *filename = strtok(request, " ");
        filename = strtok(NULL, " ");
        if (filename == NULL || strlen(filename) <= 1) {
            filename = "index.html";
        } else {
            filename++;
        }

        // open requested file
        FILE *fp = fopen(filename, "rb");

        // check if file exists
        if (fp == NULL) {
            char response[] = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
            write(clientSock, response, strlen(response));
            close(clientSock);
            continue;
        }

        // get file size
        fseek(fp, 0L, SEEK_END);
        int fileSize = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        // read file contents
        char *fileContents = (char *) malloc(fileSize);
        fread(fileContents, sizeof(char), fileSize, fp);

        // build http response
        char response[1024 + fileSize];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", fileSize, fileContents);

        // write http response
        write(clientSock, response, strlen(response));

        // close client connection
        close(clientSock);

        // free file contents
        free(fileContents);

        // close file
        fclose(fp);
    }

    // close server socket
    close(serverSock);

    return 0;
}