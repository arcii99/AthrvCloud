//FormAI DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

struct sockaddr_in target;

void scan_port(int port) {
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open\n", port);
    }
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port-range>\n", argv[0]);
        return 1;
    }
    char *range = argv[1];
    char *ptr = strchr(range, '-');
    if (ptr == NULL) {
        printf("Invalid port range specified.\n");
        return 1;
    }
    int low_port = atoi(range);
    int high_port = atoi(ptr+1);
    if (low_port > high_port) {
        printf("Invalid port range specified.\n");
        return 1;
    }
    for (int port=low_port; port<=high_port; port++) {
        scan_port(port);
    }
    return 0;
}