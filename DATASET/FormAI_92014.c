//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 42069

int main(int argc, char const *argv[]) {
    // Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the address details
    struct sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sock, 1) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Please solve the puzzle to establish a connection\n");

    while (1) {
        // Accept a connection
        int new_sock = accept(sock, NULL, NULL);
        if (new_sock == -1) {
            perror("accept");
            continue;
        }

        char *secret_word = "chatbot";
        char response[255];
        int guess_count = 0;

        while (1) {
            // Send the prompt
            const char *prompt = "Guess the secret word: ";
            send(new_sock, prompt, strlen(prompt), 0);

            // Receive the guess
            char guess[255];
            ssize_t bytes_recv = recv(new_sock, guess, sizeof(guess), 0);
            if (bytes_recv == -1) {
                perror("recv");
                close(new_sock);
                break;
            }
            guess[bytes_recv] = '\0';

            // Check the guess
            if (strcmp(guess, secret_word) == 0) {
                const char *correct = "Correct! Connection Established!\n";
                send(new_sock, correct, strlen(correct), 0);
                break;
            } else {
                guess_count++;
                sprintf(response, "Incorrect! You have %d more guesses\n", 3 - guess_count);
                send(new_sock, response, strlen(response), 0);

                // Too many incorrect guesses
                if (guess_count == 3) {
                    const char *failure = "Connection refused, too many incorrect guesses!\n";
                    send(new_sock, failure, strlen(failure), 0);
                    close(new_sock);
                    break;
                }
            }
        }
    }

    return 0;
}