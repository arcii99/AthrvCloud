//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
// Wow! I can't believe we're building an HTTP client! This is exciting!
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80 // Whoa, we're connecting on port 80!

int main(int argc, char *argv[]) {
    
    char *address = "www.google.com"; // Let's connect to Google!
    struct sockaddr_in server;

    int client_socket = socket(AF_INET, SOCK_STREAM, 0); // First, let's create a socket

    if (client_socket == -1) {
        printf("Oh no, something went wrong creating the socket!\n");
    } else {
        printf("Socket created successfully!\n");
    }

    server.sin_addr.s_addr = inet_addr(address); // Okay, now let's fill in the server info
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0 ) { // Oh boy, time to connect!
        printf("Couldn't connect to server. Try again later, maybe?\n");
        return 1;
    } else {
        printf("Connected to %s on port %d!\n", address, PORT);
    }

    char request[512] = "GET / HTTP/1.1\r\n\r\n"; // We're going to request the root page

    if ( send(client_socket, request, strlen(request), 0) < 0) { // Let's send the request
        printf("Uh oh, something went wrong while sending the request!\n");
        return 1;
    } else {
        printf("Request sent!\n");
    }

    char response[4096]; // Hold onto your hats, we're about to get a response!

    if (recv(client_socket, response, 4096, 0) < 0) { // Receive that response
        printf("Huh, didn't get a response back. That's not good.\n");
    } else {
        printf("Response received!\n");
        printf("%s\n", response); // Now let's print out the response
    }

    close(client_socket); // Alright, we're all done. Time to close up shop.
    printf("Connection closed.\n");

    return 0;
}