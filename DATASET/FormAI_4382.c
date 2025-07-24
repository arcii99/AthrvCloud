//FormAI DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    printf("Welcome to the C Port Scanner! Let's do this thing!\n");
    printf("Usage: ./scanner IP_ADDRESS START_PORT END_PORT\n");
    if (argc < 4) {
        printf("Oops! Invalid arguments. Please enter the IP address and range of ports to scan.\n");
        return 1;
    }

    char *ipAddress = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    printf("Scanning ports %d through %d on %s...\n", startPort, endPort, ipAddress);

    for (int port = startPort; port <= endPort; port++) {
        struct sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = inet_addr(ipAddress);
        serverAddress.sin_port = htons(port);

        int socketId = socket(AF_INET, SOCK_STREAM, 0);
        if (socketId < 0) {
            continue;
        }

        int connectResult = connect(socketId, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
        if (connectResult < 0) {
            close(socketId);
            continue;
        }

        printf("Port %d is open!\n", port);
        close(socketId);
    }

    printf("Scan complete! Peace out!\n");
    return 0;
}