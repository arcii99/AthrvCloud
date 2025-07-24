//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock, conn, port = 587;
    char *email_server = "smtp.gmail.com";
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("smtp.gmail.com");
    server.sin_port = htons(port);

    // connect to server
    conn = connect(sock, (struct sockaddr *)&server, sizeof(server));

    // check if connection is successful
    if (conn < 0) {
        perror("Connection failed ");
        return 1;
    }

    printf("Connection successful\n");

    close(sock);
    return 0;
}