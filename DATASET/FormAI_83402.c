//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MIN_PORT 0 // Minimum port number
#define MAX_PORT 65535 // Maximum port number

void board() {
    // ASCII art of a chess board
    printf("    A   B   C   D   E   F   G   H\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 1; i <= 8; i++) {
        printf("%d |", i);
        for (int j = 1; j <= 8; j++) {
            printf("   |");
        }
        printf(" %d\n", i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H\n");
}

bool is_valid_input(char* input) {
    // Validates user input, must be in the format of host:port or IPv4:port
    char* token;
    int i = 0;
    token = strtok(input, ":");
    while (token != NULL) {
        if (i == 0 && inet_addr(token) == INADDR_NONE) {
            printf("Invalid input, please enter a valid IPv4 address or hostname.\n");
            return false;
        }
        if (i == 1 && atoi(token) < MIN_PORT || atoi(token) > MAX_PORT) {
            printf("Invalid input, please enter a valid port number between %d and %d.\n", MIN_PORT, MAX_PORT);
            return false;
        }
        token = strtok(NULL, ":");
        i++;
    }
    if (i != 2) {
        printf("Invalid input, please enter input in the format of host:port or IPv4:port.\n");
        return false;
    }
    return true;
}

void scan_port(char* target, int port) {
    // Attempt to create socket and connect to specified port for target
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;        
    target_addr.sin_addr.s_addr = inet_addr(target);  
    target_addr.sin_port = htons(port);      

    // Attempt to connect to target port
    int conn_status = connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if (conn_status >= 0) {
        printf("[*] %s:%d OPEN\n", target, port);
    }
    close(sock);
}

int main() {
    char* input = (char*) malloc(100*sizeof(char));
    bool valid_input = false;

    // Display ASCII art of chess board before prompting user for input
    board();

    // Prompt user for input until valid input is entered
    while (!valid_input) {
        printf("Please enter target in the format of host:port or IPv4:port: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline character
        valid_input = is_valid_input(input);
    }

    // Extract target and port number from input string
    char* target;
    int port;
    target = strtok(input, ":");
    port = atoi(strtok(NULL, ":"));

    // Scan all ports in range (MIN_PORT, MAX_PORT) for target
    for (int i = MIN_PORT; i <= MAX_PORT; i++) {
        scan_port(target, i);
    } 

    return 0;
}