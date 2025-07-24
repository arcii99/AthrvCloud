//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
// Romeo and Juliet IMAP Client Example

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {
    
    // open socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        printf("Oh dreadful socket! How you betray me!\n");
        return -1;
    }
    
    // initialize server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993); // IMAP port
    server_address.sin_addr.s_addr = inet_addr("imap.gmail.com");
    
    // connect to server
    int status = connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if(status == -1) {
        printf("Why must you tarry, oh connection! My love, Juliet, needs me!\n");
        return -1;
    }
    
    // send login data
    char username[50];
    char password[50];
    printf("Enter username: ");
    fgets(username, 50, stdin);
    printf("Enter password: ");
    fgets(password, 50, stdin);
    char login[MAX_BUFFER];
    sprintf(login, "LOGIN %s %s\n", username, password);
    send(client_socket, login, strlen(login), 0);
    
    // check login status
    char login_response[MAX_BUFFER];
    recv(client_socket, login_response, MAX_BUFFER, 0);
    if(strncmp(login_response, "* OK", 4) != 0) {
        printf("Alas, my login attempt has failed! I cannot reach Juliet...\n");
        return -1;
    }
    
    // fetch inbox
    char fetch[MAX_BUFFER];
    sprintf(fetch, "FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\n");
    send(client_socket, fetch, strlen(fetch), 0);
    
    // print inbox
    char message[MAX_BUFFER];
    int message_count = 0;
    while(recv(client_socket, message, MAX_BUFFER, 0)) {
        if(strncmp(message, "* ", 2) == 0) {
            printf("%s", message);
        }
        if(strncmp(message, "Message-ID:", 11) == 0) {
            message_count++;
        }
        if(message_count > 0 && strncmp(message, ")\r\n", 3) == 0) {
            break;
        }
    }
    
    // close socket
    close(client_socket);
    printf("O, farewell cruel world! I must bid you adieu...\n");
    return 0;
}