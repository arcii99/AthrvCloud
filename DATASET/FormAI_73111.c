//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define POP3_SERVER "pop.gmail.com" // Change to your POP3 server
#define POP3_PORT 995 // Change to the POP3 SSL port

int main()
{
    int sock;
    struct sockaddr_in pop3_server;
    char cmd[1024], recv_buf[1024];

    // Create an SSL socket
    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Set up the server address struct
    memset(&pop3_server, 0, sizeof(pop3_server));
    pop3_server.sin_family = AF_INET;
    pop3_server.sin_port = htons(POP3_PORT);
    pop3_server.sin_addr.s_addr = inet_addr(POP3_SERVER);

    // Connect to the server
    if(connect(sock, (struct sockaddr *)&pop3_server, sizeof(pop3_server)) < 0) {
        perror("Failed to connect to server");
        close(sock);
        return 1;
    }

    // Receive the server's greeting message
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive greeting message from server");
        close(sock);
        return 1;
    }

    printf("Server: %s", recv_buf);

    // Send the user's username
    printf("Username: ");
    fgets(cmd, sizeof(cmd), stdin);
    sprintf(cmd, "USER %s", strtok(cmd, "\n"));

    if(send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("Failed to send username");
        close(sock);
        return 1;
    }

    // Receive the server's response to the username
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to username from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Send the user's password
    printf("Password: ");
    fgets(cmd, sizeof(cmd), stdin);
    sprintf(cmd, "PASS %s", strtok(cmd, "\n"));

    if(send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("Failed to send password");
        close(sock);
        return 1;
    }

    // Receive the server's response to the password
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to password from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Send the command to list all messages
    if(send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        perror("Failed to send LIST command");
        close(sock);
        return 1;
    }

    // Receive the server's response to the LIST command
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to LIST command from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Send the command to retrieve the first message
    if(send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) < 0) {
        perror("Failed to send RETR command");
        close(sock);
        return 1;
    }

    // Receive the server's response to the RETR command
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to RETR command from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Send the command to delete the first message
    if(send(sock, "DELE 1\r\n", strlen("DELE 1\r\n"), 0) < 0) {
        perror("Failed to send DELE command");
        close(sock);
        return 1;
    }

    // Receive the server's response to the DELE command
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to DELE command from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Send the command to quit
    if(send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Failed to send QUIT command");
        close(sock);
        return 1;
    }

    // Receive the server's response to the QUIT command
    if(recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
        perror("Failed to receive response to QUIT command from server");
        close(sock);
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    // Close the socket
    close(sock);

    return 0;
}