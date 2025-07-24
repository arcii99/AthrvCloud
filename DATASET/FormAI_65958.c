//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
// QoS monitor program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define QOS_THRESHOLD 50

int sock_fd, client_fd;

void handle_sigint(int sig)
{
    printf("Shutting down QoS monitor...\n");
    close(client_fd);
    close(sock_fd);
    exit(0);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int len, n;

    // set up signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(12345);

    // bind socket to port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sock_fd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("QoS monitor running...\n");

    // main loop
    while (1) {
        len = sizeof(client_addr);
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &len);

        if (client_fd == -1) {
            perror("accept");
            exit(1);
        }

        // read data from client
        n = read(client_fd, buffer, BUFFER_SIZE);

        if (n == -1) {
            perror("read");
            exit(1);
        }

        // convert data to integer
        int qos_value = atoi(buffer);

        // check if QoS value is below threshold
        if (qos_value < QOS_THRESHOLD) {
            // QoS is poor, notify network admin
            printf("QoS is poor! Value is %d\n", qos_value);
            // insert code to send notification to network admin here
        }

        // send response back to client
        strcpy(buffer, "OK");
        n = write(client_fd, buffer, strlen(buffer)+1);

        if (n == -1) {
            perror("write");
            exit(1);
        }

        close(client_fd);
    }

    return 0;
}