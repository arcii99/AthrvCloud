//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Happy HTTP Client Program

int main(int argc, char *argv[]) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Oops! Failed to create socket. 😞\n");
        return 1;
    }

    printf("Yay! Socket created successfully. 🎉\n");

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to HTTP server

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Oops! Failed to connect to HTTP server. 😞\n");
        return 1;
    }

    printf("Connecting to HTTP server... 🤝\n");
    printf("Connected to HTTP server successfully! 👍\n");

    char *request = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Oops! Failed to send HTTP request to server. 😞\n");
        return 1;
    }

    printf("Sending HTTP request to server... 📩\n");
    printf("HTTP request sent successfully! 🚀\n");

    char response[1024];
    int len = recv(sock, response, 1024, 0);
    if (len < 0) {
        printf("Oops! Failed to receive HTTP response from server. 😞\n");
        return 1;
    }

    printf("Receiving HTTP response from server... 📨\n");
    printf("HTTP response received successfully! 🎉\n");

    printf("%.*s", len, response);

    close(sock);

    printf("Disconnected from HTTP server. Bye! 👋\n");

    return 0;
}