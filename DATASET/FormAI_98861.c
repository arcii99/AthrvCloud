//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define MAX_LINE 1024

void proxy(int *client_d) {
    char buf[MAX_LINE];
    int i, n;
    int proxy_d;
    struct sockaddr_in proxy_addr;

    if ((proxy_d = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Unable to create socket\n");
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to the IP you'd like
    proxy_addr.sin_port = htons(8080); // Change this to the port you'd like

    if (connect(proxy_d, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Unable to connect to proxy\n");
    }

    while ((n = read(*client_d, buf, MAX_LINE)) > 0) {
        if (write(proxy_d, buf, n) < 0) {
            perror("Failed to write to proxy\n");
            break;
        }

        memset(buf, 0, sizeof(buf));

        if ((n = read(proxy_d, buf, MAX_LINE)) > 0) {
            if (write(*client_d, buf, n) < 0) {
                perror("Failed to write to client\n");
                break;
            }
        } else {
            break;
        }

        memset(buf, 0, sizeof(buf));
    }

    close(proxy_d);
    close(*client_d);
}

void serve(int server_d) {
    int client_d;
    struct sockaddr_in client_addr;
    int len = sizeof(client_addr);
    printf("Proxy server started!\n");

    while (1) {
        if ((client_d = accept(server_d, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("Failed to accept client connection\n");
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Failed to fork new process\n");
        } else if (pid == 0) {
            close(server_d);
            proxy(&client_d);
            exit(0);
        } else {
            close(client_d);
        }

    }
}

int main(int argc, char *argv[]) {
    int server_d;
    struct sockaddr_in server_addr;

    if ((server_d = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8888); // Change the port you'd like

    if (bind(server_d, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket\n");
        return 1;
    }

    if (listen(server_d, SOMAXCONN) < 0) {
        perror("Failed to listen for incoming connections\n");
        return 1;
    }

    serve(server_d);

    return 0;
}