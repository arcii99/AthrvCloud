//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

  printf("Welcome to the IMAP Client!\n");

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Server details
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(993);  // IMAP port
  server_address.sin_addr.s_addr = inet_addr("192.168.10.10");  // Server IP

  // Connect to server
  if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
    perror("Connection to server failed");
    exit(EXIT_FAILURE);
  }

  // Initialize OpenSSL
  SSL_load_error_strings();
  OpenSSL_add_ssl_algorithms();
  SSL_CTX* sslctx = SSL_CTX_new(TLSv1_2_client_method());

  if (sslctx == NULL) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  SSL* ssl = SSL_new(sslctx);
  SSL_set_fd(ssl, sockfd);

  // Start TLS handshake
  if (SSL_connect(ssl) != 1) {
    perror("TLS handshake failed");
    exit(EXIT_FAILURE);
  }

  // Login credentials
  char username[] = "my_username";
  char password[] = "secret_password";

  // Send login command
  char login_command[BUFFER_SIZE];
  snprintf(login_command, BUFFER_SIZE, "LOGIN %s %s", username, password);
  SSL_write(ssl, login_command, strlen(login_command));

  // Receive response from server
  char response[BUFFER_SIZE];
  memset(response, 0, BUFFER_SIZE);
  SSL_read(ssl, response, BUFFER_SIZE);

  // Check if login was successful
  char* response_code = strstr(response, "OK");
  if (response_code == NULL) {
    printf("Login failed.\n");
    exit(EXIT_FAILURE);
  }

  // List all mailboxes
  SSL_write(ssl, "LIST \"\" *\r\n", 11);
  SSL_read(ssl, response, BUFFER_SIZE);
  printf("Mailboxes:\n%s", response);  // Print list of mailboxes

  // Select mailbox
  printf("Enter mailbox name: ");
  char mailbox_name[BUFFER_SIZE];
  memset(mailbox_name, 0, BUFFER_SIZE);
  fgets(mailbox_name, BUFFER_SIZE, stdin);
  mailbox_name[strcspn(mailbox_name, "\n")] = '\0';
  char select_command[BUFFER_SIZE];
  snprintf(select_command, BUFFER_SIZE, "SELECT %s\r\n", mailbox_name);
  SSL_write(ssl, select_command, strlen(select_command));
  SSL_read(ssl, response, BUFFER_SIZE);  // Receive response from server
  printf("%s\n", response);  // Print response

  // Fetch emails
  char fetch_command[BUFFER_SIZE];
  snprintf(fetch_command, BUFFER_SIZE, "FETCH 1:* BODY[HEADER.FIELDS (SUBJECT FROM)]\r\n");
  SSL_write(ssl, fetch_command, strlen(fetch_command));

  // Receive email headers
  int bytes_received = 0;
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);

  while ((bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE)) > 0) {
    printf("%s", buffer);
    memset(buffer, 0, BUFFER_SIZE);
  }

  // Logout and close SSL connection
  SSL_write(ssl, "LOGOUT\r\n", 8);
  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(sslctx);

  printf("Goodbye! Thanks for using the IMAP Client.\n");
  close(sockfd);

  return 0;
}