//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

void scan_port(const char* host, int port) {
    struct sockaddr_in sa;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, host, &sa.sin_addr);
    if (connect(sd, (struct sockaddr*)&sa, sizeof(sa)) == 0) {
        printf("%s:%d - OPEN\n", host, port);
    } else {
        printf("%s:%d - CLOSED\n", host, port);
    }
    close(sd);
}

int main() {
    const char* host = "127.0.0.1";
    int start_port = 1;
    int end_port = 1024;
    printf("Scanning ports on %s...\n", host);
    for (int port = start_port; port <= end_port; port++) {
        scan_port(host, port);
    }
    printf("Port scan complete\n");
    return 0;
}