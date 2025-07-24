//FormAI DATASET v1.0 Category: Simple Web Server ; Style: puzzling
/* Welcome to the Puzzling Simple Web Server!
 * Get ready for a code challenge that will test your brain and your coding skills!
 * This server listens on port 8080 and serves up a simple website with a twist.
 * Instead of serving traditional HTML pages, it serves up messages that can only
 * be decoded with a secret key.
 * 
 * Your challenge is to find the key and decode the messages. Good luck!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define SECRET_KEY "PUZZLE"

// The encoded message
char *message = "765d596b79596b6859766b59696e6b796e68765d596c6b";

// The function to decode the message using the secret key
void decode_message(char *key) {
    int length = strlen(message);
    char decoded[length / 2 + 1];
    decoded[length / 2] = '\0';
    for (int i = 0; i < length; i += 2) {
        char byte[3] = { message[i], message[i+1], '\0' };
        decoded[i / 2] = (char) (strtol(byte, NULL, 16) ^ key[i % strlen(key)]);
    }
    printf("%s\n", decoded);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 19\n\n";
        char *page = "PUZZLING WEB SERVER\n";
        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        decode_message(SECRET_KEY);
        send(new_socket, response, strlen(response), 0);
        send(new_socket, page, strlen(page), 0);
        close(new_socket);
    }
    return 0;
}