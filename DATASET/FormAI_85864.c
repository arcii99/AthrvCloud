//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 110

int main()
{
    // Step 1: Creating a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0)
    {
        perror("Socket creation failed");
        return 1;
    }

    // Step 2: Connecting to the server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to the POP3 server.\n");

    // Step 3: Reading server greeting
    char server_message[1024];
    memset(server_message, 0, sizeof(server_message));
    read(client_socket, server_message, sizeof(server_message));
    printf("POP3 Server: %s", server_message);

    // Step 4: Sending the username to the server
    char username[100];
    printf("Enter your username: ");
    fgets(username, 100, stdin);
    char user_command[100];
    sprintf(user_command, "USER %s", username);
    write(client_socket, user_command, strlen(user_command));

    // Step 5: Reading server response to username
    memset(server_message, 0, sizeof(server_message));
    read(client_socket, server_message, sizeof(server_message));
    printf("POP3 Server: %s", server_message);

    // Step 6: Sending the password to the server
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    char pass_command[100];
    sprintf(pass_command, "PASS %s", password);
    write(client_socket, pass_command, strlen(pass_command));

    // Step 7: Reading server response to password
    memset(server_message, 0, sizeof(server_message));
    read(client_socket, server_message, sizeof(server_message));
    printf("POP3 Server: %s", server_message);

    // Step 8: Sending the list command to the server
    char list_command[100];
    sprintf(list_command, "LIST");
    write(client_socket, list_command, strlen(list_command));

    // Step 9: Reading server response to list command
    memset(server_message, 0, sizeof(server_message));
    read(client_socket, server_message, sizeof(server_message));
    printf("POP3 Server: %s", server_message);

    // Step 10: Quitting the session
    char quit_command[100];
    sprintf(quit_command, "QUIT");
    write(client_socket, quit_command, strlen(quit_command));

    // Step 11: Reading quit response from server
    memset(server_message, 0, sizeof(server_message));
    read(client_socket, server_message, sizeof(server_message));
    printf("POP3 Server: %s", server_message);

    // Step 12: Closing the socket
    close(client_socket);

    return 0;
}