//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char server_ip[15] = "127.0.0.1"; // IP address of the IMAP server
    int server_port = 143; // Port number of the IMAP server
    char username[50] = "username"; // Your IMAP username
    char password[50] = "password"; // Your IMAP password

    // Connect to the IMAP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Authenticate with the server
    char login_cmd[100];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    send(sock, login_cmd, strlen(login_cmd), 0);

    // Select a mailbox
    char select_cmd[100] = "SELECT INBOX\r\n";
    send(sock, select_cmd, strlen(select_cmd), 0);

    // Fetch emails from the selected mailbox
    char fetch_cmd[100] = "FETCH 1:10 BODY[HEADER.FIELDS (SUBJECT FROM)]\r\n";
    send(sock, fetch_cmd, strlen(fetch_cmd), 0);
    char response[1024];
    recv(sock, response, 1024, 0);

    // Parse the email content and display it to the user
    printf("%s", response);

    // Close the socket
    close(sock);
    
    return 0;
}