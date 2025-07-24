//FormAI DATASET v1.0 Category: Networking ; Style: scientific
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define PORT 5000 // Define the Port

int main(int argc, char *argv[]){

    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char message[1024] = {0};
    char buffer[1024] = {0};

    // Create the socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("\n Socket Creation Error \n");
        return -1;
    }

    // Assign the IP, PORT and Address family
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if(connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))<0){
        printf("\n Connection Failed \n");
        return -1;
    }

    printf("Connected to the Server \n");

    // Keep the chat running
    while(1){

        printf("\n Enter your message: ");
        fgets(message, 1024, stdin); // Get the input message

        // Send the message to the server
        send(sock, message, strlen(message), 0);

        // Break when user types 'exit'
        if(strncmp(message, "exit", 4)==0){
            break;
        }

        // Receive the response from the server
        valread = read(sock, buffer, 1024);

        // Print the response
        printf("Server Response: %s\n", buffer);

        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        memset(message, 0, sizeof(message)); // Clear the message

    }

    // Close the socket
    close(sock);

    return 0;
}