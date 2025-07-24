//FormAI DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

bool is_number(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) { 
    if (argc != 2) { 
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE); 
    }
    
    if (inet_addr(argv[1]) == -1) {
        printf("Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    char response[1024];

    for (int i = 1; i < 65535; i++) {
        struct sockaddr_in dest;

        int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        dest.sin_family = AF_INET;
        dest.sin_port = htons(i);
        dest.sin_addr.s_addr = inet_addr(argv[1]);

        int ret = connect(sock, (struct sockaddr*) &dest, sizeof(dest));

        if (ret == 0) {
            printf("Port %d is open\n", i);
        }
        
        close(sock);
    }

    return 0;  
}