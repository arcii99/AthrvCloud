//FormAI DATASET v1.0 Category: Client Server Application ; Style: creative
// Creative Client Server Application Example Program

/* This application demonstrates a simple conversation between a client and server. 
The server waits for the client to send a message and responds according to the message. 
The communication between the client and server is done over sockets.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Establishing connection with the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("**** Welcome to the Creative Client Server Application ****\n");

    while(1) {
        printf("\nEnter your message: ");
        fgets(buffer, 1024, stdin);

        // Send message to the server
        send(sock, buffer, strlen(buffer), 0);

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));

        // Read message from server
        valread = read(sock, buffer, 1024);

        // Handle the server's response
        if(strncmp(buffer, "hello", 5) == 0) {
            printf("Server : Hi there! How can I help you?\n");
        }
        else if(strncmp(buffer, "bye", 3) == 0) {
            printf("Server : Goodbye! Have a nice day!\n");
            break;
        }
        else {
            printf("Server : I don't understand what you want. Could you please be more specific?\n");
        }

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    // Close the socket
    close(sock);

    printf("\n**** Goodbye! Thank you for using the Creative Client Server Application **** \n");
    return 0;
}