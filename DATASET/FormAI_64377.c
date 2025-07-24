//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Client-Server Chat Application
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char buffer[1024] = {0};

    // Romeo joins the chat server
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\n Invalid Address \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Connection Failed \n");
        return -1;
    }

    printf("[Romeo joined the server.]\nEnter your message: ");

    while (1) {
        fgets(buffer, 1024, stdin);

        // replace newline with null character
        buffer[strcspn(buffer, "\n")] = 0;

        // Romeo sends a message to Juliet
        send(sock, buffer, strlen(buffer), 0);

        // clear out buffer
        memset(buffer, 0, 1024);

        // Romeo waits for Juliet's message
        valread = read(sock, message, 1024);

        printf("[Juliet]: %s\n", message);

        // clear out message
        memset(message, 0, 1024);

        printf("Enter your message: ");
    }

    return 0;
}