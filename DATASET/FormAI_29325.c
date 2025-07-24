//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 4096
#define PORT 80

char* banner = "Ye Olde Wireless Scanner\n\n";

void usage(char* argv[])
{
    printf("Usage: %s [target]\n", argv[0]);
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        usage(argv);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up address struct
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to target
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        perror("Error connecting to target");
        exit(1);
    }

    // Send banner
    send(sock, banner, strlen(banner), 0);

    // Receive response
    char response[MAX_PACKET_SIZE];
    if(recv(sock, response, MAX_PACKET_SIZE, 0) == -1)
    {
        perror("Error receiving response");
        exit(1);
    }

    printf("%s\n", response);

    // Close socket
    close(sock);

    return 0;
}