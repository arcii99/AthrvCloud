//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX 1024

int main()
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_reply[MAX];
    char username[MAX], password[MAX];
    char command[MAX], userCommand[MAX];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Enter server IP address here
    server_addr.sin_port = htons(110); // POP3 port number is 110

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection error\n");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, MAX, 0) < 0)
    {
        printf("Receive failed\n");
        return 1;
    }

    // Display server response on the console
    printf("%s", server_reply);

    // Enter username and password
    printf("Enter your username: ");
    fgets(username, MAX, stdin);
    printf("Enter your password: ");
    fgets(password, MAX, stdin);

    // Send username and password to server
    sprintf(command, "USER %s", username);
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, server_reply, MAX, 0);

    sprintf(command, "PASS %s", password);
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, server_reply, MAX, 0);

    // Print the response from the server
    printf("%s", server_reply);

    // Send download command to server
    sprintf(command, "LIST\n");
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, server_reply, MAX, 0);
    
    // Print the number of emails and their sizes
    printf("%s", server_reply);
    
    // Enter the email number you want to download
    printf("Enter the email number you want to download: ");
    fgets(userCommand, MAX, stdin);
    sprintf(command, "RETR %s", userCommand);
    send(socket_desc, command, strlen(command), 0);
    recv(socket_desc, server_reply, MAX, 0);

    // Print the email body
    printf("%s", server_reply);

    // Close the socket connection
    close(socket_desc);

    return 0;
}