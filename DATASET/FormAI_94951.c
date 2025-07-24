//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<time.h>

#define BUFFER_SIZE 100
#define SERVER_PORT 9001

int main(int argc, char *argv[])
{
    int socket_fd, client_socket_fd, num_bytes, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if(bind(socket_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if(listen(socket_fd, 3) < 0)
    {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    int client_len = sizeof(client_addr);

    if((client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0)
    {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int num1 = rand()%20, num2 = rand()%20;

    sprintf(buffer, "What is the sum of %d and %d?\n", num1, num2);
    send(client_socket_fd, buffer, strlen(buffer), 0);

    memset(buffer, 0, BUFFER_SIZE);
    if((num_bytes = recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) < 0)
    {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }

    int answer = atoi(buffer);
    memset(buffer, 0, BUFFER_SIZE);

    if(answer == num1 + num2)
    {
        sprintf(buffer, "Correct! %d + %d = %d\n", num1, num2, answer);
    }
    else
    {
        sprintf(buffer, "Wrong! %d + %d = %d\n", num1, num2, num1 + num2);
    }
    send(client_socket_fd, buffer, strlen(buffer), 0);

    close(client_socket_fd);
    close(socket_fd);

    return 0;
}