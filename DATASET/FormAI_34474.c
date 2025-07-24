//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

int main(int argc, char* argv[]){
    // create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1){
        printf("Could not create socket\n");
        return 1;
    }
    
    // defining the address
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of SMTP server
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // port number of SMTP server
    
    //connect to the remote server
    if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
        printf("Connection failed\n");
        return 1;
    }
    
    // Receive the response
    char server_reply[2000];
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send HELO message to server
    char *helo = "HELO localhost\r\n";
    if(send(socket_desc, helo, strlen(helo), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send MAIL FROM message to server
    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    if(send(socket_desc, mail_from, strlen(mail_from), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send RCPT TO message to server
    char *rcpt_to = "RCPT TO:<receiver@example.com>\r\n";
    if(send(socket_desc, rcpt_to, strlen(rcpt_to), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send DATA message to server
    char *data = "DATA\r\n";
    if(send(socket_desc, data, strlen(data), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send message body to server
    char *message_body = "From: sender@example.com\r\nTo: receiver@example.com\r\nSubject: Test\r\nTesting SMTP client implementation in C\r\n.\r\n";
    if(send(socket_desc, message_body, strlen(message_body), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // Send QUIT message to server
    char *quit = "QUIT\r\n";
    if(send(socket_desc, quit, strlen(quit), 0) < 0){
        printf("Send failed\n");
        return 1;
    }
    if(recv(socket_desc, server_reply, 2000, 0) < 0){
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply: %s\n", server_reply);
    
    // close the socket
    close(socket_desc);
    return 0;
}