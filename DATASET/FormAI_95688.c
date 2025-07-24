//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_TOKENS 100
#define MAX_HOSTS 100
#define MAX_IP_ADDR 16
#define MAX_HOSTNAME 256

int main(int argc, char **argv) {
    char command[1024];
    int token_count = 0;
    char *tokens[MAX_TOKENS];
    char *hosts[MAX_HOSTS];
    char ip_addr[MAX_IP_ADDR], hostname[MAX_HOSTNAME];
    struct hostent *he;
    struct sockaddr_in sin;
    int sockfd;

    // Clear out hosts array
    for (int i = 0; i < MAX_HOSTS; i++) {
        hosts[i] = NULL;
    }

    // Loop forever, until user terminates program
    while (1) {
        printf("Enter command: ");
        fgets(command, 1024, stdin);

        // Tokenize input command
        char *token = strtok(command, " \n");
        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " \n");
        }

        // If the first token is "quit", exit the loop and terminate program
        if (strcmp(tokens[0], "quit") == 0) {
            break;
        }

        // If the first token is "addhost", add the specified hostname to the hosts array
        if (strcmp(tokens[0], "addhost") == 0) {
            if (token_count != 2) {
                printf("Usage: addhost <hostname>\n");
            } else {
                // Get IP address of host and add it to hosts array
                he = gethostbyname(tokens[1]);
                if (he == NULL) {
                    printf("Could not resolve hostname %s\n", tokens[1]);
                } else {
                    inet_ntop(AF_INET, he->h_addr_list[0], ip_addr, MAX_IP_ADDR);
                    hosts[token_count - 2] = strdup(tokens[1]);
                    printf("Added host %s (%s) to list\n", tokens[1], ip_addr);
                }
            }
        }

        // If the first token is "map", display a mapping of hosts
        if (strcmp(tokens[0], "map") == 0) {
            if (token_count != 1) {
                printf("Usage: map\n");
            } else {
                printf("Mapping hosts...\n");

                for (int i = 0; i < MAX_HOSTS && hosts[i] != NULL; i++) {
                    printf("%s: ", hosts[i]);

                    // Try to connect to host on port 80 to determine if it's a web server
                    sockfd = socket(AF_INET, SOCK_STREAM, 0);
                    sin.sin_family = AF_INET;
                    sin.sin_port = htons(80);
                    inet_pton(AF_INET, ip_addr, &sin.sin_addr);

                    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
                        printf("Web server\n");
                    } else {
                        printf("Unknown\n");
                    }

                    close(sockfd);
                }
            }
        }

        // Reset token count and tokens array for next iteration
        token_count = 0;
        memset(tokens, 0, sizeof(tokens));
    }

    // Free any allocated memory
    for (int i = 0; i < MAX_HOSTS && hosts[i] != NULL; i++) {
        free(hosts[i]);
    }

    return 0;
}