//FormAI DATASET v1.0 Category: Networking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
#endif

#define PORT_NUMBER 8080

int main() {
    #ifdef _WIN32
        // Initialize Winsock
        WSADATA wsaData;
        int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (err != 0) {
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
        }
    #endif

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket!\n");
        return 1;
    }

    // bind socket to port
    struct sockaddr_in si_me;
    memset(&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT_NUMBER);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    int bind_result = bind(sock, (struct sockaddr*)&si_me, sizeof(si_me));
    if (bind_result < 0) {
        printf("Error binding socket to port %d!\n", PORT_NUMBER);
        return 1;
    }

    // listen for incoming connections
    int listen_result = listen(sock, 5);
    if (listen_result < 0) {
        printf("Error listening for connections!\n");
        return 1;
    }

    printf("Server listening on port %d...\n", PORT_NUMBER);

    // accept incoming connection
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    int client_sock = accept(sock, (struct sockaddr*)&si_other, &slen);
    if (client_sock < 0) {
        printf("Error accepting incoming connection!\n");
        return 1;
    }

    printf("Incoming connection accepted from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));

    // send greeting to client
    char greeting[100] = "Hello, welcome to my server!";
    send(client_sock, greeting, strlen(greeting), 0);

    // receive client message
    char message[200];
    memset(message, 0, sizeof(message));
    int recv_result = recv(client_sock, message, sizeof(message), 0);
    if (recv_result > 0) {
        printf("Client sent message: %s\n", message);
    }

    // close sockets
    #ifdef _WIN32
        closesocket(sock);
        closesocket(client_sock);
        WSACleanup();
    #else
        close(sock);
        close(client_sock);
    #endif

    return 0;
}