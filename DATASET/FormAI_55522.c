//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_SIZE 100
#define MAX_RESPONSE_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char command[MAX_COMMAND_SIZE];
    char response[MAX_RESPONSE_SIZE];

    // Create a socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        error("Error: Could not create socket.");
    }
    printf("Socket created\n");

    // Set up server address
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);

    // Connect to server
    if (connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0)
    {
        error("Error: Could not connect to server.");
    }
    printf("Connected to server\n");

    // Receive server welcome message
    if (recv(sock , response , MAX_RESPONSE_SIZE , 0) < 0)
    {
        error("Error: Could not receive welcome message.");
    }
    printf("%s\n", response);

    // Send user name
    printf("User: ");
    fgets(command, MAX_COMMAND_SIZE, stdin);
    if (send(sock , command , strlen(command) , 0) < 0)
    {
        error("Error: Could not send user name.");
    }

    // Receive server response
    if (recv(sock , response , MAX_RESPONSE_SIZE , 0) < 0)
    {
        error("Error: Could not receive user response.");
    }
    printf("%s\n", response);

    // Send password
    printf("Password: ");
    fgets(command, MAX_COMMAND_SIZE, stdin);
    if (send(sock , command , strlen(command) , 0) < 0)
    {
        error("Error: Could not send password.");
    }

    // Receive server response
    if (recv(sock , response , MAX_RESPONSE_SIZE , 0) < 0)
    {
        error("Error: Could not receive password response.");
    }
    printf("%s\n", response);

    // Main loop
    while (1)
    {
        printf("> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);

        // Send command
        if (send(sock , command , strlen(command) , 0) < 0)
        {
            error("Error: Could not send command.");
        }

        // Receive server response
        if (recv(sock , response , MAX_RESPONSE_SIZE , 0) < 0)
        {
            error("Error: Could not receive response.");
        }
        printf("%s\n", response);
    }

    return 0;
}