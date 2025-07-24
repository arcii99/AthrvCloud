//FormAI DATASET v1.0 Category: Client Server Application ; Style: paranoid
// A paranoid client server application that sends encrypted messages

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aesKey, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aesKey, iv, AES_DECRYPT);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create a random 128 bit key and IV
    unsigned char key[AES_BLOCK_SIZE], iv[AES_BLOCK_SIZE];
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        printf("Error generating random bytes!\n");
        exit(1);
    }

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the server socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    // Send the key and IV to the client
    if (send(new_socket, key, sizeof(key), 0) != sizeof(key)) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    printf("Key sent to client.\n");
    if (send(new_socket, iv, sizeof(iv), 0) != sizeof(iv)) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    printf("IV sent to client.\n");

    // Receive encrypted messages from the client and decrypt them
    while (1) {
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0)
            break;

        unsigned char ciphertext[BUFFER_SIZE] = {0};
        memcpy(ciphertext, buffer, valread);

        unsigned char decrypted[BUFFER_SIZE] = {0};
        decrypt(ciphertext, valread, key, iv, decrypted);

        printf("Client: %s\n", decrypted);

        memset(buffer, 0, BUFFER_SIZE);
        memset(ciphertext, 0, BUFFER_SIZE);
    }

    // Cleanup
    close(new_socket);
    close(server_fd);

    return 0;
}