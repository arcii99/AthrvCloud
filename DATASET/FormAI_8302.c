//FormAI DATASET v1.0 Category: Client Server Application ; Style: futuristic
// This is a futuristic style C Client-Server Application Example Program
// This program allows secure file transfer over a network connection
// It uses AES-256 encryption for secure file transfer
// It also uses TCP/IP protocol for reliable network communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/aes.h>

#define BUFF_SIZE 1024 // The maximum buffer size for file transfer
#define PORT 8080 // The Server's port number
#define ENCRYPT_KEY "my_secret_key" // The AES Encryption key

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

int encrypt_file(const char *filename, const char *key, unsigned char *iv) {
    AES_KEY aes_key;
    FILE *fp = fopen(filename, "rb");
    FILE *fp_out = fopen("encrypted_file", "wb");
    unsigned char in_buff[BUFF_SIZE];
    unsigned char out_buff[BUFF_SIZE];
    int bytes_read = 0;
    int out_buff_len = 0;

    if (fp == NULL || fp_out == NULL) {
        return -1;
    }

    AES_set_encrypt_key((unsigned char *) key, 256, &aes_key);
    fwrite(iv, 1, AES_BLOCK_SIZE, fp_out);

    while ((bytes_read = fread(in_buff, 1, BUFF_SIZE, fp)) > 0) {
        AES_cbc_encrypt(in_buff, out_buff, bytes_read , &aes_key, iv, AES_ENCRYPT);
        fwrite(out_buff, 1, bytes_read, fp_out);
        out_buff_len += bytes_read;
    }
    fclose(fp);
    fclose(fp_out);

    return out_buff_len;
}

int decrypt_file(const char *filename, const char *key, unsigned char *iv) {
    AES_KEY aes_key;
    FILE *fp = fopen(filename, "rb");
    FILE *fp_out = fopen("decrypted_file", "wb");
    unsigned char in_buff[BUFF_SIZE];
    unsigned char out_buff[BUFF_SIZE];
    int bytes_read = 0;
    int out_buff_len = 0;

    if (fp == NULL || fp_out == NULL) {
        return -1;
    }

    AES_set_decrypt_key((unsigned char *) key, 256, &aes_key);
    fread(iv, 1, AES_BLOCK_SIZE, fp);

    while ((bytes_read = fread(in_buff, 1, BUFF_SIZE, fp)) > 0) {
        AES_cbc_encrypt(in_buff, out_buff, bytes_read , &aes_key, iv, AES_DECRYPT);
        fwrite(out_buff, 1, bytes_read, fp_out);
        out_buff_len += bytes_read;
    }
    fclose(fp);
    fclose(fp_out);

    return out_buff_len;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFF_SIZE] = {0};

    SSL_CTX *ctx;
    SSL *ssl;
    const SSL_METHOD *method;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = SSLv23_server_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        handle_error("Error initializing SSL context");
    }

    SSL_CTX_set_ecdh_auto(ctx, 1);
    if (SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
        handle_error("Error loading certificate");
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM) <= 0) {
        handle_error("Error loading private key");
    }

    if (!SSL_CTX_check_private_key(ctx)) {
        handle_error("Error checking private key");
    }

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("Error creating socket");
    }

    // Attach socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("Error binding socket to port");
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        handle_error("Error listening for incoming connections");
    }

    while (1) {
        printf("Waiting for incoming connection...\n");

        // Accept an incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            handle_error("Error accepting incoming connection");
        }

        printf("Incoming connection accepted\n");

        ssl = SSL_new(ctx);
        SSL_set_fd(ssl, new_socket);

        // Perform SSL handshake
        if (SSL_accept(ssl) <= 0) {
            handle_error("Error performing SSL handshake");
        }

        // Receive encrypted file name from client
        valread = SSL_read(ssl, buffer, sizeof(buffer));
        if (valread <= 0) {
            handle_error("Error receiving file name from client");
        }

        // Decrypt the file name using AES Encryption
        unsigned char iv[AES_BLOCK_SIZE];
        memset(iv, 0x00, AES_BLOCK_SIZE);
        int filename_len = decrypt_file(buffer, ENCRYPT_KEY, iv);
        char filename[filename_len+1];
        memset(filename, 0x00, sizeof(filename));
        FILE *fp = fopen("decrypted_file", "rb");
        fread(filename, 1, filename_len, fp);
        fclose(fp);

        // Send back an acknowledgement to confirm receipt of file name
        valread = SSL_write(ssl, "ACK", strlen("ACK"));
        if (valread < 0) {
            handle_error("Error sending acknowledgement to client");
        }

        printf("Received file name: %s\n", filename);

        // Receive encrypted file content from client
        unsigned char encrypted_file_buff[BUFF_SIZE];
        int encrypted_file_len = 0;
        unsigned char iv_file[AES_BLOCK_SIZE];
        memset(iv_file, 0x00, AES_BLOCK_SIZE);

        while (1) {
            valread = SSL_read(ssl, encrypted_file_buff, sizeof(encrypted_file_buff));
            if (valread <= 0) {
                handle_error("Error receiving file content from client");
            }

            if (valread < sizeof(encrypted_file_buff)) {
                encrypted_file_len += valread;
                break;
            }

            encrypted_file_len += valread;
        }

        // Decrypt the file content using AES Encryption
        FILE *fp_out = fopen(filename, "wb");
        fwrite(iv_file, 1, AES_BLOCK_SIZE, fp_out);
        int bytes_written = 0;

        while (bytes_written < encrypted_file_len) {
            AES_KEY aes_key;
            AES_set_decrypt_key((unsigned char *) ENCRYPT_KEY, 256, &aes_key);
            int bytes_to_write = encrypted_file_len - bytes_written;
            if (bytes_to_write > BUFF_SIZE) {
                bytes_to_write = BUFF_SIZE;
            }

            unsigned char decrypted_buff[bytes_to_write];
            AES_cbc_encrypt(&encrypted_file_buff[bytes_written], decrypted_buff, bytes_to_write, &aes_key, iv_file, AES_DECRYPT);
            fwrite(decrypted_buff, 1, bytes_to_write, fp_out);
            bytes_written += bytes_to_write;
        }

        fclose(fp_out);

        // Send back an acknowledgement to confirm receipt of file content
        valread = SSL_write(ssl, "ACK", strlen("ACK"));
        if (valread < 0) {
            handle_error("Error sending acknowledgement to client");
        }

        printf("File received and saved as %s\n", filename);

        // Clean up connections
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(new_socket);
    }

    SSL_CTX_free(ctx);
    
    return 0;
}