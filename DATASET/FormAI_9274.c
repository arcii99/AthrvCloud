//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char hostname[1024];
    int result = gethostname(hostname, 1024);
    if(result != 0) {
        perror("Could not get hostname");
        exit(EXIT_FAILURE);
    }
    printf("Hostname: %s\n", hostname);

    result = chdir("/");
    if(result != 0) {
        perror("Could not change directory");
        exit(EXIT_FAILURE);
    }

    result = setuid(0);
    if(result != 0) {
        perror("Could not set UID to 0");
        exit(EXIT_FAILURE);
    }

    result = setgid(0);
    if(result != 0) {
        perror("Could not set GID to 0");
        exit(EXIT_FAILURE);
    }

    printf("Successfully became superuser!\n");

    // Do some system administration tasks here...

    return 0;
}