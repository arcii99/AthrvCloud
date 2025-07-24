//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *website = argv[1];
    struct hostent *host;
    int status;

    while (1) {
        printf("Checking status of website: %s\n", website);

        host = gethostbyname(website);

        if (host == NULL) {
            printf("Error: Invalid website\n");
            exit(1);
        }

        status = system("ping -c 1 google.com > /dev/null");

        if (status == 0) {
            printf("Website is UP!\n");
        } else {
            printf("Website is DOWN!\n");
        }

        sleep(60);
    }

    return 0;
}