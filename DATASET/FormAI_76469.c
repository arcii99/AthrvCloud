//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 100
#define BUFFER_SIZE 1024

int dnslookup(char *addr, char *hostname, int len) {
    struct sockaddr_in sa;
    size_t salen = sizeof(sa);
    char hbuf[MAX_HOSTNAME_LEN], sbuf[INET_ADDRSTRLEN];
    memset(hbuf, 0, sizeof(hbuf));
    memset(&sa, 0, salen);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(addr);
    if (getnameinfo((struct sockaddr *) &sa, salen, hbuf, sizeof(hbuf), NULL, 0, NI_NAMEREQD)) 
        return -1;
    strncpy(hostname, hbuf, len);
    return 0;
}

int main(int argc, char *argv[]) {
    // Initialize variables
    int sd, rc;
    char hostname[MAX_HOSTNAME_LEN];
    char buffer[BUFFER_SIZE] = "";
    char *ipaddress = "127.0.0.1";
    struct sockaddr_in pin;

    // Create socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Set address structure
    memset(&pin, 0, sizeof(pin));
    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = inet_addr(ipaddress);
    pin.sin_port = htons(0);

    // Bind socket to address structure
    if (bind(sd, (struct sockaddr *) &pin, sizeof(pin)) < 0) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    // Connect to wireless network
    printf("Scanning for wireless networks...\n");
    if (system("sudo iwlist scan > output.txt") == -1) {
        perror("system() error");
        exit(EXIT_FAILURE);
    }

    // Scan output.txt for wireless networks
    FILE *fp;
    char line[BUFFER_SIZE];
    char *ssid;
    char *encryption;
    bool is_encrypted;
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "ESSID:\"")) {
            ssid = strtok(line, "\"");
            ssid = strtok(NULL, "\"");
            if (dnslookup(ipaddress, hostname, MAX_HOSTNAME_LEN) < 0) {
                printf("%s - ESSID: %s\n", ipaddress, ssid);
            } else {
                printf("%s (%s) - ESSID: %s\n", ipaddress, hostname, ssid);
            }
        } else if (strstr(line, "IE: WPA2") || strstr(line, "IE: IEEE802.11i")) {
            encryption = strtok(line, "-");
            encryption = strtok(NULL, "-");
            encryption = strtok(encryption, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            encryption = strtok(NULL, ":");
            if (isspace(*encryption))
                encryption++;
            encryption[strlen(encryption)-2] = '\0';
            is_encrypted = true;
            printf("- Encryption: %s\n", encryption);
        } else if (strstr(line, "Encryption key:off")) {
            printf("- Encryption: None\n");
            is_encrypted = false;
        }
        memset(line, 0, sizeof(line));
    }
    fclose(fp);

    // Close socket
    close(sd);

    return 0;
}