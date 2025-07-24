//FormAI DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
/* Hello there! Welcome to my simple web server program in C! */
/* This program listens to incoming browser requests and responds with a static webpage. */
/* Let's get started! */

/* First, let's import the necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Now, let's define some constants */
#define MAX_CONNECTIONS 5
#define REQUEST_SIZE 1024
#define RESPONSE_SIZE 4096

/* Great! Next, let's write our main function */
int main(int argc, char **argv) {

    /* Let's define some variables */
    int server_socket, client_socket, address_length;
    struct sockaddr_in server_address, client_address;

    /* Let's create our server socket */
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    /* Let's check if our socket was successfully created */
    if (server_socket == -1) {
        printf("Oops! Socket creation failed. Sorry!\n");
        return 1;
    }

    /* Let's define our server address */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    /* Let's bind our server address to our server socket */
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Oops! Binding failed. Sorry!\n");
        return 1;
    }

    /* Let's start listening to incoming connections */
    listen(server_socket, MAX_CONNECTIONS);

    /* Let's keep accepting incoming connections */
    while(1) {

        /* Let's define our client address length */
        address_length = sizeof(struct sockaddr_in);

        /* Let's accept the incoming connection and create a new client socket */
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &address_length);

        /* Let's check if our client socket was successfully created */
        if (client_socket < 0) {
            printf("Oops! Connection failed. Sorry!\n");
            continue;
        }

        /* Let's define some more variables */
        char request[REQUEST_SIZE], response[RESPONSE_SIZE], *file_name;
        FILE *file;

        /* Let's read the incoming request */
        read(client_socket, request, REQUEST_SIZE);

        /* Let's extract the filename from the request */
        file_name = strtok(request, " ");
        file_name = strtok(NULL, " ");
        file_name++;

        /* Let's check if the file exists */
        if ((file = fopen(file_name, "r")) == NULL) {
            strcpy(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<html><body><h1>404 Not Found</h1><p>The requested file was not found on this server.</p></body></html>");
        } else {
            /* Let's read the file contents */
            char file_contents[RESPONSE_SIZE];
            while (fgets(file_contents, RESPONSE_SIZE, file)) {
                strcat(response, file_contents);
            }
            fclose(file);
        }

        /* Let's send the response back to the client */
        write(client_socket, response, strlen(response));

        /* Let's close the client socket */
        close(client_socket);
    }

    /* Let's close the server socket */
    close(server_socket);

    /* And we're done! Thanks for checking out my program! */
    return 0;
}
/* Fantastic! */