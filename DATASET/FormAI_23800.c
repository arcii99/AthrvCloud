//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket!\n");
        return -1;
    }

    // Fill in server information
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Error: Invalid address or address not supported!\n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed!\n");
        return -1;
    }

    // Send message to server
    char message[] = "Hello server, this is a QoS monitor!";
    send(sock, message, strlen(message), 0);
    printf("Message sent to server!\n");

    // Receive response from server
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}