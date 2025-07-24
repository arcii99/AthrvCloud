//FormAI DATASET v1.0 Category: Networking ; Style: grateful
/* 
 * Thank you for choosing to learn Networking with C!
 * In this program, we will create a simple client-server communication 
 * application using TCP/IP sockets.
 * 
 * The client side will be responsible for sending messages to the server,
 * while the server side will receive the messages and send a reply back to 
 * the client.
 *
 * Let's get started!
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080 // Port to be used for the connection

int main(int argc, char const *argv[]) {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    
    // Creating the socket object
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error! \n");
        return -1;
    }
    
    // Setting the server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address / Address not supported! \n");
        return -1;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed! \n");
        return -1;
    }

    printf("\n Connection successful! \n");

    // Loop to send and receive messages
    while(1) {
        char buffer[1024] = {0};
        printf("\n Enter message to send to server: ");
        fgets(buffer, 1024, stdin);
        send(sock, buffer, strlen(buffer), 0);
        printf("\n Message sent to server! \n");

        valread = read(sock, buffer, 1024);
        printf("\n Server replied with message: %s", buffer);
    }

    // Closing the socket
    close(sock);

    return 0;
}