//FormAI DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CUSTOMERS 10

typedef struct {
    pid_t pid;
    char name[30];
    char status[10];
} Process;

Process customers[MAX_CUSTOMERS];

void get_processes() {
    FILE *fp;
    char output[50];
    pid_t pid;
    char name[30];
    char status[10];

    fp = popen("ps -aux", "r");
    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(output, sizeof output, fp) != NULL && i < MAX_CUSTOMERS) {
        sscanf(output, "%*s %d %*s %*s %*s %*s %*s %*s %*s %*s %*s %[^\n]s",
         &pid, name);
        if (pid != 0) {
            strcpy(customers[i].name, name);
            customers[i].pid = pid;
            i++;
        }
    }
    fclose(fp);
}

void display_processes() {
    printf("\t\tSystem Process Viewer\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("%-15s %-25s %-10s\n", "Process ID", "Process Name", "Status");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].pid != 0) {
            printf("%-15d %-25s %-10s\n", customers[i].pid, customers[i].name, customers[i].status);
        }
    }
}

void *server_function() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char hello[] = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, 
        sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
            (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
        close(new_socket);
    }
}

void *client_function() {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[] = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
}

int main() {
    pthread_t server_thread, client_thread;

    pthread_create(&server_thread, NULL, server_function, NULL);
    pthread_create(&client_thread, NULL, client_function, NULL);

    get_processes();
    display_processes();

    pthread_join(server_thread, NULL);
    pthread_join(client_thread, NULL);

    return 0;
}