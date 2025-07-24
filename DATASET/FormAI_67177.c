//FormAI DATASET v1.0 Category: Socket programming ; Style: surprised
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    int sock_desc;
    struct sockaddr_in server_addr;

    char *message = "Hello from the other side!";

    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_desc == -1) {
        printf("Socket creation failed!\n");
    }
    else {
        printf("Socket created successfully!\n");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    int conn = connect(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(conn == -1) {
        printf("Connection failed!\n");
    }
    else {
        printf("Connected to server successfully!\n");
    }

    if(send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send message!\n");
    }
    else {
        printf("Message sent!\n");
    }

    char server_reply[2000];
    int recv_status;

    recv_status = recv(sock_desc, server_reply, 2000, 0);

    if(recv_status < 0) {
        printf("Failed to receive data!\n");
    }
    else {
        printf("Data received: %s\n", server_reply);
    }

    close(sock_desc);

    return 0;
}