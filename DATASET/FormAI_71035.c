//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];

    int sockfd;
    struct sockaddr_in target_addr;

    memset(&target_addr, 0, sizeof(target_addr));

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip_address);
    target_addr.sin_port = htons(0);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        error("Could not connect");
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "nmap -T4 %s", ip_address);

    printf("\n\033[1mScanning %s...\033[0m\n", ip_address);

    FILE *output_file = popen(buffer, "r");
    if (output_file == NULL) {
        error("Error opening output file");
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), output_file)) {
        printf("%s", line);
        fflush(stdout);
    }

    pclose(output_file);
    close(sockfd);

    return 0;
}