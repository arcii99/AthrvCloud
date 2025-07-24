//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

void handle_connection(int client_fd) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[100];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S",timeinfo);
    char message[1000] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html>\n<head>\n<title>Simple Web Server</title>\n</head>\n<body>\nThe server time is: ";
    strcat(message, buffer);
    strcat(message, "</body>\n</html>\n");

    write(client_fd, message, strlen(message));
    close(client_fd);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    int server_fd, client_fd, address_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        address_len = sizeof(server_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&address_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        handle_connection(client_fd);
    }
    
    return 0;
}