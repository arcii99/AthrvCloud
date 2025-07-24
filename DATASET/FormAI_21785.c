//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void mapper(char *ip) {
    char command[500];
    sprintf(command, "nmap -sP %s/24 | awk '/is up/ {print up}; {gsub (/\(|\)/,\"\",$3); up = $3}'", ip);
    printf("Running command: %s\n", command);
    system(command);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);
        printf("Received IP address: %s\n", buffer);

        mapper(buffer);

        char *filename = "temp.txt";

        FILE *fp;
        fp = fopen(filename, "r");

        if (fp == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        char temp[512];
        char output[1024] = {0};

        while (fgets(temp, 512, fp) != NULL) {
            strcat(output, temp);
        }

        fclose(fp);

        send(new_socket, output, strlen(output), 0);
        printf("Sent response to client\n");

        close(new_socket);
    }

    return 0;
}