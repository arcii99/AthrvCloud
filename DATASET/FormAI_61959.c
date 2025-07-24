//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *username;
    char *password;
    char *server_address;
    int server_port;
    int mailbox_number;
} email_account;

void *imap_client_thread(void *account);

int main() {
    // initialize email account information
    email_account account = {
        .username = "example@gmail.com",
        .password = "password",
        .server_address = "imap.gmail.com",
        .server_port = 993,
        .mailbox_number = 1
    };

    pthread_t client_thread;
    pthread_create(&client_thread, NULL, imap_client_thread, (void *) &account);
    pthread_detach(client_thread);

    // main thread continues to do other tasks
    while (1) {
        // perform other tasks
        sleep(1);
    }

    return 0;
}

void *imap_client_thread(void *arg) {
    email_account account = *(email_account *) arg;
    int sock;
    struct sockaddr_in server_addr;

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        pthread_exit(NULL);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(account.server_port);
    if (inet_pton(AF_INET, account.server_address, &server_addr.sin_addr) == -1) {
        perror("Invalid server IP address");
        pthread_exit(NULL);
    }

    // connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Server connection error");
        pthread_exit(NULL);
    }

    // receive server greeting
    char greeting[BUFFER_SIZE];
    if (recv(sock, greeting, BUFFER_SIZE, 0) == -1) {
        perror("Server greeting receive error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", greeting);

    // send login credentials
    char login_credential[BUFFER_SIZE];
    sprintf(login_credential, "login %s %s\r\n", account.username, account.password);
    if (send(sock, login_credential, strlen(login_credential), 0) == -1) {
        perror("Login request send error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", login_credential);

    // receive login result
    char login_result[BUFFER_SIZE];
    if (recv(sock, login_result, BUFFER_SIZE, 0) == -1) {
        perror("Login result receive error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", login_result);

    // select mailbox
    char select_mailbox[BUFFER_SIZE];
    sprintf(select_mailbox, "select INBOX\r\n");
    if (send(sock, select_mailbox, strlen(select_mailbox), 0) == -1) {
        perror("Select mailbox request send error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", select_mailbox);

    // receive mailbox selection result
    char mailbox_selection_result[BUFFER_SIZE];
    if (recv(sock, mailbox_selection_result, BUFFER_SIZE, 0) == -1) {
        perror("Mailbox selection result receive error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", mailbox_selection_result);

    // fetch mailbox messages
    char fetch_mailbox_messages[BUFFER_SIZE];
    sprintf(fetch_mailbox_messages, "fetch 1:%d body[text]\r\n", account.mailbox_number);
    if (send(sock, fetch_mailbox_messages, strlen(fetch_mailbox_messages), 0) == -1) {
        perror("Fetch mailbox messages request send error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", fetch_mailbox_messages);

    // receive mailbox messages
    char mailbox_messages[BUFFER_SIZE];
    if (recv(sock, mailbox_messages, BUFFER_SIZE, 0) == -1) {
        perror("Mailbox messages receive error");
        close(sock);
        pthread_exit(NULL);
    }
    printf("%s", mailbox_messages);

    // close socket
    close(sock);

    pthread_exit(NULL);
}