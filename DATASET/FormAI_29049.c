//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("Usage: %s <host> <start-port> <end-port>\n", argv[0]);
        return 0;
    }
    
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    
    printf("Scanning ports %d through %d on %s...\n", start_port, end_port, host);
    
    struct hostent *he;
    struct sockaddr_in addr;
    
    if ((he = gethostbyname(host)) == NULL) {
        printf("Error: Cannot resolve '%s'\n", host);
        return 1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(addr.sin_zero), '\0', 8);
    
    int sock;
    
    for (int i = start_port; i <= end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)) == 0) {
            printf("Port %d is open\n", i);
        }
        close(sock);
    }
    
    printf("Scan complete.\n");
    
    return 0;
}