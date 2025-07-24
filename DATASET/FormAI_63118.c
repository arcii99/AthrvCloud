//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    char *server_ip_address, *from_address, *to_address, *message_body;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    
    if (argc != 5) {
        printf("Invalid arguments: usage %s <server ip address> <from address> <to address> <message body>\n", argv[0]);
        exit(1);
    }
    
    server_ip_address = argv[1];
    from_address = argv[2];
    to_address = argv[3];
    message_body = argv[4];
    
    // create a TCP socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Could not create socket");
        exit(1);
    }
    
    // set server address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip_address);
    server_address.sin_port = htons(25); // SMTP port is 25
    
    // connect to the SMTP server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    // receive server welcome message
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send HELO command
    sprintf(buffer, "HELO %s\r\n", server_ip_address);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to HELO command
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from_address);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to MAIL FROM command
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", to_address);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to RCPT TO command
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send DATA command
    if (send(client_socket, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to DATA command
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send message body
    sprintf(buffer, "%s\r\n.\r\n", message_body); // add "." at the end according to SMTP protocol
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to message body
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);
    
    // send QUIT command
    if (send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Could not send message to server");
        exit(1);
    }
    
    // receive response to QUIT command
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Could not receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    close(client_socket);
    return 0;
}