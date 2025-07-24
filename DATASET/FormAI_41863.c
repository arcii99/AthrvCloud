//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define POP3_PORT 110
#define MAX_BUFF 4096

int main(void){
    char* recipient = "youremail@example.com";
    char* password = "yourpassword";
    char* pop3_server = "mail.example.com";

    char* greeting_msg;
    char* send_username_msg;
    char* send_password_msg;
    char* list_msg;
    char* quit_msg;

    char read_buff[MAX_BUFF];
    char write_buff[MAX_BUFF];

    int sock_fd;
    struct sockaddr_in pop3_server_addr;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&pop3_server_addr, '\0', sizeof(pop3_server_addr));

    pop3_server_addr.sin_family = AF_INET;
    pop3_server_addr.sin_port = htons(POP3_PORT);
    pop3_server_addr.sin_addr.s_addr = inet_addr(pop3_server);

    if(connect(sock_fd, (struct sockaddr*)&pop3_server_addr, sizeof(pop3_server_addr)) < 0){
        perror("Connection Failed");
        return 0;
    }

    recv(sock_fd, read_buff, MAX_BUFF, 0);
    greeting_msg = strtok(read_buff, "\n");

    //send username to server
    snprintf(write_buff, MAX_BUFF, "USER %s\r\n", recipient);
    send(sock_fd, write_buff, strlen(write_buff), 0);

    recv(sock_fd, read_buff, MAX_BUFF, 0);
    send_username_msg = strtok(read_buff, "\n");

    //send password to server
    snprintf(write_buff, MAX_BUFF, "PASS %s\r\n", password);
    send(sock_fd, write_buff, strlen(write_buff), 0);

    recv(sock_fd, read_buff, MAX_BUFF, 0);
    send_password_msg = strtok(read_buff, "\n");

    //list messages in mailbox
    snprintf(write_buff, MAX_BUFF, "LIST\r\n");
    send(sock_fd, write_buff, strlen(write_buff), 0);

    recv(sock_fd, read_buff, MAX_BUFF, 0);
    list_msg = strtok(read_buff, "\n");

    //quit connection
    snprintf(write_buff, MAX_BUFF, "QUIT\r\n");
    send(sock_fd, write_buff, strlen(write_buff), 0);

    recv(sock_fd, read_buff, MAX_BUFF, 0);
    quit_msg = strtok(read_buff, "\n");

    printf("Greeting Message: %s\n", greeting_msg);
    printf("Username Message: %s\n", send_username_msg);
    printf("Password Message: %s\n", send_password_msg);
    printf("List Message: %s\n", list_msg);
    printf("Quit Message: %s\n", quit_msg);

    close(sock_fd);
    return 0;
}