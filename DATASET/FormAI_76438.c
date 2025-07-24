//FormAI DATASET v1.0 Category: Client Server Application ; Style: beginner-friendly
/* This is a simple Client-Server Application in C Programming Language.
   The client is responsible for sending a message to the server and the server
   receives the message, converts it to uppercase and sends it back to the client.
   The client then displays the uppercase message to the user. */

// Header files
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
    char message[1024] = {0}, buffer[1024] = {0};

    // Creating the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Configuring socket address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Establishing the connection with the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Getting message from user
    printf("Enter a message: ");
    scanf("%[^\n]%*c", message);

    // Sending the message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent to Server\n");

    // Receiving message from the server
    valread = read(sock, buffer, 1024);
    printf("Uppercase message received from Server: %s\n", buffer);

    // Closing the socket
    close(sock);
    return 0;
}