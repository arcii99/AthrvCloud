//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shape shifting
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sock;
    struct sockaddr_in serverAddr;
    struct hostent *host;

    host = gethostbyname("server_address");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(143);
    serverAddr.sin_addr = *((struct in_addr*) host->h_addr);
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Now you can send and receive IMAP commands using the socket
    close(sock);
    return 0;
}