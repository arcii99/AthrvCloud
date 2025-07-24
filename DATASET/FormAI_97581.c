//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_ADDR_LEN 32
#define MAX_HOST_LEN 256

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [ip address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    char addr_str[MAX_ADDR_LEN];
    strncpy(addr_str, argv[1], MAX_ADDR_LEN);

    if (inet_pton(AF_INET, addr_str, &(addr.sin_addr)) == 1) {
        printf("IP Address: %s\n", addr_str);

        char hostname[MAX_HOST_LEN];
        struct hostent *he = gethostbyaddr(&(addr.sin_addr), sizeof(addr.sin_addr), AF_INET);
        
        if (he == NULL) {
            fprintf(stderr, "Error getting host by address: %s\n", hstrerror(h_errno));
            exit(EXIT_FAILURE);
        }
      
        strncpy(hostname, he->h_name, MAX_HOST_LEN);
        printf("Hostname: %s\n", hostname);

    } else {
        printf("Invalid IP Address\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}