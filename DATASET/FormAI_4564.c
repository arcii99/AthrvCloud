//FormAI DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int opt;
    char *user = NULL;
    char *password = NULL;
    int port = 22;

    while ((opt = getopt(argc, argv, "u:p:P:")) != -1) {
        switch (opt) {
            case 'u':
                user = optarg;
                break;
            case 'p':
                password = optarg;
                break;
            case 'P':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-u user] [-p password] [-P port]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (user != NULL && password != NULL) {
        printf("Connecting to server with user %s and password %s on port %d...\n", user, password, port);
        // Connect to server and execute commands with specified user, password, and port
    } else {
        fprintf(stderr, "Error: both user and password must be provided.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}