//FormAI DATASET v1.0 Category: Socket programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char prompt[] = "Say something to the server: ";
    
    // Create socket client
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Get input from user
    while(1) {
        write(STDOUT_FILENO, prompt, sizeof(prompt));
        memset(buffer, 0, 1024);
        if (fgets(buffer, 1024, stdin) != NULL) {
            strtok(buffer, "\n"); // Remove new line character at the end
        }
        
        // Send user input to server
        send(sock, buffer, strlen(buffer), 0);

        // Receive message from server
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }

    return 0;
}