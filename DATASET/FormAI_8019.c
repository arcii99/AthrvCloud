//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread, addrlen = sizeof(address);
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char *remote_ip = "192.168.0.1"; // Replace with the IP address of the remote control device

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, remote_ip, &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    while (1)
    {
        printf("Enter command (takeoff/land/move): ");
        fgets(buffer, 1024, stdin);
        send(sock, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "land\n") == 0)
            break;

        memset(buffer, 0, sizeof(buffer));
        valread = read(sock, buffer, 1024);
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}