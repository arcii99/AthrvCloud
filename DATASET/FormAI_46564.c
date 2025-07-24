//FormAI DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>

int main() {
    printf("Welcome to the Firewall of the Castle of Yore!\n");
    printf("Please enter your username: ");

    char username[20];
    scanf("%s", username);

    printf("Welcome, Server Administrator %s!\n", username);
    printf("The Firewall is running and operational. Please enter the IP address of the server you wish to add to the whitelist: ");

    char ip_address[16];
    scanf("%s", ip_address);

    int is_whitelisted = 0;
    char confirmed;
    printf("Do you confirm the addition of %s to the whitelist? [y/n]: ", ip_address);
    scanf(" %c", &confirmed);

    if (confirmed == 'y' || confirmed == 'Y') {
        printf("%s has been added to the whitelist!\n", ip_address);
        is_whitelisted = 1;
    } else {
        printf("Addition of %s to the whitelist has been cancelled.\n", ip_address);
    }

    printf("The Firewall is now monitoring network traffic. Press 'q' to quit or 's' to see current whitelist.\n");

    while (1) {
        char option = getchar();
        if (option == 'q' || option == 'Q') {
            printf("Stopping the Firewall. Goodbye!\n");
            break;
        } else if (option == 's' || option == 'S') {
            if (is_whitelisted) {
                printf("The following IPs are currently whitelisted:\n");
                printf("%s\n", ip_address);
            } else {
                printf("There are currently no IPs whitelisted.\n");
            }
        }
    }

    return 0;
}