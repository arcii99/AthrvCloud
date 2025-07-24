//FormAI DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 8080
#define MAX_BUFFER 1024

int main(int argc, char const *argv[]) {
    int sock = 0, val_read;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read input from user
        fgets(buffer, MAX_BUFFER, stdin);

        // Replace vowels with asterisk
        int length = strlen(buffer);
        for (int i = 0; i < length; i++) {
            if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u') {
                buffer[i] = '*';
            }
        }

        // Send message to server
        send(sock, buffer, strlen(buffer), 0);

        // Receive message from server
        val_read = read(sock, buffer, MAX_BUFFER);
        buffer[val_read] = '\0';

        // Display message from server
        printf("%s\n", buffer);
    }

    return 0;
}